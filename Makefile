# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/19 11:27:45 by nmeunier          #+#    #+#              #
#    Updated: 2025/12/19 16:04:50 by nmeunier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = so_long.c parser_map.c gnl/get_next_line.c gnl/get_next_line_utils.c \
		ft_strcpy.c copy_in_tab.c

CC = cc 
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I./mlx
LDFLAGS = -L./mlx -lmlx -lX11 -lXext

NAME = so_long
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

