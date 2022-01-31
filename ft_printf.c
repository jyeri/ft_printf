/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrummuka <jrummuka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:56:34 by jrummuka          #+#    #+#             */
/*   Updated: 2022/01/20 20:58:15 by jrummuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int ft_store_width (const char *s, int i, t_flags flags)
{
	int width;

	width = 1;
	i++;
	while (ft_is_type_list(s, i) == 0)
	{
		if (s[i] > 9 && s[i] < 0)
			exit (-1);
		flags.width = flags.width * 10 + s[i];
		width++;
		i++;
	}
	return (width);
}

int ft_store_prec (const char *s, int i, t_flags flags)
{
	int precandwidth;

	precandwidth = 0;
	while (s[i] != '.' && ft_is_type_list(s, i) != 1)
	{
		flags.precision = flags.precision * 10 + s[i];
		precandwidth++;
		i++;
	}
	if (s[i] == '.')
	{
		precandwidth = precandwidth + ft_store_width(s, i, flags);
	}
	return (precandwidth);
}

void	read_input(const char *s, va_list args)
{
	int i;
	t_flags flags;

	i = 0;
	flags = init_flags();
	while (s[i] != '\0')
	{
		if (s[i] == '%' && s[i + 1])
		{
			i = ft_check_flags(s, i, flags);
			ft_check_type(s, i, args);
		}
		else
		{
			write (1, &s[i], 1);
		}
		i++;
	}
}

int	ft_check_flags(const char *s, int i, t_flags flags)
{
	while (s[i] != 'c' || s[i] != 's' || s[i] != 'p' || s[i] != 'd' || s[i] != 'i' || s[i] != 'o' || s[i] != 'u' || s[i] != 'x' || s[i] != 'X' || s[i] != 'f')
	{
		if (s[i] == '+')
			flags.plus = 1;
		if (s[i] == '-')
			flags.minus = 1;
		if (s[i] == ' ')
			flags.sp = 1;
		if (s[i] == '#')
			flags.hash = 1;
		if (s[i] == '0')
			flags.zero = 1;
		if (s[i] == '.')
		{
			flags.dot = 1;
			i = i + ft_store_width(s, i, flags);
		}
		if (s[i] <= 9 && s[i] > 0)
			i = i + ft_store_prec(s, i, flags);
		i++;
	}
	return (i);
}

void	ft_check_type(const char *s, int index, va_list args)
{
	int i;
	char *str;

	if (s[index] == 'd' || s[index] == 'c' || s[index] == 'i')
	{
		i = va_arg(args, int);
		ft_putn(i);
	}
	if (s[index] == 's')
	{
		str = va_arg(args, char *);
		ft_putstr(s);
	}
	if (s[index] == 'p')
		print_pointer(va_arg(args, int), flags);
	if (s[index] == 'o');
		print_octal(va_arg(args, unsigned int), flags);
	if (s[index] == 'f' || s[index] == 'F')
		print_float(va_arg(args, float), flags);
	if (s[index] == 'u');
		print_unsigned(va_arg(args, unsigned int), flags);
	if (s[index] == 'x' || s[index] == 'X');
		print_hexa(va_arg(args, unsigned int), flags);
	else
	{
		ft_printf("error!");
	}
}

void	ft_printf(const char *s, ...)
{
	int	i;
	va_list	args;

	i = 0;
	va_start(args, s);
	read_input(s, args);
	va_end(args);
}
