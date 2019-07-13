/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 22:15:43 by fshade            #+#    #+#             */
/*   Updated: 2019/05/17 22:40:17 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <limits.h>

void						ft_putchar_calc(char c, t_attrib *atr)
{
	write(1, &c, 1);
	atr->symbol++;
	return ;
}

void						ft_putnbr_ll(long long n, t_attrib *params)
{
	unsigned long long		new;

	new = (n > 0) ? n : -n;
	if (new < 10)
		ft_putchar_calc(new + 48, params);
	else
	{
		ft_putnbr_ll(new / 10, params);
		ft_putchar_calc(new % 10 + 48, params);
	}
}

static unsigned long long	ft_pow(unsigned long long a, unsigned int power)
{
	unsigned long long		mem;

	mem = a;
	if (power == 0)
		return (1);
	while (--power)
		a *= mem;
	return (a);
}

void						ft_putfloat(long double x, int precision, \
						int flag_diese, t_attrib *atr)
{
	int						i;

	if (precision == 0)
	{
		if (x - (long long)x > 0.5)
			x++;
		ft_putnbr_ll((long long)x, atr);
		if (flag_diese)
			ft_putchar_calc('.', atr);
		return ;
	}
	ft_putnbr_ll((long long)x, atr);
	ft_putchar_calc('.', atr);
	x -= (long long)x;
	i = 0;
	if ((long long)(x * (long double)ft_pow(10, precision + 1)) % 10 > 5)
		x += 1 / (long double)ft_pow(10, precision);
	while (i < precision)
	{
		x *= 10;
		ft_putnbr_ll((long long)x, atr);
		x -= (long long)x;
		i++;
	}
}
