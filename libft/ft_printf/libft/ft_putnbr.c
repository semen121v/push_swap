/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semen <semen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 17:50:37 by eschoen           #+#    #+#             */
/*   Updated: 2019/04/23 19:54:01 by semen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description = Outputs the integer n to the standard output.
** Param. #1 = The integer to output.
** Return value = None.
*/

#include "libft.h"

void	ft_putnbr(unsigned long long int n)
{
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		ft_putchar(n + '0');
	}
}
