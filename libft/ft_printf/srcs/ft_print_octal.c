/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 20:08:49 by fshade            #+#    #+#             */
/*   Updated: 2019/05/17 22:40:29 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int						ft_size(t_attrib *atr, unsigned long long int a)
{
	int							i;

	i = 1;
	while (a > 8)
	{
		i++;
		a = a / 8;
	}
	if ((atr->flag & (1 << (26))) && a == 0)
		i--;
	atr->number = atr->number + i;
	return (i);
}

static void						ft_decimal_logic(t_attrib *atr, \
										unsigned long long int a)
{
	int							i;

	i = ft_size(atr, a);
	if ((atr->flag & (1 << (26))) && (atr->accuracy > atr->number))
	{
		atr->accuracy = atr->accuracy - atr->number;
		i = i + atr->accuracy;
		atr->logic = 0;
	}
	if ((((atr->flag & (1 << (0)) && a != 0) && !(atr->flag & (1 << (26))))) \
			|| ((atr->flag & (1 << (0)) && atr->accuracy == 0)))
		i++;
	ft_special_zero(atr, i);
	if ((atr->flag & (1 << (25))) && !(atr->flag & (1 << (2))) \
				&& (atr->width - i > 0))
		atr->symbol = atr->symbol + ft_putchar_symbol(' ', atr->width - i);
	if ((((atr->flag & (1 << (0))) && a != 0) && !(atr->flag & (1 << (26)))) \
			|| ((atr->flag & (1 << (0))) && (atr->flag & (1 << (26))) \
							&& atr->accuracy == 0))
		atr->symbol = atr->symbol + ft_putchar_symbol('0', 1);
	if ((atr->flag & (1 << (26))) && (atr->logic == 0))
		atr->symbol = atr->symbol + ft_putchar_symbol('0', atr->accuracy);
	if (atr->flag & (1 << (2)))
		atr->width = atr->width - i;
	return ;
}

int								ft_print_octal(t_attrib *atr, \
									va_list argument)
{
	unsigned long long int		a;

	a = 0;
	if (atr->flag & (1 << (22)))
		a = (unsigned long long)va_arg(argument, unsigned long int);
	else if (atr->flag & (1 << (21)))
		a = (unsigned long long int)va_arg(argument, unsigned long long int);
	else if (atr->flag & (1 << (20)))
		a = (unsigned long long)(unsigned short)va_arg(argument, int);
	else if (atr->flag & (1 << (19)))
		a = (unsigned long long)(unsigned char)va_arg(argument, int);
	else
		a = (unsigned long long)va_arg(argument, unsigned int);
	ft_decimal_logic(atr, a);
	if (!((atr->flag & (1 << (26))) && (a == 0)))
		ft_putnbr_octal(a);
	if ((atr->flag & (1 << (25))) && (atr->flag & (1 << (2))) \
				&& (atr->width > 0))
		atr->symbol = atr->symbol + ft_putchar_symbol(' ', atr->width);
	return (atr->symbol + atr->number);
}
