/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschoen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 13:09:26 by eschoen           #+#    #+#             */
/*   Updated: 2019/02/05 11:07:08 by eschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION = The stpcpy() and strcpy() functions copy the string src to dst
** (including the terminating `\0' character.)
** RETURN VALUES = The strcpy() and strncpy() functions return dst. The stpcpy
** and stpncpy() functions return a pointer to the terminating `\0' character
** of dst. If stpncpy() does not terminate dst with a NUL character, it
** instead returns a pointer to dst[n] (which does not necessarily refer to
** a valid memory location.)
*/

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = src[i];
	return (dst);
}
