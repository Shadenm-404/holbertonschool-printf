#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/**
 * _putchar - writes a single character to stdout
 * @c: The character to print
 * Return: 1 on success, -1 on error
 */
int _putchar(char c);

/**
 * _printf - custom printf function
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...);

/* Helper functions */
int print_string(char *s);
int print_number(int n);
int print_unsigned(unsigned int n);
int print_octal(unsigned int n, int alt_prefix);
int print_hex(unsigned long n, int uppercase, int alt_prefix);
int print_binary(unsigned int n);
int print_pointer(void *ptr);

#endif /* MAIN_H */
