/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschoen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 17:45:41 by eschoen           #+#    #+#             */
/*   Updated: 2018/12/29 19:16:51 by eschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION = The strrchr() function is identical to strchr(), except it
** locates the last occurrence of c. The trrchr() return a pointer to the
** located character, or NULL if the character does not appear in the string
** RETURN VALUES = The functions strchr() and strrchr() return a pointer to the
** located character, or NULL if the character does not appear in the string.
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
		i--;
	}
	return (NULL);
}
