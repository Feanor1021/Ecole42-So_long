# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/14 16:12:33 by fyardimc          #+#    #+#              #
#    Updated: 2022/08/28 16:39:00 by fyardimc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_BONUS := so_long_bonus


MAIN_BONUS := src_bonus/main.o

NAME :=	so_long

MAIN := src_mandatory/main.o

SRCS_BONUS :=	 src_bonus/so_long_utils.c gnl/get_next_line.c gnl/get_next_line_utils.c src_bonus/map_create_control.c\
		src_bonus/map_create_control_utils.c src_bonus/path_find_control.c src_bonus/errors.c src_bonus/screens.c src_bonus/configure_settings.c\
		src_bonus/render.c src_bonus/key_input.c src_bonus/so_long_utils2.c src_bonus/animations.c src_bonus/enemy.c

SRCS :=	 src_mandatory/so_long_utils.c gnl/get_next_line.c gnl/get_next_line_utils.c src_mandatory/map_create_control.c\
		src_mandatory/map_create_control_utils.c src_mandatory/path_find_control.c src_mandatory/errors.c\
		src_mandatory/screens.c src_mandatory/configure_settings.c src_mandatory/render.c src_mandatory/key_input.c\

OBJ := $(SRCS:%.c=%.o)

OBJ_BONUS := $(SRCS_BONUS:%.c=%.o)

CC		 = @gcc
CFLAGS	 = -Wall -Wextra -Werror

$(NAME): $(MAIN) $(OBJ)
	@make -C ./ft_printf
	@make -C ./mlx
	$(CC) $(CFLAGS) $(OBJ) -framework OpenGL -framework AppKit mlx/libmlx.a ./ft_printf/libftprintf.a $(MAIN) -o $(NAME) -ggdb
	@printf "[\e[32mSUCCESS so_long mandatory ready✅\e[0m]\n"

all: $(NAME)

$(NAME_BONUS): $(MAIN_BONUS) $(OBJ_BONUS)
	@make -C ./ft_printf
	@make -C ./mlx
	$(CC) $(CFLAGS) $(OBJ_BONUS) -framework OpenGL -framework AppKit mlx/libmlx.a ./ft_printf/libftprintf.a $(MAIN_BONUS) -o $(NAME_BONUS) -ggdb
	@printf "[\e[32mSUCCESS so_long bonus ready✅\e[0m]\n"

bonus: $(NAME_BONUS)
	
clean:
	@rm -f src_bonus/*.o ft_printf/*.o gnl/*.o src_mandatory/*.o
	@make -C ./ft_printf fclean
	@printf "[\e[33mObject files are cleaned🚽\e[0m]\n"

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@make -C ./mlx clean
	@printf "[\e[33mEverything cleaned🗑\e[0m ]\n"
re: fclean all

.PHONY: all clean fclean re bonus