/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschoen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 15:49:07 by eschoen           #+#    #+#             */
/*   Updated: 2018/12/29 16:47:44 by eschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	int i;

	if (s != NULL)
	{
		i = 0;
		if (s[i] != '\0')
			while (s[i] != '\0')
			{
				write(1, &s[i], 1);
				i++;
			}
	}
}
