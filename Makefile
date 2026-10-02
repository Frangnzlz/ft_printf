NAME = libftprintf.a

CC = cc
FLAGS = -Wall -Wextra -Werror


SRCS = ft_printf.c \
ft_putnbr.c \
ft_putptr.c \
ft_putstr.c 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
		$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)
re : fclean all

.PHONY: all clean fclean re


