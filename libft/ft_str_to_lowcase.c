/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_lowcase.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschoen <eschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:14:28 by eschoen           #+#    #+#             */
/*   Updated: 2019/04/03 19:04:48 by eschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_to_lowcase(char *str)
{
	int		i;

	i = 0;
	while (str[i++] != '\0')
		if (ft_isuppercase(str[i - 1]))
			str[i - 1] = str[i - 1] + 32;
	return (str);
}
