#include "new.h"

char *ldtoa(long double ld)
{
	char *str;
	double base;

	base = 10;

	while (ld > 0)
	{
		*str = ld % base - '0'; 
		ld = ld / base;
	}
	return (str);
}

int print_float(t_flags *flags)
{
	char *str;
	double f;

	f = va_arg(flags->args, double);
	str = ldtoa(f);
	ft_putstr(str);

	return (1);
}