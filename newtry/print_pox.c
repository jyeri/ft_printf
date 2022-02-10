#include "new.h"

char *ft_itoa_base(int n, int base)
{
	char *str;
	char *tab;
	int counter;
	long holder;

	holder = n;
	counter = 0;
	tab = "0123456789ABCDEF";
	if (n == 0)
		return ("0");
	while (holder)
	{
		counter++;
		holder = holder / base;
	}
	holder = n;
	if (n < 0)
	{
		if (base == 10)
			counter++;
		holder = holder * -1;
	}
	str = (char *)malloc(sizeof(char) * counter);
	if (!str)
		exit (-1);
	str[counter] = '\0';
	while (holder)
	{
		str[--counter] = tab[holder % base];
		holder = holder / base;
	}
	if (n < 0 && base == 10)
		str[0] = '-';
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

void print_pox(t_flags *flags)
{
	char *str;
	int base;
	long long n;

	n = va_arg(flags->args, unsigned int);
	if (flags->type == 'x' || flags->type == 'X')
	{
		base = 16;
		str = ft_itoa_base(n, base);
	}
	if (flags->type == 'p')
	{
		base = 10;
		str = ft_itoa_base(n, base);
	}
	if (flags->type == 'o')
	{
		base = 8;
		str = ft_itoa_base(n, base);
	}
	ft_putstr(str);
	free(str);
}