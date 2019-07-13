/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschoen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 13:06:36 by eschoen           #+#    #+#             */
/*   Updated: 2018/12/29 19:03:20 by eschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION = The strncpy() functions copy at most len characters from src
** into dst. If src is less than len characters long, the remainder of dst is
** filled with `\0' characters. Otherwise, dst is not terminated.
** RETURN VALUES = The strcpy() and strncpy() functions return dst.
** The stpcpy() and stpncpy() functions return a pointer to the terminating
** `\0' character of dst.  If stpncpy() does not terminate dst with a NUL
** character, it instead returns a pointer to dst[n] (which does not
** necessarily refer to a valid memory location.)
*/

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while (src[i] != '\0' && (i < len))
	{
		dst[i] = src[i];
		i++;
	}
	while (i < len)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
