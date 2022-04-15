// Made by GermanBread#9077 (Discord)
#include <iostream>
#include <string.h>

#include "ANSI.hpp"
#include "Cells.hpp"
#include "Global.hpp"
#include "Interpreter.cpp"

int main(int argc, const char** argv) {
    const char* code = nullptr;
    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "--run") == 0) {
            if (i + 1 < argc) code = argv[i + 1];
        } else if (strcmp(argv[i], "--help") == 0) {
            std::cerr << "Bred's Brainfuck Interpreter" << std::endl
             
             << std::endl << ANSI_MKUNDERLINE("USAGE:") << std::endl
             << "--help    : this menu" << std::endl
             << "--verbose : verbose output" << std::endl
             << "--run     : run program (the following parameter)" << std::endl
             
             << std::endl << ANSI_MKUNDERLINE("COMPATIBILITY:") << std::endl
             << "--no-gc   : disable garbage-collection" << std::endl
             << "--legacy  : restrict cell count to 30.000 and size to 8-bit values" << std::endl
             << "--no-ext  : disable extensions to Brainfuck" << std::endl;

            return 0;
        } else if (strcmp(argv[i], "--verbose") == 0) {
            verbose = true;
        } else if (strcmp(argv[i], "--no-ext") == 0) {
            noext = true;
        } else if (strcmp(argv[i], "--no-gc") == 0) {
            nogc = true;
        } else if (strcmp(argv[i], "--legacy") == 0) {
            legacy = true;
        }
    }
    if (code == nullptr) {
        std::cerr << "Run with --help" << std::endl;
        return 1;
    }

    interpret(std::string(code));

    if (!verbose) return 0;
    
    std::cout << std::endl
     << "Interpretation " << ANSI_MKUNDERLINE("completed") << ", the programme exited with "
     << ANSI_MKUNDERLINE("address " << address)
     << " and " ANSI_MKUNDERLINE(cells.size() + 1 << " cell(s).")
     << std::endl;
    printCells();

    return 0;
}
