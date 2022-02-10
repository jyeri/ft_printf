#include "../libft/libft.h"
#include <stdarg.h>
#include <stdlib.h> 

typedef struct s_flags
{
	int width; //width
	int precision; //precision
	int	zero; //flag 0
	int plus; //flag +
	int minus; //flag -
	int hash; //flag #
	int sp; //flag space (' ')
	int dot; //flag dot
	int type; //store the type
	int base;
	int l; //long
	int ll; //long long
	int h; // short int
	int hh; //short
	int offset; // width is bigger than precision
	int bigones; // big hexa with X
	int bigL; // big L flag
	int printlen; // total length of print?
	va_list args;

} t_flags;

void init_flags (t_flags *flags);
int	ft_printf(const char *s, ...);
void	ft_check_flags(char s, t_flags *flags);
char *ft_check_type(char *s, t_flags *flags);
int print_diu(t_flags *flags);
int print_c(t_flags *flags);
int print_s(t_flags *flags);
int print_string(t_flags *flags);
int print_address(unsigned long long i, int base);
int print_pointer(t_flags *flags);
int print_octal(t_flags *flags);
int print_unsigned(char c, t_flags *flags, int base);
int print_float(t_flags *flags);
void print_nbr_base(long long n, int base, t_flags *flags);
void ft_putnbr_us(unsigned int n, int base);
void print_pox(t_flags *flags);
void print_actual_string(char *str, t_flags *flags);