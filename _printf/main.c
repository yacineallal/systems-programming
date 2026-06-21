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

char *itoa(int value, char* str, char* buff, int base) {
    char* ptr = str, *ptr1 = str, tmp_char;
    int tmp_value; 
    char tmpBuffer[32];
    char *pTmpBuffer = tmpBuffer;

    do
    {
        tmp_value = value; 
        value /= base; 
        *pTmpBuffer++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
    } while (value);
    
    // apply negative sign 
    if (tmp_value < 0) {
        *str++ = '-';
        if (base == 16) {
            if (str - buff > 1022) {
                print_buffer(buff, str);
                str = buff;
            }
            *str++ = '0';
            *str++ = 'x';
        }
    }
    *pTmpBuffer-- = '\0';

    while (pTmpBuffer >= tmpBuffer) {
        *str++ = *pTmpBuffer--;
        if (check_size(str, buff)) {
            print_buffer(buff, str);
            str = buff;
        }
    }

    return str;
}

// int _printf(const char *format, ...) {
//     char print_buff[1024];
//     int n;

// }

int main(int argc, char* argv[]) {
    
}