CC=gcc
SRCS=ft_printf.c ft_printf_utils.c ft_printf_arg.c ft_printf_arg_2.c ft_string.c main.c
OBJS=$(SRCS:.c=.o)
#NAME=libftprintf.a
TARGET=exec
HEADER=-I libft.h
#CFLAG=-Wall -Werror -Wextra
CFLAG=

#all: $(NAME)
all: $(TARGET)

#$(NAME): $(OBJS)
	#ar -rc $(NAME) $^

%.o: %.c
	$(CC) $(CFLAG) -c -o $@ $< $(HEADER)

$(TARGET): $(OBJS)
	$(CC) $(CFLAG) -o $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all
