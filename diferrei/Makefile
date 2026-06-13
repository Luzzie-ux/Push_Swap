# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#   By: diferrei <diferrei@student.42porto.com>    +#+  +:+       +#+          #
#                                                +#+#+#+#+#+   +#+             #
#    Created: 2026/05/15 10:42:54 by rodrpere          #+#    #+#              #
#    Updated: 2026/06/12 12:27:53 by diferrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I. -I$(PRINTF_DIR)
PRINTF_DIR  = ./ft_printf
PRINTF      = $(PRINTF_DIR)/libftprintf.a
SRCS        = main.c parsing_swap.c check_stackdisorder.c ft_atoladdback.c split_utils.c \
              simple_alg.c medium_alg.c complex_alg.c adaptive_alg.c split.c bench_utils.c \
	      ft_strcmp.c push_swap_sp.c push_swap_rr.c push_swap_minmax_rrr.c print_bench.c
OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) -o $(NAME)
$(PRINTF):
	@make -C $(PRINTF_DIR)
clean:
	@make clean -C $(PRINTF_DIR) 
	rm -f $(OBJS)

fclean: clean
	@make fclean -C $(PRINTF_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
