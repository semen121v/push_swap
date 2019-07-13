/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschoen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 11:29:51 by eschoen           #+#    #+#             */
/*   Updated: 2018/12/29 19:31:33 by eschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION = The strncmp() function compares not more than n characters.
** Because strncmp() is designed for comparing strings rather than binary data,
** characters that appear after a `\0' character are not compared.
** RETURN VALUES = The strncmp() functions return an integer greater than,
** equal to, or less than 0, according as the string s1 is greater than,
** equal to, or less than the string s2.  The comparison is done using
** unsigned characters, so that `\200' is greater than `\0'.
*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int i;

	i = 0;
	while (n > 0)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		else if (s1[i] == '\0')
			return (0);
		i++;
		n--;
	}
	return (0);
}
