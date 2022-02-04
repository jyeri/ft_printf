#include "new.h"

int print_char(t_flags *flags)
{
	char c;

	c = va_arg(flags->args, int);
	ft_putchar(c);

	return (1);
}
