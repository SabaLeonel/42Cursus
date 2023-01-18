# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 11:02:33 by lsaba-qu          #+#    #+#              #
#    Updated: 2023/01/18 12:04:13 by lsaba-qu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRC	= ft_toupper.c \
	ft_tolower.c \
	ft_strlen.c \
	ft_isascii.c \
	ft_isalpha.c \
	ft_isprint.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_bzero.c \
	ft_memset.c \
	ft_strncmp.c \
	ft_memcpy.c \
	ft_strchr.c \
	ft_atoi.c \
	ft_strrchr.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_strnstr.c \
	ft_memchr.c \
	ft_memmove.c \
	ft_memcmp.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_strjoin.c \
	ft_itoa.c \
	ft_substr.c \
	ft_strtrim.c \
	ft_split.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_striteri.c \
	ft_strmapi.c \
	ft_printbase.c \
	ft_printf.c \
	ft_printfutils.c \

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