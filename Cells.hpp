#include <math.h>
#include <vector>
#include <climits>
#include <iostream>

#include "Global.hpp"

#ifndef CELLS
#define CELLS

size_t getStringLen(int64_t value) {
    return std::max<double>(ceil(log10(abs(value) + 1)), 1) + (value < 0 ? 1 : 0);
}

void printCells() {
    size_t cell_count = cells.size();
    std::cout << "┌";
    for (size_t i = 0; i < cell_count; i++) {
        if (i > 0)
            std::cout << "┬";
        
        size_t _offset = getStringLen(i);
        size_t _len = getStringLen(cells[i]);
        
        // Try to fit the cell number
        if (_offset <= _len)
            std::cout << i;
        else
            std::cout << std::to_string(i).substr(std::max<size_t>(_offset - _len, 0), _offset - _len);
        
        for (size_t a = _offset; a < _len; a++)
            std::cout << "─";
    }
    std::cout << "╮" << std::endl;

    std::cout << "│";
    for (size_t i = 0; i < cell_count; i++) {
        if (i > 0)
            std::cout << "┆";
        std::cout << cells[i];
    }
    std::cout << "│" << std::endl;

    std::cout << "╰";
    for (size_t i = 0; i < cell_count; i++) {
        if (i > 0)
            std::cout << "┴";
        for (size_t a = 0; a < getStringLen(cells[i]); a++)
            std::cout << "─";
    }
    std::cout << "┘" << std::endl;
}

#endif