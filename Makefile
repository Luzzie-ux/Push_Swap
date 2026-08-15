# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/08 12:22:11 by rodrpere          #+#    #+#              #
#    Updated: 2026/06/15 14:26:46 by rodrpere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

INCLUDES = -Iincs -Ilibft -Ift_fprintf

LIBFT = libft/libft.a

FT_FPRINTF = ft_fprintf/libftfprintf.a

SRCS = 	lists/create_list.c lists/lists_fts.c lists/bench.c lists/bench_utils.c \
		methods/swap_n_push.c methods/rotate_n_rrotate.c methods/minmax_rrr.c methods/disorder.c \
		parsers/validate.c parsers/matrix.c parsers/check_errors.c \
		algos/sorts.c algos/simple_alg.c algos/medium_alg.c algos/complex_alg.c algos/adaptive_alg.c\
		main.c

OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(FT_FPRINTF) $(NAME)

$(LIBFT):
	$(MAKE) -C libft/

$(FT_FPRINTF):
	$(MAKE) -C ft_fprintf/

$(NAME): $(OBJS) $(LIBFT) $(FT_FPRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(FT_FPRINTF) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C libft/ clean
	$(MAKE) -C ft_fprintf/ clean
	rm -fr $(OBJS)

fclean: clean
	$(MAKE) -C libft/ fclean
	$(MAKE) -C ft_fprintf/ fclean
	rm -fr $(NAME)

re: fclean all

.PHONY: all clean fclean re