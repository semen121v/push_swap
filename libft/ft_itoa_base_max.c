/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_max.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschoen <eschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 20:48:31 by eschoen           #+#    #+#             */
/*   Updated: 2019/05/27 20:48:32 by eschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base_max(intmax_t value, int base)
{
	char	*buff;
	char	*digits;
	int		len;
	int		minus;

	if (base < 2 || base > 16)
		return (NULL);
	minus = (value < 0 && base == 10) ? 1 : 0;
	value *= (value < 0) ? (-1) : 1;
	len = ft_numlen_max(value, base) + minus;
	if (!(buff = ft_strnew(len)))
		return (NULL);
	digits = "0123456789ABCDEF";
	while (len--)
	{
		buff[len] = digits[value % base];
		value /= base;
	}
	if (minus)
		buff[0] = '-';
	return (buff);
}
