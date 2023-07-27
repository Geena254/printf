#ifndef _MAIN_H
#define _MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_HASH 8
#define F_PLUS 2
#define F_SPACE 16
#define F_ZERO 4
#define F_MINUS 1

/**
 * typedef struct fmt fmt_t - the struct op
 *
 * @frmt: The format.
 * @frm_t: The function associated.
 */
typedef struct frmt frmt_t;

/**
  * struct frmt - the struct op.
  * @frmt: The format.
  * @func: The function associated.
  */

struct frmt
{
	char frmt;
	int (*func)(va_list, char[], int, int, int, int);
};

/****************FOR PRINTF FUNC****************/
int _printf(const char *format, ...);

/****************** FUNCTIONS ******************/

/**** Funtions to print chars ****/
int print_char(va_list types, char buffer[],
	int flags, int wid, int precision, int size);

/**** Functions to print string ****/
int print_string(va_list types, char buffer[],
	int flags, int wid, int precision, int size);

/**** Functions to print percent sign ****/
int print_percent(va_list types, char buffer[],
	int flags, int wid, int precision, int size);

/**** Functions to print numbers ****/
int print_integer(va_list types, char buffer[],
	int flags, int wid, int precision, int size);
int print_binary(va_list types, char buffer[],
	int flags, int wid, int precision, int size);
int print_unsigned(va_list types, char buffer[],
	int flags, int wid, int precision, int size);
int print_octal(va_list types, char buffer[],
	int flags, int wid, int precision, int size);
int print_hexadeci(va_list types, char buffer[],
	int flags, int wid, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
	int flags, int wid, int precision, int size);

int print_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int wid, int precision, int size);

/**** Function to print non printable characters ****/
int print_non_printble(va_list types, char buffer[],
	int flags, int wid, int precision, int size);

/**** Funcion to print memory address *****/
int print_pter(va_list types, char buffer[],
	int flags, int wid, int precision, int size);

/**** Funciotns to handle other specifiers ****/
int print_flags(const char *format, int *j);
int print_width(const char *format, int *j, va_list lst);
int print_precision(const char *format, int *j, va_list lst);
int print_size(const char *format, int *j);

/**** Function to print string in reverse ****/
int print_reverse(va_list types, char buffer[],
	int flags, int wid, int precision, int size);

/**** Function to print a string in rot 13 ****/
int print_rot13str(va_list types, char buffer[],
	int flags, int wid, int precision, int size);

/**** Function for handle print file ****/
int handl_print(const char *frmt, int *i, va_list lst, char buffer[],
		int flags, int wid, int precision, int size);

/**** width handler ****/
int handl_writ_char(char a, char buffer[],
	int flags, int wid, int precision, int size);
int write_number(int is_pos, int ind, char buffer[],
	int flags, int wid, int precision, int size);
int write_num(int ind, char bff[], int flags, int wid, int precision,
	int length, char padd, char extra_c);
int write_pter(char buffer[], int ind, int leng,
	int wid, int flags, char padd, char extra_c, int padd_begin);

int write_unsgnd(int is_neg, int ind, char buffer[],
	int flags, int wid, int precision, int size);

/****************** UTILS ******************/
int is_printable(char);
int append_hexa_code(char asc_cod, char buffer[], int j);
int is_dig(char a);

long int conv_siz_num(long int num, int size);
long int conv_siz_unsignd(unsigned long int num, int size);

#endif /* MAIN_H */
