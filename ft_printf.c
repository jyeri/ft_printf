/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrummuka <jrummuka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:56:34 by jrummuka          #+#    #+#             */
/*   Updated: 2022/01/20 13:45:00 by jrummuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	init_flags (t_flags flags)
{
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

void	ft_check_flags(const char *s, int i, t_flags flags)
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
			flags.dot = 1;
		i++;
	}
}

void	ft_check_type(const char *s, int index t_flags flags)
{
	if (s[index] == 'c')
		print_char(s, index);
	if (s[index] == 's')
		print_string(s, index);
	if (s[index] == 'p')
		print_pointer(s, index);
	if (s[index] == 'd' || s[index] == 'i' || s[index] == 'o' || s[index] == 'u' || s[index] == 'x' || s[index] == 'X');
		print_integer(s, index);
	if (s[index] == 'f' || s[index] == 'F')
		print_float(s, index);
	else
		ft_printf("error!");
}

void	ft_printf(const char *s, ...)
{
	int	i;
	t_flags flags;
	va_list	args;

	flags = (t_flags)malloc(sizeof(t_flags));
	if (!flags)
		exit(-1);
	flags = init_flags(flags);
	i = 0;
	while (s)
	{
		if (s[i] == '%')
		{
			i++;
			ft_check_flags(*s, i, flags);
			ft_check_type(*s, i, flags);
		}
		else
		{
			write (1, &s[i], 1);
		}
		i++;
	}
}
