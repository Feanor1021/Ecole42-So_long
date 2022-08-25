# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/14 16:12:33 by fyardimc          #+#    #+#              #
#    Updated: 2022/08/25 16:18:03 by fyardimc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long

MAIN := main.o

SRCS :=	 so_long_utils.c gnl/get_next_line.c gnl/get_next_line_utils.c map_create_control.c\
		map_create_control_utils.c path_find_control.c errors.c

OBJ := $(SRCS:%.c=%.o)

CC		 = @gcc
CFLAGS	 = 

$(NAME): $(MAIN) $(OBJ)
	@make -C ./ft_printf
	$(CC) $(CFLAGS) $(OBJ) ./ft_printf/libftprintf.a $(MAIN) -o $(NAME) -ggdb
	@printf "[\e[32mSUCCESS so_long ready✅\e[0m]\n"

all: $(NAME)

clean:
	@rm -f *.o ft_printf/*.o get_next_line/*.o
	@make -C ./ft_printf fclean
	@printf "[\e[33mObject files are cleaned🚽\e[0m]\n"
fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@printf "[\e[33mEverything cleaned🗑\e[0m ]\n"
re: fclean all

.PHONY: all clean fclean re bonus