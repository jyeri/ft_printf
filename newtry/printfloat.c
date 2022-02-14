#include "new.h"

static char *ft_ftoi_helper(intmax_t n, int base)
{
	char *buf;
	char *tab;
	int i;
	uintmax_t value;

	tab = "0123456789abcdef";
	i = 30;
	buf = "0";
	if (n == 0)
		return(buf);
	if (n < 0)
	{
		value = -n;
		while (value > 0 && i > 0)
		{
			ft_putendl("here3");
			buf[i] = tab[value % base];
			value = value / base;
			--i;
		}
		return (buf + i + 1);
	}
	while (n > 0 && i > 0)
	{
		ft_putendl("here2");
		buf[i] = tab[n % base];
		n = n / base;
		--i;
	}
	return (buf + i + 1);
}

static char *ft_ftoa(double n, int prec)
{
	char *str = NULL;
	char *str2 = NULL;
	int i = 0;
	int bef_part = 0;
	int aft_part = 0;

	bef_part = n;
	n = n - bef_part;
	while (i < prec)
	{
		ft_putendl("here1");
		n = n * 10;
		i++;
	}
	aft_part = n * 0.1 * 10;
	if (aft_part < 0)
		aft_part = -1 * aft_part;
	str = ft_ftoi_helper(bef_part, 10);
	str = ft_strjoin(str, ".");
	str2 = ft_ftoi_helper(aft_part, 10);
	str = ft_strjoin(str, str2);
	return (str);
}

int print_float(t_flags *flags)
{
	char *str;
	double f;

	f = va_arg(flags->args, double);
	str = ft_ftoa(f, 6);
	ft_putstr(str);

	return (1);
}