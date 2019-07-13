/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschoen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 20:46:57 by eschoen           #+#    #+#             */
/*   Updated: 2018/12/29 20:18:04 by eschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description = Allocates (with malloc(3)) and returns a copy of the string
** given as argument without whitespaces at the beginning or at the end of the
** string. Will be considered as whitespaces the following characters ’ ’,
** ’\n’ and ’\t’. If s has no whitespaces at the beginning or at the end,
** the function returns a copy of s. If the allocation fails the function
** returns NULL.
** Param. #1 = The string to be trimed.
** Return value = The “fresh” trimmed string or a copy of s.
*/

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*newstr;
	int		start;
	int		end;

	if (s != NULL)
	{
		start = 0;
		end = ft_strlen(s);
		while (ft_isspace(s[start]))
			start++;
		while (ft_isspace(s[end - 1]))
			end--;
		if (end < start)
			end = start;
		newstr = ft_strnew(end - start);
		if (newstr == NULL)
			return (NULL);
		return (ft_strncpy(newstr, s + start, end - start));
	}
	return (NULL);
}
