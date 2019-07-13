/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 20:43:30 by fshade            #+#    #+#             */
/*   Updated: 2019/05/17 22:44:29 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int					conv_ex(int nb)
{
	if (nb >= 10)
		return (nb - 10 + 'a');
	else
		return (nb + '0');
}

static char					*ft_itoa_base(unsigned long long int value,\
								int base, t_attrib *atr)
{
	int						i;
	char					*str;
	long long int			tmp;

	i = 0;
	tmp = value;
	atr->number = 1;
	while (tmp >= base)
	{
		tmp = tmp / base;
		i++;
	}
	atr->number = atr->number + i;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i + 1] = '\0';
	while (i >= 0)
	{
		tmp = value % base;
		str[i] = conv_ex(tmp);
		value /= base;
		i--;
	}
	return (str);
}

static void					ft_decimal_logic(t_attrib *atr)
{
	int						i;

	i = atr->number + 2;
	if ((atr->flag & (1 << (26))) && (atr->accuracy > atr->number))
	{
		atr->accuracy = atr->accuracy - atr->number;
		i = i + atr->accuracy;
		atr->logic = 0;
	}
	if ((atr->flag & (1 << (25))) && !(atr->flag & (1 << (2))) \
				&& (atr->width - i > 0) && !(atr->flag & (1 << (1))))
		atr->symbol = atr->symbol + ft_putchar_symbol(' ', atr->width - i);
	atr->symbol = atr->symbol + ft_putstr(S_X) + 2;
	ft_special_zero(atr, i);
	if ((atr->flag & (1 << (26))) && (atr->logic == 0))
		atr->symbol = atr->symbol + ft_putchar_symbol('0', atr->accuracy);
	if (atr->flag & (1 << (2)))
		atr->width = atr->width - i;
	return ;
}

int							print_pointer(va_list arg, t_attrib *atr)
{
	char					*str;
	unsigned long long int	a;

	a = 0;
	a = (unsigned long long int)va_arg(arg, unsigned long long int);
	str = ft_itoa_base(a, 16, atr);
	if (a == 0 && (atr->flag & (1 << (26))))
		atr->number = 0;
	ft_decimal_logic(atr);
	if ((atr->flag & (1 << (26))) && (a == 0))
		return (atr->symbol);
	ft_putstr(str);
	free(str);
	if ((atr->flag & (1 << (25))) && (atr->flag & (1 << (2))) \
			&& (atr->width > 0))
		atr->symbol = atr->symbol + ft_putchar_symbol(' ', atr->width);
	return (atr->number + atr->symbol);
}
