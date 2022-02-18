/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrummuka <jrummuka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:56:40 by jrummuka          #+#    #+#             */
/*   Updated: 2022/02/18 18:39:40 by jrummuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new.h"
#include <stdio.h>

int	main(void)
{
	int i;
	int i2;
	int i3;
	unsigned int ui;
	char c;
	const char *s;
	double d1;

	i = 902;
	i2 = 6;
	i3 = 7;
	ui = 3000.000000;
	d1 = 10.327;
	c = 'a';
	s = "HELLO";

	printf("TESTS WITH CHAR:\n\n");

	printf("real [c]: %c ending\n", c);
	ft_printf("mine [c]: %c ending\n\n", c);

//	printf("real [7.5c]: %7.5c ending\n", c);
//	ft_printf("mine [7.5c]: %7.5c ending\n\n", c);
//
//	printf("real [-7.5c]: %-7.5c ending\n", c);
//	ft_printf("mine [-7.5c]: %-7.5c ending\n\n", c);
//
//	printf("real [+7.5c]: %+7.5c ending\n", c);
//	ft_printf("mine [+7.5c]: %+7.5c ending\n\n", c);
//
//	printf("real [+-7.5c]: %+-7.5c ending\n", c);
//	ft_printf("mine [+-7.5c]: %+-7.5c ending\n\n", c);
//
//	printf("real [7.5c]: %7.5c ending\n", c);
//	ft_printf("mine [7.5c]: %7.5c ending\n\n", c);
//
//	printf("real [-7.5c]: %-7.5c ending\n", c);
//	ft_printf("mine [-7.5c]: %-7.5c ending\n\n", c);

	printf("TESTS WITH STRINGS:\n\n");

	printf("real [s]: %s ending\n", s);
	ft_printf("mine [s]: %s ending\n\n", s);

	printf("real [7.5s]: %7.5s ending\n", s);
	ft_printf("mine [7.5s]: %7.5s ending\n\n", s);

	printf("real [-7.5s]: %-7.5s ending\n", s);
	ft_printf("mine [-7.5s]: %-7.5s ending\n\n", s);

	printf("real [7.5s]: %7.5s ending\n", s);
	ft_printf("mine [7.5s]: %7.5s ending\n\n", s);

	printf("real [-7.5s]: %-7.5s ending\n", s);
	ft_printf("mine [-7.5s]: %-7.5s ending\n\n", s);

	printf("TESTS WITH INT:\n\n");
	sleep(3);

	printf("real [i]: %i ending\n", i);
	ft_printf("mine [i]: %i ending\n\n",i);

	printf("real [7.1i]: %7.1i ending\n", i);
	ft_printf("mine [7.1i]: %7.1i ending\n\n", i);

	printf("real [-7.5i]: %-7.5i ending\n", i);
	ft_printf("mine [-7.5i]: %-7.5i ending\n\n", i);

	printf("real [+7.5i]: %+7.5i ending\n", i);
	ft_printf("mine [+7.5i]: %+7.5i ending\n\n", i);

	printf("real [+-7.5i]: %+-7.5i ending\n", i);
	ft_printf("mine [+-7.5i]: %+-7.5i ending\n\n", i);

	printf("real [7.5i]: %7.5i ending\n", i);
	ft_printf("mine [7.5i]: %7.5i ending\n\n", i);

	printf("real [-7.5i]: %-7.5i ending\n", i);
	ft_printf("mine [-7.5i]: %-7.5i ending\n\n", i);

	printf("TESTS WITH UINT:\n\n");
	sleep(3);

	printf("real [u]: %u ending\n", ui);
	ft_printf("mine [u]: %u ending\n\n", ui);

	printf("real [7.5u]: %7.5u ending\n", ui);
	ft_printf("mine [7.5u]: %7.5u ending\n\n", ui);

	printf("real [-7.5u]: %-7.5u ending\n", ui);
	ft_printf("mine [-7.5u]: %-7.5u ending\n\n", ui);

	printf("real [7.5u]: %7.5u ending\n", ui);
	ft_printf("mine [7.5u]: %7.5u ending\n\n", ui);

	printf("real [-7.5u]: %-7.5u ending\n", ui);
	ft_printf("mine [-7.5u]: %-7.5u ending\n\n", ui);

	printf("TESTS WITH POINTERS:\n\n");
	sleep(3);

	printf("real [p]: %p ending\n", &i);
	ft_printf("mine [p]: %p ending\n\n", &i);

	printf("real [p]: %p ending\n", &ui);
	ft_printf("mine [p]: %p ending\n\n", &ui);

	printf("real [-25p]: %-25p ending\n", &c);
	ft_printf("mine [-25p]: %-25p ending\n\n", &c);

	printf("real [25p]: %25p ending\n", &ui);
	ft_printf("mine [25p]: %25p ending\n\n", &ui);

	printf("TESTS WITH X:\n\n");
	sleep(3);

	printf("real [x]: %x ending\n", i);
	ft_printf("mine [x]: %x ending\n\n", i);

	printf("real [x]: %x ending\n", ui);
	ft_printf("mine [x]: %x ending\n\n", ui);

	printf("real [-25x]: %-25x ending\n", c);
	ft_printf("mine [-25x]: %-25x ending\n\n", c);

	printf("real [25x]: %25x ending\n", ui);
	ft_printf("mine [25x]: %25x ending\n\n", ui);

	printf("TESTS WITH O:\n\n");
	sleep(3);

	printf("real [o]: %o ending\n", i);
	ft_printf("mine [o]: %o ending\n\n", i);

	printf("real [o]: %o ending\n", ui);
	ft_printf("mine [o]: %o ending\n\n", ui);

	printf("real [-25o]: %-25o ending\n", c);
	ft_printf("mine [-25o]: %-25o ending\n\n", c);

	printf("real [25o]: %25o ending\n", ui);
	ft_printf("mine [25o]: %25o ending\n\n", ui);

	printf("TESTS WITH f:\n\n");
	sleep(3);

	printf("real [f]: %f ending\n", d1);
	ft_printf("mine [f]: %f ending\n\n", d1);

	printf("real [f]: %f ending\n", d1);
	ft_printf("mine [f]: %f ending\n\n", d1);

	printf("real [-25f]: %-25f ending\n", d1);
	ft_printf("mine [-25f]: %-25f ending\n\n", d1);

	printf("real [25f]: %25f ending\n", d1);
	ft_printf("mine [25f]: %25f ending\n\n", d1);

	return (0);
}
