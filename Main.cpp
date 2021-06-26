// Made by GermanBread#9077 (Discord)
#include <iostream>

#include "ANSI.hpp"
#include "Cells.cpp"
#include "Global.hpp"
#include "Interpreter.cpp"

int main(int argc, const char** argv) {
    if (argc < 2) {
        std::cerr << "Please provide a brainfuck programme as the parameter" << std::endl;
        return 1;
    }
    const char* code = argv[1];
    size_t length = std::string(code).length();
    interpret(code, length);
    std::cout << std::endl
     << "Interpretation " << ANSI_MKUNDERLINE("completed") << ", the programme exited with "
     << ANSI_MKUNDERLINE("address " << address)
     << " and " ANSI_MKUNDERLINE(cells.size() + 1 << " cell(s).") <<
    std::endl;
    printCells();
}
