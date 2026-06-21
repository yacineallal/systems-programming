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

int _printf(const char *format, ...) {
    char print_buf[1024];
    int n;
    char *str = NULL;   
    const char *s = NULL;

    va_list args; // hold arguments;
    va_start(args, format); // Initalize arguments list 

    for (str = print_buf; *format; format++) {
        if (*format != '%') { // if the character is not '%' move to next character
            *str++ = *format;
            // printed++;

            if(check_size(str, print_buf)) {
                print_buffer(print_buf, str); 
                str = print_buf; // reset buffer pointer
            }

            continue;
        }

        ++ format; // if there is '%', move to the next character

        switch(*format) {
            case 'c': 
                *str++ = va_arg(args, int); // take next character as integer
                // printed++;
                if (check_size(str, print_buf)) {
                    print_buffer(print_buf, str); 
                    str = print_buf; // reset buffer pointer
                }
                continue;
        }
    }

}

int main(int argc, char* argv[]) {
    
}