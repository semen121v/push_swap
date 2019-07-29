/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:46:35 by fshade            #+#    #+#             */
/*   Updated: 2019/07/27 21:52:21 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	znak;
	int	nbr;

	znak = 1;
	nbr = 0;
	if (!(ft_strcmp("-2147483648", str)))
		return (-2147483648);
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		znak = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if (nbr * 10 / 10 != nbr || nbr * 10 + *str - '0' < 0)
		{
			if (znak == 1)
				return (-1);
			return (0);
		}
		nbr = nbr * 10 + *str - '0';
		str++;
	}
	return ((int)nbr * znak);
}
