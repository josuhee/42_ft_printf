CC=gcc
SRCS=ft_printf.c ft_printf_utils.c ft_printf_arg.c ft_printf_arg_2.c ft_printf_arg_utils.c ft_string.c ft_print_p.c
OBJS=$(SRCS:.c=.o)
NAME=libftprintf.a
HEADER=-I .
CFLAG=-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $^

%.o: %.c
	$(CC) $(CFLAG) -c -o $@ $< $(HEADER)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
