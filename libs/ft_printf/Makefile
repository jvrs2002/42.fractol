CFLAGS = -Wall -Wextra -Werror

CFILES = ft_printf.c ft_putchar_pf.c ft_putnbr_hex.c ft_putnbr_pf.c ft_putnbr_unsigned_pf.c ft_putstr_pf.c

OFILES = $(CFILES:.c=.o)

NAME = libftprintf.a

CC = gcc

all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

%.o: %.c
	$(CC) -c $(CFLAGS) $<

clean:
	rm -rf $(OFILES)

fclean: clean
	rm -rf $(NAME)
	
re: fclean all

.PHONY: all bonus clean fclean re