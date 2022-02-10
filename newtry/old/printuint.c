#include "new.h"

int print_octal(t_flags *flags)
{
	unsigned int i;
	int j = 0;
	int k = 0;
	int hold[10];

	i = va_arg(flags->args, unsigned int);
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

int print_unsigned(char c, t_flags *flags, int base)
{
	unsigned int n;

	if (c == 'X')
		flags->bigones = 1;
	n = va_arg(flags->args, unsigned int);
	print_nbr_base(n, base, flags);
	return (1);
}

void print_nbr_base(long long n, int base, t_flags *flags)
{
	int sign;
	char *array;

	array = "0123456789abcdef";
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		ft_putchar('-');
	}
	else if (flags->hash && n > 0)
	{
		ft_putstr("0x");
	}
	if (n / base)
		print_nbr_base(n / base * sign, base, flags);
	ft_putchar(array[n % base * sign]);
}