/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschoen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 09:58:32 by eschoen           #+#    #+#             */
/*   Updated: 2018/12/29 18:30:22 by eschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description = Outputs the string s to the standard output followed by a ’\n’.
** Param. #1 = The string to output.
** Return value = None.
*/

#include "libft.h"

void	ft_putendl(char const *s)
{
	if (s != NULL)
	{
		ft_putstr(s);
		ft_putchar('\n');
	}
}
