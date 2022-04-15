OUTPUT := BrainfuckInterpreter
GCC := g++ -Wall -O3 -o $(OUTPUT)

all:
	$(GCC) Main.cpp
	strip $(OUTPUT)

static:
	$(GCC) -static Main.cpp
	strip $(OUTPUT)

test: all
	./$(OUTPUT) --run "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++." --verbose
