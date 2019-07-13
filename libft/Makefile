# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eschoen <eschoen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/02 17:06:20 by eschoen           #+#    #+#              #
#    Updated: 2019/05/27 20:53:18 by eschoen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = libft.h
CFLAGS = -Wall -Wextra -Werror -c
SRCS = get_next_line.c ft_isspace.c ft_abs.c ft_maximum.c ft_minimum.c \
	   ft_charinwordcalc.c ft_wordlen.c ft_wordnext.c ft_countdigit.c \
	   ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	   ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
	   ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
	   ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
	   ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	   ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c \
	   ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
	   ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
	   ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c \
	   ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
	   ft_putendl_fd.c ft_putnbr_fd.c ft_str_to_lowcase.c ft_isuppercase.c \
	   ft_atoi_base.c ft_itoa_base_max.c ft_numlen_max.c ft_atoi_l.c
OBJ = $(SRCS:%.c=%.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(CFLAGS) $(HEADER) $(SRCS)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
