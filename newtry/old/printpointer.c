#include "new.h"

int print_address(unsigned long long i, int base)
{
	const char *values = "0123456789abcdef";
	if (i / base)
		print_address(i / base, base);
	ft_putchar(values[i % base]);
	return (i);
}

char ft_hexlen(unsigned long long i, int base)
{
	const char *values = "0123456789abcdef";

	if (i / base)
		print_address(i / base, base);
	ft_putchar(values[i % base]);
	return (i);
}

// MUISTA KORVATA 14 HEXLENGTHILLA
int print_pointer(t_flags *flags)
{
	unsigned long long i;
	int hex_len;

	i = va_arg(flags->args, unsigned long long);
	hex_len = ft_hexlen(i, 16);
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
	return (i);
}