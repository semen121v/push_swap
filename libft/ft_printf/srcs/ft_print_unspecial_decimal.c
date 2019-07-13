/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unspecial_decimal.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 19:15:53 by fshade            #+#    #+#             */
/*   Updated: 2019/05/17 22:40:58 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int						ft_size(t_attrib *atr, va_list argument)
{
	int							i;
	unsigned long long int		a;

	i = 1;
	if (atr->flag & (1 << (24)))
		a = (ssize_t)va_arg(argument, ssize_t);
	else
		a = (intmax_t)va_arg(argument, intmax_t);
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

int								ft_unspecial_decimal(t_attrib *atr, \
									va_list argument)
{
	int							i;
	unsigned long long int		a;
	va_list						argument2;

	i = 0;
	va_copy(argument2, argument);
	ft_decimal_logic(atr, argument2, i);
	if (atr->flag & (1 << (24)))
		a = (ssize_t)va_arg(argument, ssize_t);
	else
		a = (intmax_t)va_arg(argument, intmax_t);
	ft_putnbr(a);
	if ((atr->flag & (1 << (25))) && (atr->flag & (1 << (2))))
		atr->symbol = atr->symbol + ft_putchar_symbol(' ', atr->width);
	return (atr->symbol + atr->number);
}
