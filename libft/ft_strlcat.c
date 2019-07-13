/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschoen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 13:58:17 by eschoen           #+#    #+#             */
/*   Updated: 2018/12/29 19:11:03 by eschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION = The strlcat() function returns the total length of strings at
** src and dst addresses. The return value does not depend on whether the
** string was concat completely or not.
** Size is destination buffer size.
** RETURN VALUES = For strlcat() that means the initial length of dst plus the
** length of src.  While this may seem somewhat confusing, it was done to
** make truncation detection simple.
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (dst[i] != '\0' && i < size)
		i++;
	while (src[j] != '\0' && (i + j + 1) < size)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < size)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
