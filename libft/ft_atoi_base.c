/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschoen <eschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 10:42:46 by eschoen           #+#    #+#             */
/*   Updated: 2019/04/03 19:05:37 by eschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Проверяет присутствует ли этот символ в выбранной системе счисления
*/

static int			ft_is_allowed_symbol(char c, int base)
{
	const char		*digits = "0123456789ABCDEF";
	int				i;

	i = 0;
	while (i < base)
	{
		if (digits[i] == ft_toupper(c))
			return (i);
		i++;
	}
	return (-1);
}

/*
** Проверяет содержит ли эта строка префикс своей числовой системы
*/

static int			ft_has_prefix(const char *str, int base)
{
	size_t			i;

	i = 0;
	if (base == 2 || base == 8 || base == 16)
	{
		if (str[i++] != '0')
			return (0);
		if (base == 2 && (str[i] == 'b' || str[i] == 'B'))
			return (1);
		if (base == 16 && (str[i] == 'x' || str[i] == 'X'))
			return (1);
		if (base == 8)
			return (1);
	}
	return (0);
}

/*
** Преобразовывает строку в число в соответствии с выбранной системой счисления
*/

int					ft_atoi_base(const char *str, int base)
{
	unsigned long	result;
	size_t			i;
	int				sign;

	result = 0;
	i = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (base != 10 && ft_has_prefix(&str[i], base) == 0)
		return (0);
	if (base == 2 || base == 16)
		i += 2;
	else if (base == 8)
		i++;
	else if (base == 10 && (str[i] == '-' || str[i] == '+'))
		sign = (str[i++] == '-') ? -1 : 1;
	while (ft_is_allowed_symbol(str[i], base) >= 0)
		result = result * base + ft_is_allowed_symbol(str[i++], base);
	return ((int)(result * sign));
}
