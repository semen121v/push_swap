/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschoen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 15:58:07 by eschoen           #+#    #+#             */
/*   Updated: 2019/01/26 16:24:35 by eschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description = Allocates (with malloc(3)) and returns an array of “fresh”
** strings (all ending with ’\0’, including the array itself) obtained by
** spliting s using the character c as a delimiter. If the allocation fails the
** function returns NULL. Example : ft_strsplit("*hello*fellow***students*",
** ’*’) returns the array ["hello", "fellow", "students"]
** Param. #1 = The string to split.
** Param. #2 = The delimiter character.
** Return value = The array of “fresh” strings result of the split.
*/

#include "libft.h"

static void		cleanup(char **splitted, int position)
{
	while (position > 0)
	{
		position--;
		ft_strdel(&splitted[position]);
	}
	ft_strdel(splitted);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**splitted;
	int		position;
	int		charqty;

	if (s == NULL)
		return (NULL);
	charqty = ft_charinwordcalc((char *)s, c);
	splitted = (char **)ft_memalloc((charqty + 1) * sizeof(char *));
	if (splitted == NULL)
		return (NULL);
	position = 0;
	while (position < charqty)
	{
		s = ft_wordnext(s, c);
		splitted[position] = ft_strsub(s, 0, ft_wordlen(s, c));
		if (splitted[position] == NULL)
		{
			cleanup(splitted, position);
			return (NULL);
		}
		position++;
		s = s + ft_wordlen(s, c);
	}
	splitted[charqty] = NULL;
	return (splitted);
}
