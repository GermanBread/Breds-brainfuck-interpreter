#ifndef ANSI
#define ANSI

#define ANSI_COL_CYAN "\u001B[36m"
#define ANSI_UNDERLINE "\u001B[4m"
#define ANSI_STOP_UNDERLINE "\u001B[24m"
#define ANSI_RESET "\u001B(B\u001B[m"
#define ANSI_MKUNDERLINE(string) ANSI_UNDERLINE << string << ANSI_STOP_UNDERLINE

#endif