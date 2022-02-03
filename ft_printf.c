/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrummuka <jrummuka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:56:34 by jrummuka          #+#    #+#             */
/*   Updated: 2022/02/02 19:19:17 by jrummuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

t_flags	init_flags (void)
{
	t_flags flags;

	flags.plus = 0;
	flags.minus = 0;
	flags.width = 0;
	flags.precision = 0;
	flags.sp = 0;
	flags.hash = 0;
	flags.zero = 0;
	flags.dot = 0;
	return (flags);
}

int ft_is_type_list(const char *s, int i)
{
	if (s[i] == 'c' || s[i] == 's' || s[i] == 'p' || s[i] == 'd' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'x' || s[i] == 'X' || s[i] == 'f')
		return (1);
	return (0);
}

//int ft_store_width (const char *s, int i, t_flags flags)
//{
//	int width;
//
//	width = 1;
//	i++;
//	while (ft_is_type_list(s, i) == 0)
//	{
//		if (s[i] > 9 && s[i] < 0)
//			exit (-1);
//		flags.width = flags.width * 10 + s[i];
//		width++;
//		i++;
//	}
//	return (width);
//}
//
//int ft_store_prec (const char *s, int i, t_flags flags)
//{
//	int precandwidth;
//
//	precandwidth = 0;
//	while (s[i] != '.' && ft_is_type_list(s, i) != 1)
//	{
//		flags.precision = flags.precision * 10 + s[i];
//		precandwidth++;
//		i++;
//	}
//	if (s[i] == '.')
//	{
//		precandwidth = precandwidth + ft_store_width(s, i, flags);
//	}
//	return (precandwidth);
}

int	read_input(const char *s, va_list args)
{
	int i;
	t_flags flags;

	i = 0;
	flags = init_flags();
	while (s[i] != '\0')
	{
		if (s[i] == '%' && s[i + 1])
		{
			ft_check_type(s, i + 1, args, flags);
			i++;
		}
		else
		{
			write (1, &s[i], 1);
		}
		i++;
	}
	return (i);
}

void	ft_check_flags(const char *s, int i, t_flags flags)
{
	if (ft_isdigit(s[i]))
	{
		if (flags.dot || flags.zero)
			flags.precision = flags.precision * 10 + s[i] - '0';
		else
		{
			if (!flags.width && s[i] == '0')
				flags.zero = 1;
			flags.width = flags.width * 10 + s[i] - '0';
		}
	}
	if (s[i] == '+')
		flags.plus = 1;
	if (s[i] == '-')
		flags.minus = 1;
	if (s[i] == ' ')
		flags.sp = 1;
	if (s[i] == '#')
		flags.hash = 1;
	if (s[i] == '.')
		flags.dot = 1;
	if (s[i] == 'l')
	{
		if (s[i + 1] == 'l')
		{
			i++;
			flags.ll = 1;
		}
		else
		{
			flags.l = 1;
		}
	}
	if (s[i] == 'h')
	{
		if (s[i + 1] == 'h')
		{
			i++;
			flags.hh = 1;
		}
		else
		{
			flags.h = 1;
		}
	}

}

int	ft_check_type(const char *s, int index, va_list args, t_flags flags)
{
	int i = 0;
	char *str = NULL;

	while (s[index] != 'c' && s[index] != 's' && s[index] != 'p'
		&& s[index] != 'd' && s[index] != 'i' && s[index] != 'o'
		&& s[index] != 'u' && s[index] != 'x' && s[index] != 'X')
	{
		ft_check_flags(s, index + 1, flags);
		index++;
	}
	if (s[index] == 'd' || s[index] == 'i')
	{
		i = va_arg(args, int);
		ft_putnbr(i);
		index++;
	}
	else if (s[index] == 's')
	{
		str = va_arg(args, char *);
		ft_putstr(str);
		index++;
	}
	if (s[index] == 'c')
		ft_putchar(va_arg(args, int));
	if (s[index] == 'p')
		print_pointer(va_arg(args, unsigned long long));
	if (s[index] == 'o')
		print_octal(va_arg(args, unsigned int));
//	if (s[index] == 'f' || s[index] == 'F')
//		print_float(va_arg(args, double), flags);
	if (s[index] == 'u')
		print_unsigned(va_arg(args, unsigned int), 10);
	if (s[index] == 'x' || s[index] == 'X')
		print_unsigned(va_arg(args, unsigned int), 16);
//	if (str[index + 1] == '%')
//		ft_putchar(str[index]);
//	else
//	{
//		ft_printf("error!");
//	}
	return (i);
}

int	ft_printf(const char *s, ...)
{
	int	i;
	va_list	args;

	i = 0;
	va_start(args, s);
	i = read_input(s, args);
	va_end(args);
	return (i);
}
