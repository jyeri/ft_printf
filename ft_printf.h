/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrummuka <jrummuka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:56:37 by jrummuka          #+#    #+#             */
/*   Updated: 2022/02/02 15:44:52 by jrummuka         ###   ########.fr       */
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
	int l; //long
	int ll; //long long
	int h; // short int
	int hh; //short

} t_flags;

t_flags	init_flags (void);
int ft_is_type_list(const char *s, int i);
int ft_store_prec (const char *s, int i, t_flags flags);
int ft_store_width (const char *s, int i, t_flags flags);
int	read_input(const char *s, va_list args);
int	ft_check_flags(const char *s, int i, t_flags flags);
int	ft_check_type(const char *s, int index, va_list args);
int	ft_printf(const char *s, ...);
int print_octal(unsigned int i);
int print_unsigned(unsigned int i);