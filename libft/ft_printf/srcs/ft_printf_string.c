/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:42:32 by eschoen           #+#    #+#             */
/*   Updated: 2019/05/14 20:32:17 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		free_func(t_attrib *attr, char *str, char *cpy)
{
	if (attr->flag & (1 << 26))
		free(cpy);
	if (attr->check == 1)
		free(str);
	return ;
}

int			print_string(va_list ap, t_attrib *attr)
{
	int		len;
	char	*str;
	char	*cpy;

	cpy = NULL;
	if (!(str = va_arg(ap, char *)))
	{
		str = ft_strdup("(null)");
		attr->check = 1;
	}
	if (attr->flag & (1 << 26))
	{
		if (!(cpy = ft_strnew(attr->accuracy)))
			return (0);
		cpy = ft_strncpy(cpy, str, attr->accuracy);
		str = cpy;
	}
	len = ft_strlen(str);
	if (!(attr->flag & (1 << 2)))
		len = print_spaces(attr->width, len, attr->flag);
	ft_putstr(str);
	free_func(attr, str, cpy);
	if (attr->flag & (1 << 2))
		len = print_spaces(attr->width, len, attr->flag);
	return (len);
}

/*
** Печать символов.
*/

int			print_character(va_list ap, t_attrib *attr)
{
	int		len;
	char	c;

	c = va_arg(ap, int);
	len = sizeof(char);
	if (!(attr->flag & (1 << 2)))
		len = print_spaces(attr->width, len, attr->flag);
	ft_putchar(c);
	if (attr->flag & (1 << 2))
		len = print_spaces(attr->width, len, attr->flag);
	return (len);
}
