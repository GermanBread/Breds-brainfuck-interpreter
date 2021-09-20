#ifndef GLOBAL
#define GLOBAL

#include <deque>

uint64_t address;
std::deque<int64_t> cells;

bool nogc = false;
bool noext = false;
bool legacy = false;
bool verbose = false;

#endif