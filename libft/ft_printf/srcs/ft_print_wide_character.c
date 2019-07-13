/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_wide_character.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 16:58:54 by fshade            #+#    #+#             */
/*   Updated: 2019/05/06 18:54:59 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "wchar.h"

static int		check_bytes(char *mas, wchar_t c)
{
	int			bytes;

	bytes = 0;
	if (++bytes && c <= 0x7F)
		mas[0] = c;
	else if (++bytes && c <= 0x7FF)
	{
		mas[0] = 0xC0 | (c >> 6);
		mas[1] = 0x80 | (c & 0x3F);
	}
	else if (++bytes && c <= 0xFFFF)
	{
		mas[0] = 0xE0 | (c >> 12);
		mas[1] = 0x80 | ((c >> 6) & 0x3F);
		mas[2] = 0x80 | (c & 0x3F);
	}
	else if (++bytes && c <= 0x10FFFF)
	{
		mas[0] = 0xF0 | (c >> 18);
		mas[1] = 0x80 | ((c >> 12) & 0x3F);
		mas[2] = 0x80 | ((c >> 6) & 0x3F);
		mas[3] = 0x80 | (c & 0x3F);
	}
	return (bytes);
}

int				print_wide_character(va_list argument, t_attrib *attr)
{
	wchar_t		c;
	char		mas[4];
	int			bytes;
	int			len;

	bytes = 0;
	mas[0] = '\0';
	mas[1] = '\0';
	mas[2] = '\0';
	mas[3] = '\0';
	c = (wchar_t)va_arg(argument, wint_t);
	bytes = check_bytes(mas, c);
	len = bytes;
	if (!(attr->flag & (1 << 2)))
		len = print_spaces(attr->width, len, attr->flag);
	write(1, mas, bytes);
	if (attr->flag & (1 << 2))
		len = print_spaces(attr->width, len, attr->flag);
	return (len);
	return (len);
}
