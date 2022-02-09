#include "new.h"

void ft_putnstr(char *str, int len)
{
	write (1, str, len);
}

int print_s(t_flags *flags)
{
	char *str;
	int len;
	int return_value;

	str = va_arg(flags->args, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (!flags->dot || flags->precision > len)
		flags->precision = len;
	if (flags->width > flags->precision)
		flags->offset = flags->width - flags->precision;
	return_value = flags->offset + flags->precision;
	if (flags->minus)
	{
		ft_putstr(str);
		while (flags->offset-- > 0)
			ft_putchar(' ');
	}
	else
	{
		while (flags->offset-- > 0)
			ft_putchar(' ');
		ft_putnstr(str, flags->precision);
	}
	return (return_value);
}

int print_c(t_flags *flags)
{
	char c;
	
	c = (char)va_arg(flags->args, int);

	return (1);
}