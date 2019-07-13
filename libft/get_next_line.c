/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschoen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 16:29:29 by eschoen           #+#    #+#             */
/*   Updated: 2019/02/05 10:51:28 by eschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** GNL is a function that returns a line read from a file descriptor.
** The first parameter is the file descriptor that will be used to read.
** The second parameter is the address of a pointer to a character that will be
** used to save the line read from the file descriptor.
** The function get_next_line must return its result without ’\n’.
** The return value can be 1, 0 or -1 depending on whether a line has been read,
** when the reading has been completed, or if an error happened respectively.
** The function get_next_line must return its result without ’\n’.
*/

#include "libft.h"

static int		check_read_line_gnl(char **stack, char **line)
{
	char		*tmp_stack;
	char		*strend_stack;
	int			i;

	i = 0;
	strend_stack = *stack;
	while (strend_stack[i] != '\n')
		if (strend_stack[i++] == '\0')
			return (0);
	tmp_stack = &strend_stack[i];
	*tmp_stack = '\0';
	*line = ft_strdup(*stack);
	*stack = ft_strdup(tmp_stack + 1);
	free(strend_stack);
	strend_stack = NULL;
	return (1);
}

static int		read_file_gnl(int fd, char *heap, char **stack, char **line)
{
	int			gnl_return;
	char		*temp_stack;

	while ((gnl_return = read(fd, heap, BUFF_SIZE)) > 0)
	{
		heap[gnl_return] = '\0';
		if (*stack != NULL)
		{
			temp_stack = *stack;
			*stack = ft_strjoin(temp_stack, heap);
			free(temp_stack);
			temp_stack = NULL;
		}
		else
			*stack = ft_strdup(heap);
		if (check_read_line_gnl(stack, line) == 1)
			break ;
	}
	return (gnl_return > 0 ? 1 : gnl_return);
}

int				get_next_line(const int fd, char **line)
{
	int			i;
	int			gnl_return;
	char		*heap;
	static char	*stack[MAX_FD];

	if (line == NULL || (fd < 0 || fd >= MAX_FD) || (read(fd, stack[fd], 0) < 0)
			|| !(heap = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	if (stack[fd] != NULL)
		if (check_read_line_gnl(&stack[fd], line) == 1)
			return (1);
	i = 0;
	while (i < BUFF_SIZE)
		heap[i++] = '\0';
	gnl_return = read_file_gnl(fd, heap, &stack[fd], line);
	free(heap);
	if (gnl_return != 0 || stack[fd] == NULL || stack[fd][0] == '\0')
	{
		if (gnl_return == 0 && *line != NULL)
			*line = NULL;
		return (gnl_return);
	}
	*line = stack[fd];
	stack[fd] = NULL;
	return (1);
}
