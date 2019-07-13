/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:23:19 by fshade            #+#    #+#             */
/*   Updated: 2019/05/17 22:40:10 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <limits.h>

static long long int			ft_max_int(int64_t a)
{
	if (a == LLONG_MIN)
	{
		ft_putchar('9');
		a = 223372036854775808;
	}
	return (a);
}

static int						ft_size_minus(int i, long long int a,\
											t_attrib *atr)
{
	atr->number = -1;
	atr->znak = '-';
	i++;
	while (a <= -10)
	{
		i++;
		a = a / 10;
	}
	return (i);
}

static int						ft_size(t_attrib *atr, \
									va_list argument2)
{
	int							i;
	long long int				a;
	va_list						argument;

	a = 0;
	va_copy(argument, argument2);
	i = 1;
	atr->znak = '+';
	a = ft_size_special(atr, argument);
	if (a < 0)
		i = ft_size_minus(i, a, atr);
	while (a >= 10)
	{
		i++;
		a = a / 10;
	}
	if ((atr->flag & (1 << (26))) && a == 0)
		i--;
	atr->number = atr->number + i;
	return (i);
}

static void						ft_decimal_logic(t_attrib *atr, \
										va_list argument)
{
	int							i;

	i = ft_size(atr, argument);
	if ((atr->flag & (1 << (26))) && (atr->accuracy > atr->number))
	{
		atr->accuracy = atr->accuracy - atr->number;
		i = i + atr->accuracy;
		atr->logic = 0;
	}
	if ((atr->flag & (1 << (3)) && !(atr->znak == '-')))
		i++;
	i = ft_special_space(atr, i);
	ft_special_zero(atr, i);
	if ((atr->flag & (1 << (25))) && !(atr->flag & (1 << (2))) \
				&& (atr->width - i > 0))
		atr->symbol = atr->symbol + ft_putchar_symbol(' ', atr->width - i);
	if ((atr->flag & (1 << (3))) || atr->znak == '-')
		atr->symbol = atr->symbol + ft_putchar_symbol(atr->znak, 1);
	if ((atr->flag & (1 << (26))) && (atr->logic == 0))
		atr->symbol = atr->symbol + ft_putchar_symbol('0', atr->accuracy);
	if (atr->flag & (1 << (2)))
		atr->width = atr->width - i;
	return ;
}

int								ft_print_decimal(int id, t_attrib *atr, \
										va_list argument)
{
	long long int				a;

	a = 0;
	if (id == LOW_U || id == UPP_U || (atr->flag & (1 << (23)))\
			|| (atr->flag & (1 << (24))))
		return (ft_special_decimal(atr, argument));
	ft_decimal_logic(atr, argument);
	if (atr->flag & (1 << (22)))
		a = (long long int)va_arg(argument, long long int);
	else if (atr->flag & (1 << (21)))
		a = (long long int)ft_max_int((int64_t)va_arg(argument, int64_t));
	else if (atr->flag & (1 << (20)))
		a = (long long int)(short)va_arg(argument, int);
	else if (atr->flag & (1 << (19)))
		a = (long long int)(char)va_arg(argument, int);
	else
		a = (long long int)va_arg(argument, int);
	a *= (a < 0) ? -1 : 1;
	if (!((atr->flag & (1 << (26))) && (a == 0)))
		ft_putnbr(a);
	if ((atr->flag & (1 << (25))) && (atr->flag & (1 << (2))) \
				&& (atr->width > 0))
		atr->symbol = atr->symbol + ft_putchar_symbol(' ', atr->width);
	return (atr->symbol + atr->number);
}
