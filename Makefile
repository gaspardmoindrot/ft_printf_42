NAME	= libftprintf.a

SRC	= ./srcs/*.c ./libft/*.c

OBJ	= $(SRC:.c=.o)
CFLAG	= -Wall -Wextra -Werror
HEADER	= includes/

all: $(NAME)

$(NAME):
	gcc $(CFLAG) -c -I $(HEADER) -I ./libft $(SRC)
	ar rc $(NAME) *.o
	ranlib $(NAME)

clean:
	rm -f *.o
	rm -f libft/*.o

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a
	rm -f libft/libft.h.gch

re: fclean all

.PHONY: all, clean, fclean, re
