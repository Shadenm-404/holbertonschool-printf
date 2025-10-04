#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/* core api */
int _printf(const char *format, ...);
int _putchar(char c);

/* helpers in conv.c */
int print_string(char *s);
int print_number(int n);
int print_unsigned(unsigned int n);
int print_octal(unsigned int n, int alt_prefix);
int print_hex(unsigned long n, int uppercase, int alt_prefix);
int print_binary(unsigned int n);
int print_pointer(void *ptr);

#endif /* MAIN_H */
