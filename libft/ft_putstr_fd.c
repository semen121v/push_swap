/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschoen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 17:40:10 by eschoen           #+#    #+#             */
/*   Updated: 2018/12/29 18:43:24 by eschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description = Outputs the string s to the file descriptor fd.
** Param. #1 = The string to output.
** Param. #2 = The file descriptor.
** Return value = None.
*/

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	if (s != NULL && fd >= 0)
		write(fd, s, ft_strlen(s));
}
