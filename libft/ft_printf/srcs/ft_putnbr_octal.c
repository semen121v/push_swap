/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_octal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:02:37 by fshade            #+#    #+#             */
/*   Updated: 2019/05/17 22:41:27 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_octal(unsigned long long int n)
{
	if (n >= 8)
	{
		ft_putnbr_octal(n / 8);
		ft_putnbr_octal(n % 8);
	}
	else
	{
		ft_putchar(n + '0');
	}
}
