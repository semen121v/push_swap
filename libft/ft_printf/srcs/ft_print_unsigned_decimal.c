/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_decimal.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 12:39:25 by semen             #+#    #+#             */
/*   Updated: 2019/05/17 22:40:53 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static unsigned long long int	ft_size2(va_list argument2, t_attrib *atr, \
											int id)
{
	unsigned long long int		a;

	if (atr->flag & (1 << (21)))
		a = (unsigned long long)va_arg(argument2, unsigned long int);
	else if ((atr->flag & (1 << (22))) || (id == UPP_U))
		a = (unsigned long long int)va_arg(argument2, unsigned long long int);
	else if (atr->flag & (1 << (20)))
		a = (unsigned long long)(unsigned short)va_arg(argument2, unsigned int);
	else if (atr->flag & (1 << (19)))
		a = (unsigned long long)(unsigned char)va_arg(argument2, unsigned int);
	else
		a = (unsigned long long)va_arg(argument2, unsigned int);
	return (a);
}

static int						ft_size(va_list argument, t_attrib *atr, int id)
{
	int							i;
	unsigned long long int		a;
	va_list						argument2;

	va_copy(argument2, argument);
	i = 1;
	atr->number = 0;
	a = ft_size2(argument2, atr, id);
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
									va_list argument, int id)
{
	int							i;

	atr->znak = '+';
	i = ft_size(argument, atr, id);
	if ((atr->flag & (1 << (26))) && (atr->accuracy > atr->number))
	{
		atr->accuracy = atr->accuracy - atr->number;
		i = i + atr->accuracy;
		atr->logic = 0;
	}
	if ((atr->flag & (1 << (3)) && !(atr->znak == '-')))
		i++;
	ft_special_zero(atr, i);
	if (atr->znak == '-')
		atr->symbol = atr->symbol + ft_putchar_symbol('-', 1);
	if ((atr->flag & (1 << (25))) && !(atr->flag & (1 << (2))) \
				&& (atr->width - i > 0))
		atr->symbol = atr->symbol + ft_putchar_symbol(' ', atr->width - i);
	if ((atr->flag & (1 << (26))) && (atr->logic == 0))
		atr->symbol = atr->symbol + ft_putchar_symbol('0', atr->accuracy);
	if (atr->flag & (1 << (2)))
		atr->width = atr->width - i;
	return ;
}

int								ft_unsigned_decimal(int id, t_attrib *atr, \
										va_list argument)
{
	unsigned long long int		a;

	if ((atr->flag & (1 << (23))) || (atr->flag & (1 << 24)))
		return (ft_unspecial_decimal(atr, argument));
	ft_decimal_logic(atr, argument, id);
	if (atr->flag & (1 << (21)))
		a = (unsigned long long)va_arg(argument, unsigned long int);
	else if ((atr->flag & (1 << (22))) || (id == UPP_U))
		a = (unsigned long long int)va_arg(argument, unsigned long long int);
	else if (atr->flag & (1 << (20)))
		a = (unsigned long long)(unsigned short)va_arg(argument, unsigned int);
	else if (atr->flag & (1 << (19)))
		a = (unsigned long long)(unsigned char)va_arg(argument, unsigned int);
	else
		a = (unsigned long long)va_arg(argument, unsigned int);
	if (!((atr->flag & (1 << (26))) && (a == 0)))
		ft_putnbr(a);
	if ((atr->flag & (1 << (25))) && (atr->flag & (1 << (2))))
		atr->symbol = atr->symbol + ft_putchar_symbol(' ', atr->width);
	return (atr->symbol + atr->number);
}
