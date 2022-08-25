NAME := libftprintf.a

SRCS :=		src/ft_prchrstrng.c src/ft_printf.c src/ft_putnum_unum.c

OBJ := $(SRCS:%.c=%.o)

CC		 = gcc
CFLAGS	 = -Wall -Wextra -Werror -I ./include

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean:
	@rm -f src/*.o

fclean: clean
	@rm -f $(NAME)
	
re: fclean all

.PHONY: all bonus clean fclean re