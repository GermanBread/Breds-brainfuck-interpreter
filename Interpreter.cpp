/*
 *      Made by GermanBread#9077 (Discord)
 *
 *  > 	Move the pointer to the right
 *  < 	Move the pointer to the left
 *  + 	Increment the cells cell at the pointer
 *  - 	Decrement the cells cell at the pointer
 *  . 	Output the character signified by the cell at the pointer
 *  , 	Input a character and store it in the cell at the pointer
 *  [ 	Jump past the matching ] if the cell at the pointer is 0
 *  ] 	Jump back to the matching [ if the cell at the pointer is nonzero
 * 
 *  EXTENSIONS:
 *  _   Swap the contents of the cell with the contents of a reusable variable
 *  !   Jump to address 0
 *  #   Undo last ! (or #)
 *  ?   Print the contents of memory including the current address
 */

#include <deque>
#include <climits>
#include <iostream>

#include "ANSI.hpp"
#include "Cells.hpp"
#include "Global.hpp"

void interpret(const char* input, const size_t string_size) {
    std::vector<uint64_t> loop_starts;
    cells = std::deque<int64_t>(1);
    int64_t swap = 0;
    int64_t addrswp = 0;

    address = 0;
    int64_t prev_addr = 0;
    int64_t loop_nest_level = -1;

    for (size_t i = 0; i < string_size; i++) {
        char instruction = input[i];

        switch (instruction) {
            case '>':
                address++;
                // >= because the size is the last index + 1
                if (address >= cells.size()) {
                    cells.push_back(0);
                }
                break;
            case '<':
                if (address > 0)
                    address--;
                else {
                    cells.push_front(0);
                }
                break;
            case '+':
                cells[address]++;
                break;
            case '-':
                cells[address]--;
                break;
            case '.':
                std::cout << static_cast<char>(cells[address]);
                break;
            case ',':
                cells[address] = getchar();
                break;
            case '[':
                if (cells[address] == 0) {
                    size_t pos = 0;
                    int64_t local_nest_level = loop_nest_level;
                    for (size_t e = 0; e < string_size; e++) {
                        if (input[e] == ']' && loop_nest_level == local_nest_level) {
                            pos = e;
                            break;
                        }
                    }
                    i = pos;
                    break;
                }
                loop_starts.push_back(i);
                loop_nest_level++;
                break;
            case ']':
                if (loop_starts.size() == 0)
                    return;
                else if (cells[address] == 0) {
                    loop_starts.erase(loop_starts.end() - 1);
                    loop_nest_level--;
                    break;
                }
                i = loop_starts[loop_nest_level];
                break;
            // Extensions start here
            case '_':
                if (noext) break;
                std::swap(swap, cells[address]);
                break;
            case '!':
                if (noext) break;
                prev_addr = address;
                address = 0;
                break;
            case '#':
                if (noext) break;
                addrswp = address;
                address = prev_addr;
                prev_addr = addrswp;
                break;
            case '?':
                if (noext) break;
                
                std::cout << std::endl <<
                 ANSI_COL_CYAN << ANSI_MKUNDERLINE("Breakpoint") << " '?' hit."
                 << std::endl << ANSI_MKUNDERLINE("Address " << address)
                 << ", " << ANSI_MKUNDERLINE("iterator " << i)
                 << ", " << ANSI_MKUNDERLINE("swap " << swap)
                 << std::endl;

                printCells();
                
                std::cout << ANSI_RESET;
                break;
            default:
                break;
        }

        // compat
        if (legacy) {
            // Constrain to 8-bit
            // Not sure if % would behave like i want it tom hence the if/else
            if (cells[address] > 128) cells[address] = -127;
            else if (cells[address] < -127) cells[address] = 128;

            // Constrain to 30.000 cells
            if (cells.size() > 30000) {
                if (address == 0) {
                    cells.pop_front();
                    address = 30000;
                } else {
                    cells.pop_back();
                    address = 0;
                }
            }
        }

        // GC
        if (!nogc) {
            while (cells.back() == 0 && address < (cells.size() - 1))
                cells.pop_back();
            while (cells.front() == 0 && address > 0) {
                cells.pop_front();
                address--;
            }
        }
    }
}
