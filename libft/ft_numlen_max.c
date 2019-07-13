/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschoen <eschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 20:51:06 by eschoen           #+#    #+#             */
/*   Updated: 2019/05/27 20:51:29 by eschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Возвращает длину числа с дополнительным пробелом для ' - ' для
** отрицательных чисел.
*/

#include "libft.h"

int		ft_numlen_max(intmax_t nb, int base)
{
	int	len;

	if (base < 2)
		return (0);
	len = (nb < 0) ? 2 : 1;
	while ((nb /= base))
		len++;
	return (len);
}