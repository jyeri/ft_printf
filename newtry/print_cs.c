#include "new.h"

void print_actual_string(char *s, t_flags *flags)
{
	write(1, s, len);
}

int print_s(t_flags *flags)
{
	char *str;
	char *tmp;
	int i;
	int len;

	i = 0;
	str = va_arg(flags->args, char *);
	if (flags->precision >= 0)
	{
		tmp = ft_strsub(str, 0, flags->precision)
		free(str);
		str = tmp;
	}
	print_actual_string(&str, flags);
	return (1);
}

int print_c(t_flags *flags)
{
	char c;
	
	c = (char)va_arg(flags->args, int);

	return (1);
}