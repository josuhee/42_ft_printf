CC=gcc
SRCS=ft_atoi.c 
SRCB=ft_lstadd_front.c 
OBJS=$(SRCS:.c=.o)
OBJSB=$(SRCB:.c=.o)
NAME=libftprintf.a
HEADER=-I libft.h
CFLAG=-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $^

bonus : $(OBJSB) $(OBJS)
	ar -rc $(NAME) $^

%.o: %.c
	$(CC) $(CFLAG) -c -o $@ $< $(HEADER)

clean:
	rm -f $(OBJS) $(OBJSB)

fclean: clean
	rm -f $(NAME)

re: fclean all
