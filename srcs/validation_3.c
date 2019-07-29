/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 21:20:28 by fshade            #+#    #+#             */
/*   Updated: 2019/07/27 22:42:39 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		return_func(int *mas, char **av, int f)
{
	if (f == 1)
		free_function(av);
	free(mas);
	return (1);
}

int		free_function_1(char **stack)
{
	int	i;

	i = 0;
	while (stack[i] != 0)
	{
		free(stack[i]);
		i++;
	}
	free(stack);
	return (1);
}
