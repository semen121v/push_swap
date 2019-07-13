/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschoen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 20:04:52 by eschoen           #+#    #+#             */
/*   Updated: 2018/12/29 19:38:08 by eschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description = Takes as a parameter the address of a memory area that needs
** to be freed with free(3), then puts the pointer to NULL.
** Param. #1 = A pointer’s address that needs its memory freed and set to NULL.
** Return value = None.
*/

#include "libft.h"

void	ft_memdel(void **ap)
{
	if (ap != NULL)
	{
		free(*ap);
		*ap = (NULL);
	}
}
