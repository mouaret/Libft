# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: souaret <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 12:06:38 by souaret           #+#    #+#              #
#    Updated: 2024/05/17 12:31:36 by souaret          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

OBJS = objs
SRCS = srcs
INCL = includes

CC = gcc
CC := @$(CC)

CFLAGS = -Wall -Wextra -Werror -I./$(INCL)

SRC    = ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c     \
		 ft_swap.c

SRC := $(addprefix $(SRCS)/, $(SRC))
OBJ = $(patsubst %.c, %.o,$(SRC))

all: $(NAME)

$(OBJS)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)
	@rm -rf $(OBJ)


clean:  
	@rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	norminette $(SRCS) | more
	norminette $(INCL) | more

.PHONY: re fclean clean all norm
