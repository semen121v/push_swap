/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:59:21 by fshade            #+#    #+#             */
/*   Updated: 2018/12/11 19:02:13 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*string;
	int		src_size;
	char	*src;

	src = (char*)s1;
	i = 0;
	src_size = 0;
	src_size = ft_strlen(s1);
	string = (char*)malloc(sizeof(char) * (src_size + 1));
	if (!string)
		return (NULL);
	while (i < src_size)
	{
		string[i] = src[i];
		i++;
	}
	string[src_size] = '\0';
	return (string);
}
