# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/08 12:22:11 by rodrpere          #+#    #+#              #
#    Updated: 2026/06/08 15:39:20 by rodrpere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT = libft/libft.a
FT_PRINTF = ft_printf/libftprintf.a
SRCS = 	lists/create_list.c lists/lists_fts.c \
		methods/push.c methods/rrotate.c methods/rotate.c methods/swap.c \
		parsers/ \
		algos/ \
		main.c 
OBJS = (SRCS=.c:.o)

all: $(NAME)

$(LIBFT): 
	make -C libft/

$(FT_PRINTF):
	make -C ft_printf/

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) -o $(NAME)

clean:
	$(MAKE) -C libft/ clean
	$(MAKE) -C ft_printf/ clean
	rm -fr $(OBJS)

fclean: clean
	rm -fr $(NAME)

re: fclean all

.PHONY: all clean fclean re