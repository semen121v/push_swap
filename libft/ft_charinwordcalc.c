/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcalc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschoen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 16:23:09 by eschoen           #+#    #+#             */
/*   Updated: 2018/12/29 21:10:51 by eschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_charinwordcalc(char *str, char sep)
{
	int i;
	int qty;

	i = 0;
	qty = 0;
	while (str[i] != '\0' && str[i] == sep)
		i++;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] != sep)
			i++;
		qty++;
		while (str[i] != '\0' && str[i] == sep)
			i++;
	}
	return (qty);
}
