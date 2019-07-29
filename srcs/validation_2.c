/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 18:14:30 by fshade            #+#    #+#             */
/*   Updated: 2019/07/27 22:43:41 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_atoi_cust(const char *str)
{
	int		znak;
	int		nbr;

	znak = 1;
	nbr = 0;
	if (!(ft_strcmp("-2147483648", str)))
		return (-2147483648);
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		znak = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if (nbr * 10 / 10 != nbr || nbr * 10 + *str - '0' < 0)
			return (0);
		nbr = nbr * 10 + *str - '0';
		str++;
	}
	if (nbr == 0)
		nbr = 1;
	return ((int)nbr * znak);
}

void		free_function(char **stack)
{
	int		i;

	i = 0;
	while (stack[i] != 0)
	{
		free(stack[i]);
		i++;
	}
	free(stack);
	return ;
}

int			check_string(int a, char *str)
{
	char	*newstr;
	int		f;

	f = ft_atoi_cust(str);
	if (f == 0 && (*(short *)str != 12288))
	{
		return (1);
	}
	newstr = ft_itoa(a);
	if (ft_strcmp(newstr, str))
	{
		free(newstr);
		return (1);
	}
	free(newstr);
	return (0);
}

static int	copy_stacks_2(char **av, int i, int f, int k)
{
	int		*num;
	int		j;

	j = -1;
	if (i == 1 && !(k = 0))
	{
		av = ft_strsplit(av[1], ' ');
		i = mas_len(av);
		f = 1;
	}
	if (i == 0)
		return (free_function_1(av));
	num = (int*)malloc(sizeof(int) * i);
	while (++j != i)
	{
		num[j] = ft_atoi(av[j + k]);
		if ((check_string(num[j], av[j + k])) == 1)
			return (return_func(num, av, f));
	}
	if (f == 1)
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
	int		m;

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
	if (copy_stacks_2(av, i, 0, 1) == 1)
		return (1);
	return (0);
}
