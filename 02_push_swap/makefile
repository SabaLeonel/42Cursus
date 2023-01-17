NAME	= pushswap.a

SRC	= main.c \


OBJ	= $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

CC	= gcc

RM	= rm -f

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs  $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re