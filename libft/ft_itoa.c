/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschoen <eschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 16:46:34 by eschoen           #+#    #+#             */
/*   Updated: 2019/04/04 14:07:03 by eschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description = Allocate (with malloc(3)) and returns a “fresh” string ending
** with ’\0’ representing the integer n given as argument. Negative numbers
** must be supported. If the allocation fails, the function returns NULL.
** Param. #1 = The integer to be transformed into a string.
** Return value = The string representing the integer passed as argument.
*/

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	char	neg;
	long	v;
	int		count;

	v = n;
	neg = (v < 0 ? 1 : 0);
	count = ft_countdigit(v);
	str = ft_strnew(count + neg);
	if (str == NULL)
		return (NULL);
	if (neg == 1)
	{
		v = -v;
		str[0] = '-';
	}
	while (count > 0)
	{
		str[count + neg - 1] = (v % 10) + '0';
		count--;
		v = v / 10;
	}
	return (str);
}
