/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 10:48:15 by eschoen           #+#    #+#             */
/*   Updated: 2019/05/17 22:44:07 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** We use "libft.h" as main library for this project (GNL, ft_toupper, etc.)
**
** @ s or s : String of characters
** @ p      : Pointer address
** @ D or i : Signed decimal integer
** @ o or O : Signed octal
** @ u or U : Unsigned decimal integer
** @ x      : Unsigned hexadecimal integer
** @ X      : Unsigned hexadecimal integer (capital letters)
** @ c or C : Character
** @ b      : Binary
*/

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

/*
** Кодировка спецификаторов
*/

# define LOW_S	0
# define UPP_S	1
# define LOW_P	2
# define LOW_D	3
# define UPP_D	4
# define LOW_I	5
# define LOW_O	6
# define UPP_O	7
# define LOW_U	8
# define UPP_U	9
# define LOW_X	10
# define UPP_X	11
# define LOW_C	12
# define UPP_C	13
# define LOW_F	14
# define UPP_F	15
# define S_X	"0x"
# define B_X	"0X"

typedef struct	s_attrib
{
	int			width;
	char		znak;
	int			flag;
	int			accuracy;
	int			logic;
	int			number;
	int			symbol;
	int			check;
}				t_attrib;

int				ft_printf(const char *format, ...);

int				specifier_parsing(va_list arg, char **format, t_attrib *attr);
int				attributes_getting(char **format, va_list arg, t_attrib *attr);
int				print_binary(va_list ap, t_attrib *attr);
int				ft_printf_float(va_list argument, t_attrib *atr, int id);
int				print_spaces(int width, int length, int attrib);
int				print_wide_string(va_list argument, t_attrib *attr);
int				print_wide_character(va_list argument, t_attrib *attribute);
int				print_string(va_list ap, t_attrib *attr);
int				ft_print_decimal(int id, t_attrib *atr, va_list argument);
int				ft_print_octal(t_attrib *atr, va_list argument);
int				ft_putchar_symbol(char c, int x);
int				ft_unsigned_decimal(int id, t_attrib *atr, va_list argument);
int				ft_special_decimal(t_attrib *atr, va_list argument);
int				special_hexdecimal(va_list arg, t_attrib *atr, int id);
int				ft_special_space(t_attrib *atr, int i);
int				ft_unspecial_decimal(t_attrib *atr, va_list argument);
int				ft_unsize(unsigned long long int a, t_attrib *atr);
long long int	ft_size_special(t_attrib *atr, va_list argument);
int				print_hexadecimal1(int id, va_list arg, t_attrib *atr);
int				print_character(va_list ap, t_attrib *attr);
int				print_pointer(va_list arg, t_attrib *atr);
void			ft_special_zero(t_attrib *atr, int i);
void			ft_putnbr_octal(unsigned long long int n);
void			ft_putchar_calc(char c, t_attrib *atr);
void			ft_putnbr_ll(long long n, t_attrib *params);
void			ft_putfloat(long double x, int precision, int flag_diese
					, t_attrib *atr);

#endif
