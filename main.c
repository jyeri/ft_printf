/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrummuka <jrummuka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:56:40 by jrummuka          #+#    #+#             */
/*   Updated: 2022/01/18 13:16:03 by jrummuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int i;
	int i2;
	int i3;
	char c;
	const char *s;

	i = 5;
	i2 = 6;
	i3 = 7;
	c = 'a';
	s = "HELLO";
	printf("real: %i this\n", i);
	ft_printf("mine: %i this\n\n", i);

	printf("real: %d this\n", i);
	ft_printf("mine: %d this\n\n", i);

	printf("real: %c\n", c);
	ft_printf("mine: %c\n\n", c);

	printf("real: %s this\n", s);
	ft_printf("mine: %s this\n\n", s);
//
//	printf("real: %p\n", &s);
//	ft_printf("mine: %p\n\n", &s);
//
//	printf("real: %o\n", i);
//	ft_printf("mine: %o\n\n", i);
//
//	printf("real: %u\n", i);
//	ft_printf("mine: %u\n\n", i);
//
	return (0);
}