/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschoen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 20:44:25 by eschoen           #+#    #+#             */
/*   Updated: 2019/02/05 11:08:18 by eschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description = Allocates (with malloc(3)) and returns a “fresh” string ending
** with ’\0’, result of the concatenation of s1 and s2. If the allocation fails
** the function returns NULL.
** Param. #1 = The prefix string.
** Param. #2 = The suffix string.
** Return value = The “fresh” string result of the concatenation of the 2
** strings.
*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *str;

	if (s1 != NULL && s2 != NULL)
	{
		str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (str == NULL)
			return (NULL);
		ft_strcpy(str, s1);
		ft_strcat(str, s2);
		return (str);
	}
	return (NULL);
}
