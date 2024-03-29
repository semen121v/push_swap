/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 20:37:29 by eschoen           #+#    #+#             */
/*   Updated: 2019/07/27 22:12:59 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "ft_printf.h"

# define ASC 1
# define DESC -1

typedef struct	s_clist
{
	int				data;
	struct s_clist	*next;
	struct s_clist	*next1;
	struct s_clist	*prev;
}				t_clist;

typedef struct	s_frame
{
	t_clist	*a;
	t_clist	*b;
	int		print;
	int		push;
	t_clist *tale_a;
}				t_frame;

void			read_num(int argc, char **argv, int i, t_frame *stacks);
int				copy_stacks(char **av, int i);
int				valid_item(int ac, char **av);
int				count_list(t_clist *stack);
int				prepare(t_frame *stacks);
int				is_sorted(t_frame *stacks);
int				print_usage(void);
int				get_median(t_clist *stacks, int size);
int				ft_check_stack(t_clist *stack, int pivot, int size, int direct);
int				ft_is_sort_size(t_clist *stack, int size, int direct);
int				ft_get_min(t_clist *stack);
int				ft_get_max(t_clist *stack);
int				check_mas(int *num, int s);
int				mas_len(char **av);
int				return_func(int *mas, char **av, int f);
int				free_function_1(char **stack);
t_clist			*create_clist(int data, t_frame *stacks);

void			quicksort(int *numbers, int left, int right);
void			sort_array(int *arr, int end);
void			add_list(t_frame *stacks, int moves);
void			failed_exit(t_frame *stacks);
void			remove_head(t_clist **head);
void			free_stacks(t_frame *stacks);
void			ft_print_ab(t_frame *stacks);
void			ft_sortl(t_frame *stacks);
void			ft_qsort(t_frame *stacks, int size);
void			ft_revrotate_op(t_frame *stacks, char op, int print);
void			ft_push_op(t_frame *stacks, char op, int print);
void			ft_swap_op(t_frame *stacks, char op);
void			ft_sort3(t_frame *stacks, int size);
void			ft_revsort3(t_frame *stacks, int bsize, int print);
void			free_function(char **stack);

void			sa(t_frame *stacks);
void			sb(t_frame *stacks);
void			ss(t_frame *stacks);

void			pa(t_frame *stacks);
void			pb(t_frame *stacks);

void			ra(t_frame *stacks);
void			rb(t_frame *stacks);
void			rr(t_frame *stacks);

void			rra(t_frame *stacks);
void			rrb(t_frame *stacks);
void			rrr(t_frame *stacks);

#endif
