#include "ft_printf.h"

int print_char(int i)
{
	write(1, &i, 1);
	return (1);
}

int print_address(unsigned long long i, int base)
{
	const char *values = "0123456789abcdef";
	if (i / base)
		print_address(i / base, base);
	ft_putchar(values[i % base]);
	return (i);
}

int print_pointer(unsigned long long i)
{
	ft_putstr("0x");
	print_address(i, 16);
	return (i);
}

int print_octal(unsigned int i)
{
	int j = 0;
	int k = 0;
	int hold[10];

	while (i > 0)
	{
		hold[j] = i % 8;
		i = i / 8;
		j++;
	}

	k = j - 1;
	while(k >= 0)
	{
		ft_putnbr(hold[k]);
		k--;
	}
	return (k);
}

int print_unsigned(unsigned int i, int base)
{
	const char *values = "0123456789abcdef";
	int sign = 1;

	if (i < 0)
	{
		sign = -1;
		ft_putchar('-');
	}
	if (i / base)
		print_unsigned(i / base * sign, base);
	ft_putchar(values[i % base * sign]);
	return (i);
}