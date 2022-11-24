# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 11:02:33 by lsaba-qu          #+#    #+#              #
#    Updated: 2022/11/24 10:22:42 by lsaba-qu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRC	= # NOM DES FICHIERS .c

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