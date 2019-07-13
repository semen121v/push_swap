# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fshade <fshade@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/27 14:08:25 by fshade            #+#    #+#              #
#    Updated: 2019/05/17 22:20:21 by fshade           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS_DIR = srcs/
LIBFT_DIR = libft/
HEADERS_DIR = includes/

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))
LIBFT = $(addprefix $(LIBFT_DIR), $(LIBFT_FILES))

SRCS_FILES = ft_printf.c ft_printf_attributes.c ft_printf_specifiers.c \
			 ft_printf_string.c  ft_print_decimal.c  ft_putchar_view.c \
			 ft_print_unsigned_decimal.c ft_print_special_decimal.c \
			 ft_print_octal.c ft_putnbr_octal.c ft_print_wide_character.c \
			 ft_print_hexdecimal.c ft_print_special_hexdecimal.c ft_print_pointer.c \
			 ft_print_unspecial_decimal.c ft_print_float.c ft_print_float1.c 
LIBFT_FILES = ft_atoi.c ft_isspace.c ft_memset.c ft_strsub.c ft_strncpy.c \
			  ft_strnew.c ft_strlen.c ft_putchar.c ft_memalloc.c ft_isdigit.c \
			  ft_bzero.c ft_putnbr.c ft_putstr.c ft_strdup.c ft_strcpy.c
OBJ = $(SRCS_FILES:.c=.o) $(LIBFT_FILES:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@gcc -c $(CFLAGS) $(SRCS) $(LIBFT) -I includes/
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ)
	@make clean -C libft/

fclean: clean 
	@rm -f $(NAME)
	@make fclean -C libft/

re: fclean all
