/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 20:08:16 by fshade            #+#    #+#             */
/*   Updated: 2019/07/13 19:57:36 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted(t_frame *stacks)
{
	t_clist		*tmp;

	if (!stacks->a || (stacks->b))
		return (0);
	tmp = stacks->a;
	while (tmp != stacks->a->prev)
	{
		if (tmp->data >= tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void		quicksort(int *numbers, int left, int right)
{
	int		pivot; // разрешающий элемент
	int		l_hold; //левая граница
	int		r_hold; // правая граница

	l_hold = left;
	r_hold = right;
	pivot = numbers[left];
	while (left < right) // пока границы не сомкнутся
	{
		while ((numbers[right] >= pivot) && (left < right))
			right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
		if (left != right) // если границы не сомкнулись
		{
			numbers[left] = numbers[right]; // перемещаем элемент [right] на место разрешающего
			left++; // сдвигаем левую границу вправо
		}
		while ((numbers[left] <= pivot) && (left < right))
			left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
		if (left != right) // если границы не сомкнулись
		{
			numbers[right] = numbers[left]; // перемещаем элемент [left] на место [right]
			right--; // сдвигаем правую границу вправо
		}
	}
	numbers[left] = pivot; // ставим разрешающий элемент на место
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
		quicksort(numbers, left, pivot - 1);
	if (right > pivot)
		quicksort(numbers, pivot + 1, right);
	return ;
}
