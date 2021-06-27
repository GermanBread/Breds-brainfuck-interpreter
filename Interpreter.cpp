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
 */

#include <vector>
#include <climits>
#include <iostream>
#include "Global.hpp"

void interpret(const char* input, const size_t string_size) {
    std::vector<ulong> loop_starts;
    cells = std::vector<int64_t>(1);

    address = 0;
    ulong address_offset = 0;
    long loop_nest_level = -1;

    for (size_t i = 0; i < string_size; i++) {
        char instruction = input[i];

        const long old_address = address; 
        long cell_value = cells[old_address + address_offset];
        
        /*std::cout << "Address " << address << " with offset " << address_offset << std::endl;
        std::cout << "Address " << address << " has value " << cell_value << std::endl;
        std::cout << "Cell count " << cells.size() << std::endl;*/

        switch (instruction) {
            case '>':
                address++;
                if (address + address_offset > cells.size()) {
                    cells.push_back(0);
                }
                break;
            case '<':
                if (address > 0)
                    address--;
                else {
                    address_offset++;
                    cells.insert(cells.begin(), 0);
                }
                break;
            case '+':
                cell_value++;
                break;
            case '-':
                cell_value--;
                break;
            case '.':
                std::cout << static_cast<char>(cell_value);
                break;
            case ',':
                cell_value = getchar();
                break;
            case '[':
                if (cell_value == 0) {
                    size_t pos = 0;
                    long local_nest_level = loop_nest_level;
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
                else if (cell_value == 0) {
                    loop_starts.erase(loop_starts.end() - 1);
                    loop_nest_level--;
                    break;
                }
                i = loop_starts[loop_nest_level];
                break;
            case '?':
                std::cout << std::endl <<
                 ANSI_COL_CYAN << ANSI_MKUNDERLINE("Breakpoint") << " '?' hit."
                 << std::endl << ANSI_MKUNDERLINE("Address " << address)
                 << ", " << ANSI_MKUNDERLINE("offset " << address_offset)
                 << ", " << ANSI_MKUNDERLINE("iterator " << i) <<
                std::endl;

                printCells();
                
                std::cout << ANSI_RESET;
                break;
            default:
                break;
        }

        cells[old_address + address_offset] = cell_value;
    }
}
