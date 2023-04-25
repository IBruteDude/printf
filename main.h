#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>

#define max(a, b) (((a) >= (b)) ? (a) : (b))
#define min(a, b) (((a) <= (b)) ? (a) : (b))
#define isdigit(x) ('0' <= (x) && (x) <= '9')
#define VALID_ALLOC(a) if(!(a))exit(EXIT_FAILURE)
#define BUFF_SIZE 1024

size_t strlen (const char *str);
char *strcpy(char *dest, const char *src);
char *strchr(const char *str, int c);
int chrpos(const char *str, char c, int start);

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

char *interpret_spec(char *fmt_spec, char *out_string);


int check_optional_fields(strQ *buffer);
char *get_valid_specifier(strQ *fmt_buf, char *found_spec_ptr);
size_t print_formatted_token(const char *format, strQ *buffer, size_t i, va_list va);
int get_fmt_spec(strQ *buffer, strQ *fmt_buffer);
int _printf(const char *format, ...);
#endif
