/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_and_reading.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 20:42:43 by eschoen           #+#    #+#             */
/*   Updated: 2019/07/26 16:51:41 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_mas(int *num, int s)
{
	int		i;

	i = 0;
	while (i != s - 1)
	{
		if (num[i] == num[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int			copy_stacks(char **av, int i)
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
		j++;
	}
	quicksort(num, 0, i - 1);
	if (check_mas(num, i) == 0)
	{
		free(num);
		return (1);
	}
	return (0);
}

void		add_to_tail(t_clist *head, int data, t_frame *stacks)
{
	t_clist	*new;

	if (!(new = (t_clist*)malloc(sizeof(*new))))
		failed_exit(stacks);
	new->data = data;
	new->next = head;
	new->next1 = NULL;
	head->prev->next1 = new;
	new->prev = (head->next == head) ? head : head->prev;
	head->prev = new;
	new->prev->next = new;
}

void		read_num(int argc, char **argv, int i, t_frame *stacks)
{
	int		tmp;

	stacks->a = NULL;
	while (i != argc)
	{
		tmp = ft_atoi(argv[i]);
		if (!stacks->a)
			stacks->a = create_clist(tmp, stacks);
		else
			add_to_tail(stacks->a, tmp, stacks);
		i++;
	}
}

int			valid_item(int ac, char **av)
{
	int		i;
	int		j;

	if ((copy_stacks(av, ac - 1)) == 1)
		return (1);
	i = 0;
	while (++i != ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9') && av[i][j] != '+' \
				&& av[i][j] != '-' && av[i][j + 1] == '-' && av[i][j + 1] == '+')
				return (1);
			j++;
		}
	}
	return (0);
}
