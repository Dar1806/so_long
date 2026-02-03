# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/19 11:27:45 by nmeunier          #+#    #+#              #
#    Updated: 2026/02/03 17:40:30 by nmeunier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/ft_putstr_fd.c libft/ft_strlcpy.c libft/ft_strtrim.c \
		 libft/ft_putnbr_fd.c libft/ft_putchar_fd.c libft/ft_itoa.c

GNL = gnl/get_next_line.c gnl/get_next_line_utils.c

SRCS = $(LIBFT) $(GNL) src/valid_map2.c src/create_tab.c src/valid_map.c \
		src/mlx_init.c src/create_map.c src/key_handler.c src/move_player.c \
		src/exit.c src/main.c

SRCS_BONUS = $(LIBFT) $(GNL)  src_bonus/enemy.c src/create_tab.c \
		src_bonus/valid_map_bonus.c src/create_map.c src_bonus/key_handler_bonus.c \
		src_bonus/move_player_bonus.c src/exit.c src/main.c src_bonus/mlx_init_bonus.c \
		src/valid_map2.c src_bonus/enemy_move.c src_bonus/moves.c

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
X11_LIB = -lXext -lX11 -lm -lz
MLXLIB = -Lmlx -lmlx

NAME = so_long
NAME_BONUS = so_long_bonus
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJS)
	make -C mlx
	$(CC) $(CFLAGS) $(OBJS) $(MLXLIB) $(X11_LIB) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
	make -C mlx
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(MLXLIB) $(X11_LIB) -o $(NAME_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx -O3 -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

bonus_re: fclean bonus

.PHONY: all bonus clean fclean re bonus_re

