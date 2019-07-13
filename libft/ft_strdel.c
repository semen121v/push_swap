/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschoen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 20:10:59 by eschoen           #+#    #+#             */
/*   Updated: 2018/12/29 19:41:41 by eschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description = Takes as a parameter the address of a string that need to be
** freed with free(3), then sets its pointer to NULL.
** Param. #1 = The string’s address that needs to be freed and its pointer set
** to NULL.
** Return value = None.
*/

#include "libft.h"

void	ft_strdel(char **as)
{
	if (as != NULL)
		ft_memdel((void **)as);
}
