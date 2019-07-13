/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschoen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 20:23:46 by eschoen           #+#    #+#             */
/*   Updated: 2018/12/29 19:52:43 by eschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description = Applies the function f to each character of the string given
** as argument to create a “fresh” new string (with malloc(3)) resulting from
** the successive applications of f.
** Param. #1 = The string to map.
** Param. #2 = The function to apply to each character of s.
** Return value = The “fresh” string created from the successive applications
** of f.
*/

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*newstr;
	int		i;

	if (s != NULL && f != NULL)
	{
		i = 0;
		newstr = ft_strnew(ft_strlen(s));
		if (newstr == NULL)
			return (NULL);
		while (s[i] != '\0')
		{
			newstr[i] = (*f)(s[i]);
			i++;
		}
		return (newstr);
	}
	return (NULL);
}
