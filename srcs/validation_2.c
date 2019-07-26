/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 18:14:30 by fshade            #+#    #+#             */
/*   Updated: 2019/07/26 20:55:07 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void        free_function(char **stack)
{
    int     i;

    i = 0;
    while (stack[i] != 0)
    {
        free(stack[i]);
        i++;
    }
    free(stack);
    return ;
}

static int	copy_stacks_2(char **av, int i)
{
	int		*num;
	int		j;
	int		k;

	j = 0;
	k = 1;
	if (i == 1)
	{
		av = ft_strsplit(av[j + 1], ' ');	
		i = mas_len(av);
		k = 0;
	}
	num = (int*)malloc(sizeof(int) * i);
	while (j != i)
	{
		num[j] = ft_atoi(av[j + k]);
        if (ft_strcmp(ft_itoa(num[j]), av[j + k]))
            return (1);
		j++;
	}
    if (i == 1)
        free_function(av);
	quicksort(num, 0, i - 1);
	if (check_mas(num, i) == 0)
		return (1);
	return (0);
}

int			copy_stacks(char **av, int i)
{
	char	**num;
	int		j;
	int		k;
    int     m;

	j = 0;
	k = 1;
	while (j != i)
	{
		num = ft_strsplit(av[j + 1], ' ');	
		m = mas_len(num);
        free_function(num);
		j++;
        if (m > 1)
            k++;
	}
	if (k > 1 && i > 1)
        return (1);
    if (copy_stacks_2(av, i) == 1)
        return (1);
    return (0);
}