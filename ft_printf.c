/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrummuka <jrummuka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:56:34 by jrummuka          #+#    #+#             */
/*   Updated: 2022/01/18 20:23:51 by jrummuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_flags(const char *s, int i)
{
	while (s[i] != 'c' || s[i] != 's' || s[i] != 'p' || s[i] != 'd' || s[i] != 'i' || s[i] != 'o' || s[i] != 'u' || s[i] != 'x' || s[i] != 'X' || s[i] != 'f')
	{
		if (s[i] == '+')
			t_flags->plus = 1;
		if (s[i] == '-')
			t_flags->minus = 1;
		if (s[i] == ' ')
			t_flags->sp = 1;
		if (s[i] == '#')
			t_flags->hash = 1;
		if (s[i] == '0')
			t_flags->zero = 1;
		if (s[i] == '.')
			t_flags->dot = 1;
		i++;
	}
}

void	ft_check_type(const char *s, int index)
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

	flags = (t_flags)malloc(sizeof(t_flags));
	if (!flags)
		exit(-1);
	i = 0;
	while (s)
	{
		if (s[i] == '%')
		{
			i++;
			ft_check_flags(*s, i);
			ft_check_type(*s, i);
		}
		else
		{
			ft_putchar(s[i]);
		}
		i++;
	}
}
