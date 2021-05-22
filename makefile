OUTPUT := BrainfuckInterpreter
GCC := g++ -Wall -O3 -o $(OUTPUT)

all:
	$(GCC) Main.cpp

run: all
	./$(OUTPUT) "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++."
