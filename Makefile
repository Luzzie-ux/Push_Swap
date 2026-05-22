# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/22 13:48:25 by rodrpere          #+#    #+#              #
#    Updated: 2026/05/22 16:38:20 by rodrpere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = swap.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I inc/
SRCS = $(wildcard srcs/*.c)
OBJS = $(SRCS:.c=.o)
MAIN = main.c

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: re
	$(CC) $(CFLAGS) $(MAIN) $(NAME)

.PHONY: all clean fclean re test