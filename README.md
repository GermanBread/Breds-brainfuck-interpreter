# A better brainfuck interpreter

(still not completely bug-free lol)
Note to self: I might've shot myself in the foot by operating completely on the stack. (But the stack is fast)

## Features

* 64-bit address-space
* 64-bit signed values in cells
* Garbage Collection
* Useful extensions, see [this file](Interpreter.cpp)
* Backwards compatibility [according to Wikipedia](https://en.wikipedia.org/wiki/Brainfuck#Cell_size)

## Compiling

`make`

then

`./BrainfuckInterpreter --help`