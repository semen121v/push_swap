/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexdecimal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 14:43:17 by fshade            #+#    #+#             */
/*   Updated: 2019/05/17 22:43:17 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <limits.h>

static int						conv_ex(int nb, int id)
{
	if (nb >= 10 && id == LOW_X)
		return (nb - 10 + 'a');
	else if (nb >= 10 && id == UPP_X)
		return (nb - 10 + 'A');
	else
		return (nb + '0');
}

static char						*ft_itoa_base(unsigned long long int value,\
									int id)
{
	int							i;
	char						*str;
	unsigned long long int		tmp;

	i = 0;
	tmp = value;
	while (tmp >= 16)
	{
		tmp = tmp / 16;
		i++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i + 1] = '\0';
	while (i >= 0)
	{
		tmp = value % 16;
		str[i] = conv_ex(tmp, id);
		value /= 16;
		i--;
	}
	return (str);
}

static void						ft_decimal_logic(t_attrib *atr, int id,\
								unsigned long long int a)
{
	int							i;

	i = atr->number;
	if ((atr->flag & (1 << (26))) && (atr->accuracy > atr->number))
	{
		atr->accuracy = atr->accuracy - atr->number;
		i = i + atr->accuracy;
		atr->logic = 0;
	}
	if ((atr->flag & (1 << (0))))
		i = i + 2;
	if ((atr->flag & (1 << (25))) && !(atr->flag & (1 << (2))) \
				&& (atr->width - i > 0) && !(atr->flag & (1 << (1))))
		atr->symbol = atr->symbol + ft_putchar_symbol(' ', atr->width - i);
	if ((atr->flag & (1 << (0))) && id == LOW_X && a != 0)
		atr->symbol = atr->symbol + ft_putstr(S_X) + 2;
	else if ((atr->flag & (1 << (0))) && id == UPP_X && a != 0)
		atr->symbol = atr->symbol + ft_putstr(B_X) + 2;
	ft_special_zero(atr, i);
	if ((atr->flag & (1 << (26))) && (atr->logic == 0))
		atr->symbol = atr->symbol + ft_putchar_symbol('0', atr->accuracy);
	if (atr->flag & (1 << (2)))
		atr->width = atr->width - i;
	return ;
}

static unsigned long long int	format(va_list arg, \
										t_attrib *atr)
{
	unsigned long long int		a;

	if (atr->flag & (1 << (21)))
		a = (unsigned long long)va_arg(arg, unsigned long int);
	else if ((atr->flag & (1 << (22))))
		a = (unsigned long long int)va_arg(arg, unsigned long long int);
	else if (atr->flag & (1 << (20)))
		a = (unsigned long long)(unsigned short)va_arg(arg, unsigned int);
	else if (atr->flag & (1 << (19)))
		a = (unsigned long long)(unsigned char)va_arg(arg, unsigned int);
	else
		a = (unsigned long long)va_arg(arg, unsigned int);
	return (a);
}

int								print_hexadecimal1(int id, va_list arg, \
										t_attrib *atr)
{
	char						*str;
	unsigned long long int		a;

	a = 0;
	if (atr->flag & (1 << (23)))
		return (special_hexdecimal(arg, atr, id));
	a = format(arg, atr);
	str = ft_itoa_base(a, id);
	atr->number = ft_unsize(a, atr);
	if ((atr->flag & (1 << (26))) && (a == 0))
		atr->number = 0;
	ft_decimal_logic(atr, id, a);
	if ((atr->flag & (1 << (26))) && (a == 0))
		return (atr->symbol);
	ft_putstr(str);
	free(str);
	if ((atr->flag & (1 << (25))) && (atr->flag & (1 << (2))) \
				&& (atr->width > 0))
		atr->symbol = atr->symbol + ft_putchar_symbol(' ', atr->width);
	atr->number = ft_unsize(a, atr);
	return (atr->number + atr->symbol);
}
