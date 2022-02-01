#include "ft_printf.h"

//int print_pointer(unsigned long i, t_flags flags)
//{
//
//}
//
//int print_octal(unsigned int i, t_flags flags)
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

int print_unsigned(unsigned int i)
{
	ft_putnbr(i);
	return (i);
}