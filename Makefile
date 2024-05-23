# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: souaret <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 12:06:38 by souaret           #+#    #+#              #
#    Updated: 2024/05/23 19:23:26 by souaret          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS= -Wall -Wextra -Werror -I./$(INCL) -g

SRC =	ft_atoi.c ft_isalpha.c ft_isalnum.c	 ft_isascii.c	ft_isdigit.c \
		ft_isprint.c ft_tolower.c ft_toupper.c ft_tolower.c ft_strncmp.c \
		ft_strlen.c ft_strchr.c ft_strnstr.c ft_strlcpy.c ft_memset.c	\
		ft_bzero.c ft_memchr.c ft_strlcat.c ft_strrchr.c ft_memcpy.c	\
		ft_memcmp.c ft_memmove.c ft_calloc.c ft_strdup.c
OBJ := $(SRC:.c=.o)
INC	=   libft.h

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(SRC) $(OBJ) $(INC)
	ar -rcs $(NAME) $(OBJ)

all: $(NAME)

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
#	@rm -f libft_test

testv:	$(NAME) $(OBJ) $(INC)
	$(CC) $(CFLAGS) ../Libft-main.c libft.a -o libft_test
	valgrind -s --track-origins=yes ./libft_test
#	@rm -f libft_test

re_test:
	rm -f libft_test

print_obj:
	@echo $(OBJ)

.PHONY: re fclean clean all
