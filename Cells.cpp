#include <math.h>
#include <vector>
#include <climits>
#include <iostream>

#include "Global.hpp"

size_t getStringLen(int64_t value) {
    return std::max<double>(ceil(log10(abs(value) + 1)), 1) + (value < 0 ? 1 : 0);
}

void printCells() {
    size_t cell_count = cells.size() + 1;
    std::cout << "┌";
    for (size_t i = 0; i < cell_count; i++) {
        if (i > 0)
            std::cout << "┬";
        
        size_t _offset = getStringLen(i);
        size_t _len = getStringLen(cells[i]);
        
        // Check if the text fits
        if (_offset <= _len)
            std::cout << i;
        else
            _offset = 0;
        
        for (size_t a = _offset; a < _len; a++)
            std::cout << "─";
    }
    std::cout << "┐" << std::endl;

    for (size_t i = 0; i < cell_count; i++) {
        std::cout << "│";
        std::cout << cells[i];
    }
    std::cout << "│" << std::endl;

    std::cout << "└";
    for (size_t i = 0; i < cell_count; i++) {
        if (i > 0)
            std::cout << "┴";
        for (size_t a = 0; a < getStringLen(cells[i]); a++)
            std::cout << "─";
    }
    std::cout << "┘" << std::endl;
}
