/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschoen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 18:39:12 by eschoen           #+#    #+#             */
/*   Updated: 2018/12/29 18:15:27 by eschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION = The memccpy() function copies bytes from string src to string
** dst. If the character c (as converted to an unsigned char) occurs in the
** string src, the copy stops and a pointer to the byte after the copy of c in
** the string dst is returned. Otherwise, n bytes are copied, and a NULL pointer
** is returned.
*/

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
		if (((unsigned char *)dst)[i - 1] == (unsigned char)c)
			return (&((unsigned char *)dst)[i]);
	}
	return (NULL);
}
