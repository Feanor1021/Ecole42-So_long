# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/14 16:12:33 by fyardimc          #+#    #+#              #
#    Updated: 2022/08/24 18:45:10 by fyardimc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long

MAIN := main.o

SRCS :=	 so_long_utils.c gnl/get_next_line.c gnl/get_next_line_utils.c map_create_control.c\
		map_create_control_utils.c map_create_control2.c

OBJ := $(SRCS:%.c=%.o)

CC		 = gcc
CFLAGS	 = -Wall -Wextra -Werror

$(NAME): $(MAIN) $(OBJ)
	@make -C ./ft_printf
	$(CC) $(CFLAGS) $(OBJ) ./ft_printf/libftprintf.a $(MAIN) -o $(NAME)

all: $(NAME)

clean:
	@rm -f *.o ft_printf/*.o get_next_line/*.o
	@make -C ./ft_printf fclean

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	
re: fclean all

.PHONY: all clean fclean re bonus