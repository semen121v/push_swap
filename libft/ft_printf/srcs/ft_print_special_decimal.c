/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_special_decimal.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 00:56:36 by semen             #+#    #+#             */
/*   Updated: 2019/05/17 22:40:40 by fshade           ###   ########.fr       */
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

static int						ft_size_minus(int i, long int a,\
											t_attrib *atr)
{
	atr->number = -1;
	atr->znak = '-';
	i++;
	while (a < -10)
	{
		i++;
		a = a / 10;
	}
	return (i);
}

static int						ft_size(t_attrib *atr, va_list argument)
{
	int							i;
	long long int				a;

	i = 1;
	a = va_arg(argument, long long int);
	if (a < 0)
		i = ft_size_minus(i, a, atr);
	while (a >= 10)
	{
		i++;
		a = a / 10;
	}
	atr->number = atr->number + i;
	return (i);
}

static void						ft_decimal_logic(t_attrib *atr, \
										va_list argument, int i)
{
	atr->znak = '+';
	i = ft_size(atr, argument);
	if ((atr->flag & (1 << (26))) && (atr->accuracy > atr->number))
	{
		atr->accuracy = atr->accuracy - atr->number;
		i = i + atr->accuracy;
		atr->logic = 0;
	}
	if ((atr->flag & (1 << (3)) && !(atr->znak == '-')))
		i++;
	ft_special_zero(atr, i);
	if ((atr->flag & (1 << (4))) && !(atr->flag & (1 << (3))) && \
		(atr->width - i <= 0) && !(atr->znak == '-'))
		atr->symbol = atr->symbol + ft_putchar_symbol(' ', 1);
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

int								ft_special_decimal(t_attrib *atr, \
									va_list argument)
{
	int							i;
	long int					a;
	va_list						argument2;

	i = 0;
	va_copy(argument2, argument);
	ft_decimal_logic(atr, argument2, i);
	if (atr->flag & (1 << (24)))
		a = (ssize_t)va_arg(argument, ssize_t);
	else
		a = ft_max_int((intmax_t)va_arg(argument, intmax_t));
	if (a < 0)
		a = a * (-1);
	ft_putnbr(a);
	if ((atr->flag & (1 << (25))) && (atr->flag & (1 << (2))))
		atr->symbol = atr->symbol + ft_putchar_symbol(' ', atr->width);
	return (atr->symbol + atr->number);
}
