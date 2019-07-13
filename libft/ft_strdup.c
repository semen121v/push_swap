/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschoen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:01:21 by eschoen           #+#    #+#             */
/*   Updated: 2019/02/05 11:05:57 by eschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION = The strdup() function allocates sufficient memory for a copy
** of the string s1, does the copy, and returns a pointer to it.
** strcpy works with already exists memory, but strdup need new memory.
*/

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *s2;

	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (s2 == NULL)
		return (NULL);
	ft_strcpy(s2, s1);
	return (s2);
}
