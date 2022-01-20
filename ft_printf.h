/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrummuka <jrummuka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:56:37 by jrummuka          #+#    #+#             */
/*   Updated: 2022/01/20 21:07:02 by jrummuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>

typedef struct s_flags
{
	int width; //width
	int precision; //precision
	int	zero; //flag 0
	int plus; //flag +
	int minus; //flag -
	int hash; //flag #
	int sp; //flag space (' ')
	int dot; //flag dot
	int type; //store the type

} t_flags;
