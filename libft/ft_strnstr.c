/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 18:13:43 by eschoen           #+#    #+#             */
/*   Updated: 2019/07/11 16:32:06 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION = The strnstr() function locates the first occurrence of the
** null-terminated string needle in the string haystack, where not more than
** len characters are searched. Characters that appear after a `\0' character
** are not searched.
** If needle is an empty string, haystack is returned; if needle occurs
** nowhere in haystack, NULL is returned; otherwise a pointer to the first
** character of the first occurrence of needle is returned.
** RETURN VALUES = If needle is an empty string, haystack is returned;
** if needle occurs nowhere in haystack, NULL is returned; otherwise a pointer
** to the first character of the first occurrence of needle is returned.
*/

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (needle[i] == '\0')
		return (&((char *)haystack)[i]);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (haystack[i + j] != '\0' && i + j < len &&
				needle[j] != '\0' && haystack[i + j] == needle[j])
			j++;
		if (needle[j] == '\0')
			return (&((char *)haystack)[i]);
		i++;
	}
	return (NULL);
}
