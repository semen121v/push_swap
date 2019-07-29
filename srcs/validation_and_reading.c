/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_and_reading.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 20:42:43 by eschoen           #+#    #+#             */
/*   Updated: 2019/07/27 22:29:50 by fshade           ###   ########.fr       */
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
		{
			free(num);
			return (0);
		}
		i++;
	}
	free(num);
	return (1);
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
	int		f;

	stacks->a = NULL;
	f = 0;
	if (argc - 1 == 1)
	{
		argv = ft_strsplit(argv[1], ' ');
		argc = mas_len(argv);
		i = 0;
		f = 1;
	}
	while (i != argc)
	{
		tmp = ft_atoi(argv[i]);
		if (!stacks->a)
			stacks->a = create_clist(tmp, stacks);
		else
			add_to_tail(stacks->a, tmp, stacks);
		i++;
	}
	if (f == 1)
		free_function(argv);
}

int			valid_item(int ac, char **av)
{
	if ((copy_stacks(av, ac - 1)) == 1)
		return (1);
	return (0);
}
