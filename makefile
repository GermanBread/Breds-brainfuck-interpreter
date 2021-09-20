OUTPUT := BrainfuckInterpreter
GCC := g++ -Wall -O3 -o $(OUTPUT)

all:
	$(GCC) Main.cpp

static:
	$(GCC) -static Main.cpp

test: all
	./$(OUTPUT) --run "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++." --verbose