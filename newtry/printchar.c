#include "new.h"

int int_len(int i)
{
	int holder;
	int len = 0;

	holder = i;
	while (holder > 0)
	{
		holder = holder / 10;
		len++;
	}
	return (len);
}

int print_int(t_flags *flags)
{
	int i;
	int len;

	i = va_arg(flags->args, int);
	len = i;

	if (flags->width || flags->precision)
	{
		if (flags->dot)
			flags->precision = flags->precision - int_len(len);
		flags->width = flags->width - int_len(len) - flags->precision;
		if (flags->minus)
		{
			while (flags->precision-- > 0)
				ft_putchar('0');
			ft_putnbr(i);
			while (flags->width-- > 0)
				ft_putchar(' ');	
		}
		else
		{
			while (flags->width-- > 0)
				ft_putchar(' ');
			if (flags->dot)
			{
				while (flags->precision-- > 0)
					ft_putchar('0');
			}
		}
	}
	if (!flags->minus)
		ft_putnbr(i);
	return (1);
}

int print_char(t_flags *flags)
{
	char c;

	c = va_arg(flags->args, int);
	ft_putchar(c);

	return (1);
}
