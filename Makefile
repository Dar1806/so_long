# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/19 11:27:45 by nmeunier          #+#    #+#              #
#    Updated: 2026/01/26 17:12:33 by nmeunier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = src/valid_map2.c src/create_tab.c src/valid_map.c gnl/get_next_line.c \
		gnl/get_next_line_utils.c libft/ft_putstr_fd.c libft/ft_strlcpy.c \
		libft/ft_strtrim.c src/main.c src/mlx_init.c src/create_map.c \
		src/key_handler.c src/move_player.c libft/ft_putnbr_fd.c \
		libft/ft_putchar_fd.c

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
	$(CC) $(CFLAGS) $(OBJS) $(MLXLIB) $(X11_LIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx -O3 -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

