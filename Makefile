# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/08 12:22:11 by rodrpere          #+#    #+#              #
#    Updated: 2026/06/12 21:47:14 by rodrpere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

INCLUDES = -Iincs -Ilibft -Ift_printf

LIBFT = libft/libft.a

FT_PRINTF = ft_printf/libftprintf.a

SRCS = 	lists/create_list.c lists/lists_fts.c \
		methods/push.c methods/rrotate.c methods/rotate.c methods/swap.c methods/disorder.c\
		parsers/validate.c parsers/matrix.c parsers/check_errors.c\
		main.c

OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(FT_PRINTF) $(NAME)

$(LIBFT):
	$(MAKE) -C libft/

$(FT_PRINTF):
	$(MAKE) -C ft_printf/

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C libft/ clean
	$(MAKE) -C ft_printf/ clean
	rm -fr $(OBJS)

fclean: clean
	$(MAKE) -C libft/ fclean
	$(MAKE) -C ft_printf/ fclean
	rm -fr $(NAME)

re: fclean all

.PHONY: all clean fclean re