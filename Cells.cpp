#include <vector>
#include <climits>
#include <iostream>
#include <math.h>
#include "Global.hpp"

size_t getStringLen(size_t value) {
    return std::max<double>(ceil(log10(value)), 1);
}

void printCells() {
    size_t cell_count = cells.size() + 1;
    for (size_t i = 0; i < cell_count; i++) {
        std::cout << "+";
        for (size_t a = 0; a < getStringLen(cells[i]); a++)
            std::cout << "-";
    }
    std::cout << "+" << std::endl;

    for (size_t i = 0; i < cell_count; i++) {
        std::cout << "|";
        std::cout << cells[i];
    }
    std::cout << "|" << std::endl;

    for (size_t i = 0; i < cell_count; i++) {
        std::cout << "+";
        for (size_t a = 0; a < getStringLen(cells[i]); a++)
            std::cout << "-";
    }
    std::cout << "+" << std::endl;
}
