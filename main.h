#ifndef MAIN_H_
#define MAIN_H_

/***** Libraries *****/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

/***** Prototypes *****/
int _putchar(char c);
int _printf(const char *format, ...);
int f_mod(char mod, va_list list);
int print_char(char c);
int print_int(int i, int amt);
int print_str(char *s);


#endif /* MAIN_H_ */
