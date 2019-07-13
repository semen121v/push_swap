/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 21:08:24 by fshade            #+#    #+#             */
/*   Updated: 2019/05/17 23:49:17 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <limits.h>

int					pad_double(t_attrib *atr, int *buff_pad)
{
	if (*buff_pad && (atr->flag & (1 << (1))) && !(atr->flag & (1 << (2))))
		while ((*buff_pad)-- > 0)
			ft_putchar_calc('0', atr);
	else if (*buff_pad > 0)
		while ((*buff_pad)-- > 0)
			ft_putchar_calc(' ', atr);
	return (0);
}

int					space_signe_double(t_attrib *atr, long double num)
{
	if (num < 0)
		ft_putchar_calc('-', atr);
	else if (atr->flag & (1 << (3)))
		ft_putchar_calc('+', atr);
	else if (atr->flag & (1 << (4)))
		ft_putchar_calc(' ', atr);
	return (0);
}

static int			len_double(long double num)
{
	int				i;

	i = 1;
	while ((num /= 10) >= 1)
		i++;
	return (i);
}

static int			print_double(t_attrib *atr, long double num, int len)
{
	static int		buff_pad;

	len = len_double(num);
	if (!(atr->flag & ((1 << (26)))))
		len += 7;
	else if ((atr->flag & (1 << (26))) || (!(atr->flag & ((1 << (26))) \
					&& (atr->flag & ((1 << (0)))))))
		len += atr->accuracy + 1;
	if (atr->width > len)
		buff_pad = atr->width - len - ((atr->flag & (1 << (4)))
				|| (atr->flag & (1 << (3))) || (num < 0));
	if (atr->flag & (1 << (1)))
		space_signe_double(atr, num);
	if (!(atr->flag & (1 << (2))))
		pad_double(atr, &buff_pad);
	if (!(atr->flag & (1 << (1))))
		space_signe_double(atr, num);
	if (num < 0)
		num = num * (-1);
	if ((atr->flag & (1 << (26))))
		ft_putfloat(num, atr->accuracy, (atr->flag & (1 << (0))), atr);
	else
		ft_putfloat(num, 6, (atr->flag & (1 << (0))), atr);
	pad_double(atr, &buff_pad);
	return (0);
}

int					ft_printf_float(va_list arg, t_attrib *atr, int id)
{
	long double		num;
	int				len;

	len = 0;
	num = 0;
	if (id == UPP_F || (atr->flag & (1 << (29))))
	{
		num = va_arg(arg, long double);
		print_double(atr, num, len);
	}
	else
		print_double(atr, va_arg(arg, double), len);
	return (atr->symbol);
}
