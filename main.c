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
	printf("real: %d\n", i);
	ft_printf("mine: %d\n\n", i);

	printf("real: %i\n", i);
	ft_printf("mine: %i\n\n", i);

	printf("real: %c\n", c);
	ft_printf("mine: %c\n\n", c);

	printf("real: %s\n", s);
	ft_printf("mine: %s\n\n", s);

	printf("real: %p\n", &s);
	ft_printf("mine: %p\n\n", &s);

	printf("real: %o\n", i);
	ft_printf("mine: %o\n\n", i);

	printf("real: %u\n", i);
	ft_printf("mine: %u\n\n", i);

	return (0);
}