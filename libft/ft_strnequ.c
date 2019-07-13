/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschoen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 20:39:47 by eschoen           #+#    #+#             */
/*   Updated: 2018/12/29 16:34:32 by eschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description = Lexicographical comparison between s1 and s2 up to n characters
** or until a ’\0’ is reached. If the 2 strings are identical, the function
** returns 1, or 0 otherwise.
** Param. #1 = The first string to be compared.
** Param. #2 = The second string to be compared.
** Param. #3 = The maximum number of characters to be compared.
** Return value = 1 or 0 according to if the 2 strings are identical or not.
*/

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 != NULL && s2 != NULL)
		return (ft_strncmp(s1, s2, n) == 0 ? 1 : 0);
	return (0);
}
