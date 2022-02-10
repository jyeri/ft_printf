#include "new.h"

int count_digits(int n, unsigned int base)
{
	int count;

	count = 0;
	while (n)
	{
		count++;
		n = n / base;
	}
	return (count);
}

char *ft_itoa_base(t_flags *flags, int n, unsigned int base)
{
	char *str;
	char *tab;
	int counter;

	counter = count_digits(n, base);
	tab = "0123456789ABCDEF";
	if (flags->type == 'x')
		tab = "0123456789abcdef";
	if (n == 0)
		return ("0");
	str = (char *)malloc(sizeof(char) * counter + 1);
	if (!str)
		exit (-1);
	str[counter] = '\0';
	while (n)
	{
		str[counter - 1] = tab[n % base];
		counter--;
		n = n / base;
	}
	return (str);
}

//void ft_putnbr_base(unsigned int n, base)
//{
//	if (n / base < 1)
//		ft_putchar(n + '0');
//	else
//	{
//		ft_putnbr_us(n / base);
//		ft_putnbr_us(n % base);
//	}
//}
int print_address(unsigned long long i, int base)
{
	const char *values = "0123456789abcdef";
	if (i / base)
		print_address(i / base, base);
	ft_putchar(values[i % base]);
	return (i);
}

void print_width_2(t_flags *flags, int len)
{
	if (flags->width > len)
		{
			flags->width = flags->width - len;
			while (flags->width-- > 0)
					ft_putchar(' ');
		}
}

void print_pox(t_flags *flags)
{
	unsigned long long i;
	char *str;
	int len;

	str = NULL;
	len = 0;
	i = va_arg(flags->args, unsigned long long);
	if (flags->type == 'X' || flags->type == 'x')
	{
		if (flags->minus)
		{
			str = ft_itoa_base(flags, i, 16);
			len = ft_strlen(str);
			ft_putstr(str);
			print_width_2(flags, len);
		}
		else
		{
			str = ft_itoa_base(flags, i, 16);
			len = ft_strlen(str);
			print_width_2(flags, len);
			ft_putstr(str);
		}
	}
	if (flags->type == 'o')
	{
		if (flags->minus)
		{
			str = ft_itoa_base(flags, i, 8);
			len = ft_strlen(str);
			ft_putstr(str);
			print_width_2(flags, len);
		}
		else
		{
			str = ft_itoa_base(flags, i, 8);
			len = ft_strlen(str);
			print_width_2(flags, len);
			ft_putstr(str);
		}
	}
	if (flags->type == 'p')
	{
		if (flags->minus)
		{
			ft_putstr("0x");
			print_address(i, 16);
			if (flags->width > 14)
			{
				flags->width = flags->width - 14;
				while (flags->width-- > 0)
					ft_putchar(' ');
			}
		}
		else
		{
			if (flags->width > 14)
			{
				flags->width = flags->width - 14;
				while (flags->width-- > 0)
					ft_putchar(' ');
			}
			ft_putstr("0x");
			print_address(i, 16);
		}
	}
}