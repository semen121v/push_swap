/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 15:52:54 by fshade            #+#    #+#             */
/*   Updated: 2018/12/12 16:13:41 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*newstr;

	if (!s)
		return (NULL);
	newstr = (char*)malloc(sizeof(char) * (len + 1));
	if (newstr == NULL)
		return (NULL);
	i = 0;
	while (len != 0)
	{
		newstr[i] = s[start + i];
		i++;
		len--;
	}
	newstr[i] = '\0';
	return (newstr);
}
