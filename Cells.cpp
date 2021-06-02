#include <vector>
#include <climits>
#include <iostream>
#include <math.h>
#include "Global.hpp"

void printCells() {
    size_t cell_count = cells.size();
    for (size_t i = 0; i < cell_count; i++) {
        std::cout << "+";
        for (size_t a = 0; a <= ceil(log10(cells[i] + 1)); a++)
            std::cout << "-";
    }
    std::cout << "+" << std::endl;

    for (size_t i = 0; i < cell_count; i++) {
        std::cout << "|";
        for (size_t a = 0; a <= ceil(log10(cells[i] + 1)); a++)
            std::cout << cells[i];
    }
    std::cout << "|" << std::endl;

    for (size_t i = 0; i < cell_count; i++) {
        std::cout << "+";
        for (size_t a = 0; a <= ceil(log10(cells[i] + 1)); a++)
            std::cout << "-";
    }
    std::cout << "+" << std::endl;
}
