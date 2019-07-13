/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_specifiers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 12:57:04 by eschoen           #+#    #+#             */
/*   Updated: 2019/05/17 22:37:59 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Возвращает каждую позицию спецификатора из format.
*/

static int		specifier_location(char c, char *specificator)
{
	int			position;

	position = 0;
	while (specificator[position])
	{
		if (c == specificator[position])
			return (position);
		position++;
	}
	return (-1);
}

/*
** Получает, какой спецификатор находится в формате, и кодирует его с учетом
** его соответствующего битового значения (переход от бита пять (5) до бита
** восемнадцать (18) для обязательных спецификаторов и бита двадцать семь (27)
** для бонуса, двоичного).
*/

static int		specifier_getting(char c, t_attrib *attr, char *spec)
{
	int			*spec_encoded;
	int			specificator;

	spec_encoded = ft_memalloc(sizeof(int) * 16);
	spec_encoded[LOW_S] = (1 << (5));
	spec_encoded[UPP_S] = (1 << (6));
	spec_encoded[LOW_P] = (1 << (7));
	spec_encoded[LOW_D] = (1 << (8));
	spec_encoded[UPP_D] = (1 << (9));
	spec_encoded[LOW_I] = (1 << (10));
	spec_encoded[LOW_O] = (1 << (11));
	spec_encoded[UPP_O] = (1 << (12));
	spec_encoded[LOW_U] = (1 << (13));
	spec_encoded[UPP_U] = (1 << (14));
	spec_encoded[LOW_X] = (1 << (15));
	spec_encoded[UPP_X] = (1 << (16));
	spec_encoded[LOW_C] = (1 << (17));
	spec_encoded[UPP_C] = (1 << (18));
	spec_encoded[LOW_F] = (1 << (27));
	spec_encoded[UPP_F] = (1 << (28));
	if (((specificator = specifier_location(c, spec)) != (-1)) && c != 0)
		attr->flag |= spec_encoded[specificator];
	free(spec_encoded);
	return (specificator);
}

/*
** Анализирует спецификатор, возвращает позицию спецификатора.
** Если атрибут недопустим, возвращает ошибку printf.
*/

int				specifier_parsing(va_list arg, char **format, t_attrib *attr)
{
	int			specificator;
	int			valid_or_not;
	char		*converting;

	attr->flag = 0;
	if (!(converting = (ft_strdup("sSpdDioOuUxXcCfF"))))
		return (0);
	specificator = -1;
	while (**format)
	{
		if ((specifier_location(**format, converting) != (-1)) \
			&& (specificator = specifier_getting(**format, attr, converting)))
			break ;
		if ((valid_or_not = attributes_getting(format, arg, attr)) == 0)
			break ;
	}
	free(converting);
	return (specificator);
}
