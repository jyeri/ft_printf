#include "libft/libft.h"
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


int print_float(t_flags *flags);

//main functions
void	init_flags (t_flags *flags);
int		ft_printf(const char *s, ...);
void	ft_check_flags(char s, t_flags *flags);
char	*ft_check_type(char *s, t_flags *flags);

//printing functions
void print_pox(t_flags *flags);
void print_width_2(t_flags *flags, int len);
int print_diu(t_flags *flags);
void print_int(t_flags *flags, int len, int sign, int n);
void print_width(t_flags *flags, int len, char sign, int n);
void print_prec(t_flags *flags, int prec);
void print_sign(t_flags *flags, char sign);
int print_c(t_flags *flags);
int print_s(t_flags *flags);
int print_address(unsigned long long i, int base);
void print_actual_string(char *str, t_flags *flags);

//helper functions
void print_nbr_base(long long n, int base, t_flags *flags);
void ft_putnbr_us(unsigned int n, int base);
void ft_putnstr(char *str, int len);
int int_len(int i);
char *ft_itoa_base(t_flags *flags, int n, unsigned int base);
int count_digits(int n, unsigned int base);