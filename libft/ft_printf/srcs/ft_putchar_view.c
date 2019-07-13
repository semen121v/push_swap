/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_view.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:45:26 by fshade            #+#    #+#             */
/*   Updated: 2019/05/15 22:11:03 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long long int		ft_size_special(t_attrib *atr, va_list argument)
{
	long long int	a;

	if (atr->flag & (1 << (22)))
		a = (long long int)va_arg(argument, long int);
	else if (atr->flag & (1 << (21)))
		a = (long long int)va_arg(argument, long long int);
	else if (atr->flag & (1 << (20)))
		a = (long long int)(short)va_arg(argument, int);
	else if (atr->flag & (1 << (19)))
		a = (long long int)(char)va_arg(argument, int);
	else
		a = (long long int)va_arg(argument, int);
	return (a);
}

int					ft_putchar_symbol(char c, int x)
{
	int				i;

	i = x;
	while (x-- > 0)
		ft_putchar(c);
	return (i);
}

void				ft_special_zero(t_attrib *atr, int i)
{
	if (!(atr->flag & (1 << (1))))
		return ;
	if (!(atr->flag & (1 << (25))))
		return ;
	if (atr->flag & (1 << (26)))
		return ;
	if (atr->flag & (1 << (2)))
		return ;
	if ((atr->flag & (1 << (3))) || atr->znak == '-')
	{
		atr->symbol = atr->symbol + ft_putchar_symbol(atr->znak, 1);
		if (atr->flag & (1 << (3)))
			atr->flag -= (1 << (3));
		atr->znak = '\0';
	}
	if (!((atr->flag & (1 << (25))) && !(atr->flag & (1 << (2))) \
				&& (atr->width - i > 0)))
		return ;
	atr->symbol = atr->symbol + ft_putchar_symbol('0', atr->width - i);
	atr->flag -= (1 << (25));
	atr->flag -= (1 << (4));
	return ;
}

int					ft_special_space(t_attrib *atr, int i)
{
	if (atr->flag & (1 << (4)) && !(atr->znak == '-' || \
					(atr->flag & (1 << (3)))))
	{
		i++;
		atr->symbol = atr->symbol + ft_putchar_symbol(' ', 1);
	}
	return (i);
}

int					ft_unsize(unsigned long long int a, t_attrib *atr)
{
	int				i;

	i = 1;
	atr->number = 0;
	while (a >= 16)
	{
		i++;
		a = a / 16;
	}
	if ((atr->flag & (1 << (26))) && a == 0)
		i--;
	atr->number = atr->number + i;
	return (i);
}
