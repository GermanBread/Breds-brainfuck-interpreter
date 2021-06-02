OUTPUT := BrainfuckInterpreter
GCC := g++ -Wall -O3 -o $(OUTPUT)

all:
	$(GCC) Main.cpp

static:
	$(GCC) -static Main.cpp

run: all
	./$(OUTPUT) "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++."
