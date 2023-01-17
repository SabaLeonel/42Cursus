NAME	= pushswap

LIBFT = ./libft/libft.a

SRC	= main.c \

OBJ	= $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

CC	= gcc

RM	= rm -f

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	cp ./libft/libft.a $(NAME)
	$(CC) -o $(NAME) $(OBJ) -L ./libft -lft

clean:
	make clean -C ./libft
	rm -f $(OBJ)

fclean : clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re