/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschoen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 20:33:27 by eschoen           #+#    #+#             */
/*   Updated: 2018/12/29 19:59:34 by eschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description = Lexicographical comparison between s1 and s2. If the 2 strings
** are identical the function returns 1, or 0 otherwise.
** Param. #1 = The first string to be compared.
** Param. #2 = The second string to be compared.
** Return value = 1 or 0 according to if the 2 strings are identical or not.
*/

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	if (s1 != NULL && s2 != NULL)
		return (ft_strnequ(s1, s2, ft_maximum(ft_strlen(s1), ft_strlen(s2))));
	return (0);
}
