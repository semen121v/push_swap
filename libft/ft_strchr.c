/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschoen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 17:22:09 by eschoen           #+#    #+#             */
/*   Updated: 2018/12/29 19:15:00 by eschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION = The strchr() function locates the first occurrence of c
** (converted to a char) in the string pointed to by s. The terminating null
** character is considered to be part of the string; therefore if c is `\0',
** the functions locate the terminating `\0'.
** RETURN VALUES = The functions strchr() and strrchr() return a pointer to
** the located character, or NULL if the character does not appear in the
** string.
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&((char *)s)[i]);
	return (NULL);
}
