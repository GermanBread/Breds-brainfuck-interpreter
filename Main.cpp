// Made by GermanBread#9077 (Discord)

#include <iostream>
#include "Interpreter.cpp"
#include "Cells.cpp"
#include "Global.hpp"

int main(int argc, const char** argv) {
        if (argc < 2) {
        std::cerr << "Please provide a brainfuck programme as the parameter" << std::endl;
        return 1;
    }
    const char* code = argv[1];
    size_t length = std::string(code).length();
    interpret(code, length);
    std::cout << std::endl << std::endl << "Interpretation completed, the programme exited with address " << address << " and " << cells.size() + 1 << " cell(s)." << std::endl;
    printCells();
}
