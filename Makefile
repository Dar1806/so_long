# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/19 11:27:45 by nmeunier          #+#    #+#              #
#    Updated: 2026/01/21 14:37:17 by nmeunier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = src/parser_map.c src/create_tab.c src/valid_map.c gnl/get_next_line.c \
		gnl/get_next_line_utils.c

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I. -I./gnl  -I./libft
LIBFT = libft/libft.a

NAME = so_long
OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re

