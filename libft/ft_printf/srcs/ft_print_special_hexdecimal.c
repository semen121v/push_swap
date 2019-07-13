/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_special_hexdecimal.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 11:14:00 by semen             #+#    #+#             */
/*   Updated: 2019/05/17 22:47:24 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <limits.h>

static int					conv_ex(int nb, int id)
{
	if (nb >= 10 && id == LOW_X)
		return (nb - 10 + 'a');
	else if (nb >= 10 && id == UPP_X)
		return (nb - 10 + 'A');
	else
		return (nb + '0');
}

static char					*ft_itoa_base(unsigned long long int value,\
								t_attrib *atr, int id)
{
	int						i;
	char					*str;
	unsigned long long int	tmp;

	i = 0;
	tmp = value;
	atr->number = 1;
	while (tmp >= 16)
	{
		tmp = tmp / 16;
		i++;
	}
	atr->number = atr->number + i;
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

static void					ft_decimal_logic(t_attrib *atr, int id,\
								unsigned long long int a)
{
	int						i;

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

int							special_hexdecimal(va_list arg, t_attrib *atr, \
								int id)
{
	unsigned long long int	a;
	char					*str;

	a = (unsigned long long int)(intmax_t)va_arg(arg, intmax_t);
	str = ft_itoa_base(a, atr, id);
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
	return (atr->number + atr->symbol);
}
