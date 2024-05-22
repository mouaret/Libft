# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: souaret <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 12:06:38 by souaret           #+#    #+#              #
#    Updated: 2024/05/21 20:00:14 by souaret          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS= -Wall -Wextra -Werror -I./$(INCL)

SRC =	ft_atoi.c ft_isalpha.c ft_isalnum.c	 ft_isascii.c	ft_isdigit.c \
		ft_isprint.c ft_tolower.c ft_toupper.c ft_tolower.c ft_strncmp.c \
		ft_strlen.c ft_strchr.c ft_strnstr.c ft_strlcpy.c ft_memset.c	\
		ft_bzero.c ft_memchr.c

INC	=   libft.h

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(OBJS)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(INC)
	ar -rcs $(NAME) $(OBJ)
#	@rm -rf $(OBJ)


clean:  
	@rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	norminette $(SRC) | more
	norminette $(INC) | more

test:	$(NAME) $(OBJ) $(INC)
	$(CC) $(CFLAGS) ../Libft-main.c libft.a -o libft_test
	./libft_test
	@rm -f libft_test

retest:
	rm -f libft_test

.PHONY: re fclean clean all norm
