/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschoen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 20:00:55 by eschoen           #+#    #+#             */
/*   Updated: 2018/12/29 19:37:32 by eschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description = Allocates (with malloc(3)) and returns a “fresh” memory area.
** The memory allocated is initialized to 0. If the allocation fails, the
** function returns NULL.
** Param #1 = The size of the memory that needs to be allocated.
** Return value = The allocated memory area.
*/

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, size);
	return (ptr);
}
