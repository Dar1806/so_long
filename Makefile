# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/19 11:27:45 by nmeunier          #+#    #+#              #
#    Updated: 2026/01/21 17:07:22 by nmeunier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = src/parser_map.c src/create_tab.c src/valid_map.c gnl/get_next_line.c \
		gnl/get_next_line_utils.c libft/ft_putstr_fd.c libft/ft_strlcpy.c \
		libft/ft_strtrim.c src/main.c src/mlx_init.c

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
X11_LIB = -lXext -lX11 -lm -lz
MLXLIB = -Lmlx -lmlx

NAME = so_long
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C mlx
	$(CC) $(CFLAGS) $(OBJS) $(X11_LIB) $(MLXLIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx -O3 -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re

