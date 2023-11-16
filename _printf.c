#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format != '\0') {
        if (*format == '%' && *(format + 1) != '\0') {
            switch (*(format + 1)) {
                case 'c':
                    putchar(va_arg(args, int));
                    count++;
                    break;
                case 's':
                    {
                        const char *str = va_arg(args, const char*);
                        while (*str != '\0') {
                            putchar(*str);
                            str++;
                            count++;
                        }
                    }
                    break;
                case '%':
                    putchar('%');
                    count++;
                    break;
                default:
                    putchar(*format);
                    count++;
                    break;
            }
            format += 2;
        } else {
            putchar(*format);
            count++;
            format++;
        }
    }

    va_end(args);

    return count;
}
int main() {
    _printf("This is a test: %c\n, %s\n, %%\n", 'A', "Hello, Pat");
    return 0;
}
