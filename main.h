#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <math.h>

#define max(a, b) (((a) >= (b)) ? (a) : (b))
#define min(a, b) (((a) <= (b)) ? (a) : (b))
#define isdigit(x) ('0' <= (x) && (x) <= '9')
#define base(n, b) (((n) < 10) ? ('0' + (n)) : ('A' + (n) % 10))
#define abs(a) (((a) >= 0) ? (a) : -(a))

#define bool unsigned char
#define true 1
#define false 0

#define VALID_ALLOC(a) if ((void *)(a)==NULL) (exit(EXIT_FAILURE));
#define UV __attribute__((unused))

size_t strlen(const char *str);
char *strcpy(char *dest, const char *src);
char *strdup(const char *s);
char *strchr(const char *str, int c);
int chrpos(const char *str, char c, int start);
void strip(char *str);

/**
 * struct constant_string_indexing_buffer - string buffer
 * @store: the address to be freed
 * @front: the address of the next stored value
 * @back: the address of the last stored value
 */
typedef struct constant_string_indexing_buffer /* we will call it a queue */
{
	char *store, *front, *back;
} strQ;

strQ *strQ_init(const char *str);
char strQ_pop(strQ *s);
void strQ_free(strQ *s);

char *interpret_spec(char *fmt_spec, strQ *out_string);
char *int_to_str(uint64_t num, size_t radix, strQ *custom);
char *double_to_str(double num, strQ *custom);
char *str_tolower(char *str);

int print_formatted_int(strQ *fmt_buffer, va_list *va);
int print_formatted_double(strQ *fmt_buffer, va_list *va);
int print_formatted_string(strQ *fmt_buffer, va_list *va);
int print_formatted_char(strQ *fmt_buffer, va_list *va);

int check_optional_fields(strQ *buffer, char *fail_flag);
int get_fmt_spec(strQ *buffer, strQ *fmt_buffer);
int process_conversion_spec(const char *format, va_list *va, strQ *buffer,
							size_t *w_bytes, size_t i);
void print_buffer(const char *format, strQ *tb,
					 size_t *r_bytes, size_t *w_bytes);
int _printf(const char *format, ...);
#endif
