# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: diferrei <diferrei@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/28 11:23:04 by diferrei          #+#    #+#              #
#    Updated: 2026/05/08 12:58:03 by diferrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftfprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs
HDRS = ft_fprintf.h
SRCS = ft_fprintf.c ft_fprintf_chars.c ft_fprintf_numbers.c ft_fprintf_hex.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o : %.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
fclean:	clean
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re
