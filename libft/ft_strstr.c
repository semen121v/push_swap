/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschoen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 18:01:13 by eschoen           #+#    #+#             */
/*   Updated: 2018/12/29 19:20:20 by eschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION = The strstr() function locates the first occurrence of the
** null-terminated string needle in the null-terminated string haystack.
** If needle is an empty string, haystack is returned; if needle occurs
** nowhere in haystack, NULL is returned; otherwise a pointer to the first
** character of the first occurrence of needle is returned.
** RETURN VALUES = If needle is an empty string, haystack is returned;
** if needle occurs nowhere in haystack, NULL is returned; otherwise a pointer
** to the first character of the first occurrence of needle is returned.
*/

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char *s1;
	char *s2;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		s1 = (char *)haystack;
		s2 = (char *)needle;
		while (*s2 && *s1 == *s2)
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
