/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschoen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 20:22:15 by eschoen           #+#    #+#             */
/*   Updated: 2018/12/29 19:49:33 by eschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description = Applies the function f to each character of the string passed
** as argument, and passing its index as first argument. Each character is
** passed by address to f to be modified if necessary.
** Param. #1 = The string to iterate.
** Param. #2 =  The function to apply to each character of s and its index.
** Return value = None.
*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int i;

	if (s != NULL && f != NULL)
	{
		i = 0;
		while (s[i] != '\0')
		{
			(*f)(i, &s[i]);
			i++;
		}
	}
}
