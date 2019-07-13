/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschoen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:47:06 by eschoen           #+#    #+#             */
/*   Updated: 2018/12/29 19:29:48 by eschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION = The strcmp() and strncmp() functions lexicographically compare
** the null-terminated strings s1 and s2.
** RETURN VALUES = The strcmp() function return an
** integer greater than, equal to, or less than 0, according as the string s1
** is greater than, equal to, or less than the string s2.
** The comparison is done using unsigned characters, so that `\200' is
** greater than `\0'.
*/

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
