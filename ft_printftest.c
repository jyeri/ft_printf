#include "ft_printf.h"

void	ft_printf(const char *s, ...)
{
	int	i;
	char *str;
	va_list	args;

	i = 0;
	va_start(args, s);
	while (s)
	{
		while (*s != '%')
		{
			ft_putchar(*s);
			s++;
		}
		if (*s == '%')
		{
			s++;
			if (*s == 'd' || *s == 'c' || *s == 'i')
			{
				i = va_arg(args, int);
				ft_putnbr(i);
				s++;
			}
			if (*s == 's')
			{
				str = va_arg(args, char *);
				ft_putstr(str);
				s++;
			}
		}
	s++;
	}
	va_end(args);
}
