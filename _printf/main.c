#include <stdarg.h>
#include <stdio.h>

void print_buffer(char buffer[], char *str) {
    for (int i=0; i<str-buffer; i++) {
        putchar(buffer[i]);
    }
}

int check_size(char *str, char* print_buff) { // check buffer size
    if (str - print_buff >= 1024) {
        return str - print_buff;
    }
    return 0;
}

int main(int argc, char* argv[]) {
    
}