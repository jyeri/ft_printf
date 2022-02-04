#include "new.h"

void print_actual_string(char *s, int len)
{
	write(1, s, len);
}

int print_string(t_flags *flags)
{
	const char *str;
	int i;
	int len;

	i = 0;
	str = va_arg(flags->args, char *);
	len = ft_strlen(str);
	print_actual_string((char *)str, len);
	return (1);
}