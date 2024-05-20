# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: souaret <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 12:06:38 by souaret           #+#    #+#              #
#    Updated: 2024/05/20 16:31:39 by souaret          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS= -Wall -Wextra -Werror -I./$(INCL)

SRC   =	ft_atoi.c ft_isalpha.c ft_isalnum.c	 ft_isascii.c	ft_isdigit.c \
		ft_isprint.c ft_tolower.c ft_toupper.c ft_tolower.c\
		ft_strlen.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(OBJS)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)
	@rm -rf $(OBJ)


clean:  
	@rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	norminette $(SRC) | more

test:	all
	$(CC) $(CFLAGS) ../Libft-main.c libft.a -o libft_test
	./libft_test

retest:
	rm -f libft_test

.PHONY: re fclean clean all norm
