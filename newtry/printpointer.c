#include "new.h"

int print_address(unsigned long long i, int base)
{
	const char *values = "0123456789abcdef";
	if (i / base)
		print_address(i / base, base);
	ft_putchar(values[i % base]);
	return (i);
}

int print_pointer(t_flags *flags)
{
	unsigned long long i;

	i = va_arg(flags->args, unsigned long long);
	ft_putstr("0x");
	print_address(i, 16);
	return (i);
}