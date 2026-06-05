# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/24 16:58:50 by rodrpere          #+#    #+#              #
#    Updated: 2026/06/05 09:39:34 by rodrpere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= push_swap
CC= cc
CFLAGS= -Wall -Wextra -Werror -g
SRCS= $(wildcard srcs/*.c) $(wildcard lists/*.c) $(wildcard algo/*.c)
LIBFT= Libft/libft.a
OBJS= $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C Libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L Libft -lft -o $(NAME)

clean:
	make -C Libft clean
	rm -f $(OBJS)

fclean: clean
	make -C Libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
