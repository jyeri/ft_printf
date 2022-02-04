#include "new.h"

void	init_flags (t_flags *flags)
{
	flags->plus = 0;
	flags->minus = 0;
	flags->width = 0;
	flags->precision = 0;
	flags->sp = 0;
	flags->hash = 0;
	flags->zero = 0;
	flags->dot = 0;
}

char *ft_check_type(char *s, t_flags *flags)
{
	while (!ft_strchr("cspdiouxX%", *s))
	{
		ft_check_flags(*s++, flags);
	}
	if (*s == 'd' || *s == 'i')
		print_int(flags);
	if (*s == 's')
		print_string(flags);
	if (*s == 'c')
		print_char(flags);
	if (*s == 'p')
		print_pointer(flags);
	if (*s == 'o')
		print_octal(flags);
	if (*s == 'u')
		print_unsigned(*s, flags, 10);
	if (*s == 'x' || *s == 'X')
		print_unsigned(*s, flags, 16);
	if (*s == 'f')
		print_float(*s, flags);
	return (++s);
}

void	ft_check_flags(char s, t_flags *flags)
{
	if (ft_isdigit(s))
	{
		if (flags->dot || flags->zero)
			flags->precision = flags->precision * 10 + s - '0';
		else
		{
			if (!flags->width && s == '0')
				flags->zero = 1;
			flags->width = flags->width * 10 + s - '0';
		}
	}
	if (s == '+')
		flags->plus = 1;
	if (s == '-')
		flags->minus = 1;
	if (s == ' ')
		flags->sp = 1;
	if (s == '#')
		flags->hash = 1;
	if (s == '.')
		flags->dot = 1;
}

int	ft_printf(const char *s, ...)
{
	int	ret;
	t_flags flags;

	init_flags(&flags);
	ret = 0;
	va_start(flags.args, s);
	while (*s)
	{
		if (*s == '%' && *s++)
		{
			s = ft_check_type((char *)s, &flags);
			init_flags(&flags);
		}
		else if (++ret)
		{
			ft_putchar(*s++);
		}
	}
	va_end(flags.args);
	return (ret);
}
