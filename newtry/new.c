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
	flags->type = *s;
	if (flags->type == 'd' || flags->type == 'i')
		print_di(flags);
	else if (flags->type == 's')
		print_s(flags);
	else if (flags->type == 'c')
		print_c(flags);
	else if (flags->type == 'p')
		print_pointer(flags);
	else if (flags->type == 'o')
		print_octal(flags);
	else if (flags->type == 'u')
		print_unsigned(*s, flags, 10);
	else if (flags->type == 'x' || flags->type == 'X')
		print_unsigned(*s, flags, 16);
	else if (flags->type == 'f')
		print_float(flags);
	else
	{
		ft_putstr("error!");
	}
	return (++s);
}

void ft_lengthspec(char s, t_flags *flags)
{
	if (s == 'h')
	{
		if (flags->h)
		{
			flags->h = 0;
			flags->hh = 1;
		}
		flags->h = 1;
	}
	if (s == 'l')
	{
		if (flags->l)
		{
			flags->l = 0;
			flags->ll = 1;
		}
		flags->l = 1;
	}
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
	else if (s == '+')
		flags->plus = 1;
	else if (s == '-')
		flags->minus = 1;
	else if (s == ' ')
		flags->sp = 1;
	else if (s == '#')
		flags->hash = 1;
	else if (s == '.')
		flags->dot = 1;
	else if (s == 'l' || s == 'h')
		ft_lengthspec(s, flags);
	else if (s == 'L')
		flags->bigL = 1;
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
