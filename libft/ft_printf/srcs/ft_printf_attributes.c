/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_attributes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:36:05 by eschoen           #+#    #+#             */
/*   Updated: 2019/05/17 23:49:02 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Получает флаги и сохраняет их в структуре атрибутов. Если флага нет, функция
** возвращает ноль (0), иначе возвращает единицу (1).
**
** @HASH:   используется с спецификаторами o, x или X значение предшествует
**          0, 0x или 0X соответственно для значений, отличных от нуля.
**          По умолчанию, если цифры не следуют, десятичная точка не записы-
**          вается.
** @ZERO  : При заполнении слева вместо пробелов указывается число с нулями (0).
** @MINUS : Левому краю в пределах заданной ширины поля. Правое обоснование -
**          это значение по умолчанию
** @SPACE : Если знак не будет записан, перед значением вставляется пустое
**          пространство.
** @PLUS  : Заставляет продолжить результат со знаком плюс или минус (+или -),
**          даже для положительных чисел. По умолчанию только отрицательным
**          числам предшествует знак минус ( -).
*/

static int	flags_getting(char flag, t_attrib *attr)
{
	flag == '#' ? attr->flag |= (1 << (0)) : 0;
	flag == '0' ? attr->flag |= (1 << (1)) : 0;
	flag == '-' ? attr->flag |= (1 << (2)) : 0;
	flag == ' ' ? attr->flag |= (1 << (4)) : 0;
	flag == '+' ? attr->flag |= (1 << (3)) : 0;
	attr->logic = 1;
	return (flag == '#' || flag == '0' || flag == '-' \
	|| flag == ' ' || flag == '+');
}

/*
** Управляет минимальным количеством выводимых символов. Если количество
** символов ввыходном значении меньше заданной ширины, пробелы добавляются слева
** или справа от значений—в зависимости от того, указан ли флаг выравнивания
** слева ( - ) — до тех пор, пока не будет достигнута минимальная ширина.
** @star (*) : Не указан в строке формата, но как дополнительный аргумент
** 			   целочисленного значения, предшествующий аргументу, который
** 			   должен быть отформатирован.
** @number   : Минимальное количество символов для печати. Если печатаемое
** 			   значение короче этого числа, результат заполняется пробелами.
*/

static int	width_getting(va_list arg, char *format, t_attrib *attr)
{
	char	*number;
	int		width;

	width = 0;
	if (format[width] == '*')
	{
		attr->width = va_arg(arg, int);
		if (attr->width < 0)
		{
			attr->width = attr->width * (-1);
			attr->flag |= (1 << (2));
		}
		width = 1;
	}
	else
	{
		while (ft_isdigit(format[width]) == 1)
			width++;
		if ((width == 0) || (number = ft_strsub(format, 0, width)) == NULL)
			return (0);
		attr->width = ft_atoi(number);
		free(number);
	}
	return (width);
}

/*
** Задает число символов строки, количество знаков после запятой, или количество
** значащих цифр для вывода. Для чисел точность-это минимальное количество цифр,
** которые необходимо записать. Если записываемое значение короче этого числа,
** результат дополняется ведущими нулями. Значение не усекается, даже если
** результат больше. Для строк-максимальное число печатаемых символов.
** По умолчанию все символы печатаются до тех пор, пока не будет обнаружен
** нулевой символ.
*/

static int	accuracy_getting(va_list ap, char *format, t_attrib *attr)
{
	int		accuracy;
	char	*number;

	accuracy = 0;
	if (format[0] == '.')
	{
		accuracy = 1;
		if (format[accuracy] == '*')
		{
			attr->accuracy = va_arg(ap, int);
			accuracy++;
		}
		else
		{
			while (ft_isdigit(format[accuracy]) == 1)
				accuracy++;
			if ((number = ft_strsub(format, 1, accuracy)) == NULL)
				return (0);
			attr->accuracy = (accuracy != 1) ? ft_atoi(number) : 0;
			free(number);
		}
	}
	return (accuracy);
}

/*
** Изменяет длину типа данных. На следующей диаграмме показаны типы,
** используемые для интерпретации соответствующего спецификатора с
** описателем длины и без него.
*/

static int	length_getting(char *format, t_attrib *attr)
{
	int		length;

	length = 0;
	while (format[length] == 'h' || format[length] == 'l' \
			|| format[length] == 'j' || format[length] == 'z' \
			|| format[length] == 'L')
	{
		if (format[length] == 'h')
			format[length + 1] == 'h' \
				? (attr->flag |= (1 << (19))) : (attr->flag |= (1 << (20)));
		if (format[length] == 'l')
			format[length + 1] == 'l' \
				? (attr->flag |= (1 << (21))) : (attr->flag |= (1 << (22)));
		if (attr->flag == (1 << (19)) || attr->flag == (1 << (21)))
			length++;
		if (format[length] == 'j')
			attr->flag |= (1 << (23));
		if (format[length] == 'z')
			attr->flag |= (1 << (24));
		if (format[length] == 'L')
			attr->flag |= (1 << (29));
		length++;
	}
	return (length);
}

/*
** Возвращает флаги, ширину, точность и длину формата. Возвращает логическое
** значение (один (1) или ноль (0)), указывающее, является ли формат допустимым.
*/

int			attributes_getting(char **format, va_list arg, t_attrib *attr)
{
	int		format_width;
	char	*init_format;

	attr->logic = 0;
	init_format = *format;
	while (flags_getting(**format, attr))
		(*format)++;
	while ((format_width = width_getting(arg, *format, attr)))
	{
		attr->flag |= (1 << (25));
		attr->logic = 1;
		(*format) = (*format) + format_width;
	}
	while ((format_width = accuracy_getting(arg, *format, attr)))
	{
		if (attr->accuracy >= 0)
			attr->flag |= (1 << (26));
		attr->logic = 1;
		(*format) = (*format) + format_width;
	}
	while ((format_width = length_getting(*format, attr)))
		(*format) = (*format) + format_width;
	return (*format > init_format);
}
