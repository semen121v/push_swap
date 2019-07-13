/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschoen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 20:41:44 by eschoen           #+#    #+#             */
/*   Updated: 2018/12/29 20:02:58 by eschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description = Allocates (with malloc(3)) and returns a “fresh” substring from
** the string given as argument. The substring begins at indexstart and is of
** size len. If start and len aren’t refering to a valid substring, the
** behavior is undefined. If the allocation fails, the function returns NULL.
** Param. #1 = The string from which create the substring.
** Param. #2 = The start index of the substring.
** Param. #3 = The size of the substring.
** Return value = The substring.
*/

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*newstr;
	size_t		i;

	if (s != NULL)
	{
		i = 0;
		newstr = ft_strnew(len);
		if (newstr == NULL)
			return (NULL);
		while (i < len)
		{
			newstr[i] = s[start + i];
			i++;
		}
		return (newstr);
	}
	return (NULL);
}
