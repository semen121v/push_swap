# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fshade <fshade@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/26 19:54:23 by eschoen           #+#    #+#              #
#    Updated: 2019/07/27 22:47:06 by fshade           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = $(NAME1) $(NAME2)

NAME1 = checker
NAME2 = push_swap

SRCS_PATH = srcs

SRC_FILES1 = checker.c push.c swap.c reverse_rotate.c rotate.c \
			 support_functions.c sort.c validation_and_reading.c \
			 print.c validation_2.c validation_3.c 
SRC_FILES2 = push_swap.c push.c swap.c reverse_rotate.c rotate.c \
			 support_functions.c sort.c validation_and_reading.c \
			 operations_1.c print.c massive_operation.c operations_2.c \
			 operation_3.c validation_2.c validation_3.c 

SRCS1 = $(addprefix $(SRCS_PATH)/,$(SRC_FILES1))
SRCS2 = $(addprefix $(SRCS_PATH)/,$(SRC_FILES2))

OBJS_PATH1 = objects1/
OBJS_PATH2 = objects2/
OBJS_NAME1 = $(SRC_FILES1:.c=.o)
OBJS_NAME2 = $(SRC_FILES2:.c=.o)
OBJS1 = $(addprefix $(OBJS_PATH1),$(OBJS_NAME1))
OBJS2 = $(addprefix $(OBJS_PATH2),$(OBJS_NAME2))

INCLUDES_PATH = includes

INCLUDES_NAME = push_swap.h get_next_line.h libft.h
INCLUDES = $(addprefix $(INCLUDES_PATH)/,$(INCLUDE_NAME))

CFLAGS = -Wall -Wextra -Werror

LIBFT_PATH = libft
LIB = $(addprefix $(LIBFT_PATH)/,libft.a)

FT_PRINTF = libft/ft_printf/libftprintf.a

PRINTF_PATH = libft/ft_printf/
PRINTF_NAME = libftprintf.a
PRINTF_A = $(addprefix $(PRINTF_PATH),$(PRINTF_NAME))
PRINTF_H = $(addprefix $(PRINTF_PATH),includes/ft_printf.h)

.SILENT: all, clean, fclean, re
.PHONY: all, clean, fclean, re

all: $(NAME)

$(FT_PRINTF):
	@make -C libft/ft_printf/ all

$(LIB):
	@make -C libft/ all

$(NAME1): $(OBJS1)
	@gcc $(CFLAGS) -o $(NAME1) $(OBJS1) libft/libft.a $(FT_PRINTF)

$(NAME2): $(OBJS2)
	@gcc $(FLAGS) -o $(NAME2) $(OBJS2) libft/libft.a $(FT_PRINTF)

$(OBJS1): $(SRCS1) $(FT_PRINTF) $(LIB)
	@gcc -I $(INCLUDES_PATH) $(CFLAGS) -c $(SRCS1)
	@mkdir $(OBJS_PATH1) 2> /dev/null || true
	@mv $(OBJS_NAME1) $(OBJS_PATH1)

$(OBJS2): $(SRCS2) $(FT_PRINTF) $(LIB)
	@gcc -I $(INCLUDES_PATH) $(CFLAGS) -c $(SRCS2)
	@mkdir $(OBJS_PATH2) 2> /dev/null || true
	@mv $(OBJS_NAME2) $(OBJS_PATH2)

clean:
	@/bin/rm -rf $(OBJS_PATH1) $(OBJS_PATH2)
	@make -C libft/ clean
	@make -C libft/ft_printf/ clean

fclean: clean
	@/bin/rm -f $(NAME1) $(NAME2)
	@make -C libft/ fclean
	@make -C libft/ft_printf/ fclean

re: fclean all
