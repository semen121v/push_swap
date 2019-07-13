/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 10:48:44 by eschoen           #+#    #+#             */
/*   Updated: 2019/05/17 21:53:15 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <limits.h>

/*
** Печатаем количество пробелов.
*/

int				print_spaces(int width, int length, int attrib)
{
	while ((width - length) > 0)
	{
		ft_putchar(((attrib & (1 << 1)) && !(attrib & (1 << 2))) ? '0' : ' ');
		length++;
	}
	return (length);
}

static int		print_no_specifier(char c, t_attrib *attr)
{
	int			length;

	if (!(attr->flag & (1 << 2)))
		length = print_spaces(attr->width, sizeof(char), attr->flag);
	ft_putchar(c);
	if (attr->flag & (1 << (2)))
		length = print_spaces(attr->width, sizeof(char), attr->flag);
	return (length);
}

/*
** Выводит на печать конкретный спецификатор полученный из format.
*/

static int		specificator_printing(char format, va_list argument, \
					t_attrib *attribute, int id)
{
	int			print;

	if (id == LOW_S)
		print = print_string(argument, attribute);
	else if (id == LOW_D || id == LOW_I)
		print = ft_print_decimal(id, attribute, argument);
	else if (id == LOW_U || id == UPP_U)
		print = ft_unsigned_decimal(id, attribute, argument);
	else if (id == LOW_O || id == UPP_O)
		print = ft_print_octal(attribute, argument);
	else if (id == LOW_X || id == UPP_X)
		print = print_hexadecimal1(id, argument, attribute);
	else if (id == LOW_C)
		print = print_character(argument, attribute);
	else if (id == UPP_C)
		print = print_wide_character(argument, attribute);
	else if (id == LOW_P)
		print = print_pointer(argument, attribute);
	else if (id == LOW_F || id == UPP_F)
		print = ft_printf_float(argument, attribute, id);
	else
		print = print_no_specifier(format, attribute);
	return (print);
}

/*
** В случае успеха возвращается общее количество напечатанных символов.
** При ошибке возвращается отрицательное число (-1).
*/

static int		stdout_printing(const char *format[], va_list arguments)
{
	t_attrib	attribute;
	int			specificator;
	int			print;

	attribute.width = 0;
	attribute.flag = 0;
	attribute.accuracy = 0;
	attribute.symbol = 0;
	attribute.number = 0;
	attribute.check = 0;
	specificator = specifier_parsing(arguments, (char **)format, &attribute);
	if (!**format)
		return (-1);
	else
	{
		print = specificator_printing((char)**format, arguments, &attribute, \
		specificator);
		return (print);
	}
}

/*
** ft_printf RETURN VALUES (from man):
** Функция возвращает количество напечатанных символов в stdout (не включая
** конечный "\0", используемый для завершения вывода в строки).
** Функция возвращает отрицательное значение, если произошла ошибка.
**
** Записывает строку, на которую указывает format, в стандартный вывод (stdout),
** заменяя любой спецификатор формата так же, как это делает printf, но
** используя элементы в списке переменных аргументов, идентифицированных
** с помощью arguments вместо дополнительных аргументов функции.
*/

int				ft_printf(const char *format, ...)
{
	int			length;
	int			quantity;
	va_list		arguments;

	quantity = 0;
	va_start(arguments, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if ((length = stdout_printing(&format, arguments)) == -1)
				break ;
			quantity = quantity + length;
		}
		else
		{
			ft_putchar(*format);
			quantity++;
		}
		format++;
	}
	va_end(arguments);
	return (quantity);
}
