# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/19 11:27:45 by nmeunier          #+#    #+#              #
#    Updated: 2026/01/19 17:15:32 by nmeunier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = parser_map.c create_tab.c valid_map.c gnl/get_next_line.c gnl/get_next_line_utils.c

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I. -I./gnl  -I./Libft
LIBFT = Libft/libft.a

NAME = so_long
OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C Libft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C Libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C Libft fclean

re: fclean all

.PHONY: all clean fclean re

