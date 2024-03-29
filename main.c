/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrummuka <jrummuka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:56:40 by jrummuka          #+#    #+#             */
/*   Updated: 2022/02/02 18:27:08 by jrummuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int i;
	int i2;
	int i3;
	unsigned int ui;
	char c;
	const char *s;

	i = 9;
	i2 = 6;
	i3 = 7;
	ui = 3000000000;
	c = 'a';
	s = "HELLO";
	printf("real [i]: %i ending\n", i);
	ft_printf("mine [i]: %i ending\n\n", i);

	printf("real [d]: %d ending\n", i);
	ft_printf("mine [d]: %d ending\n\n", i);

	printf("real [c]: %c ending\n", c);
	ft_printf("mine [c]: %c ending\n\n", c);

	printf("real [s]: %s ending\n", s);
	ft_printf("mine [s]: %s ending\n\n", s);

	printf("real [p]: %p ending\n", &s);
	ft_printf("mine [p]: %p ending\n\n", &s);

	printf("real [o]: %o ending\n", i);
	ft_printf("mine [o]: %o ending\n\n", i);

	printf("real [u]: %u ending\n", ui);
	ft_printf("mine [u]: %u ending\n\n", ui);

	printf("real [x]: %x ending\n", ui);
	ft_printf("mine [x]: %x ending\n\n", ui);

	return (0);
}
