# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/11 15:41:33 by nmeunier          #+#    #+#              #
#    Updated: 2026/01/19 17:12:59 by nmeunier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_putstr_fd.c ft_strlcpy.c ft_strtrim.c

					
OBJS	= $(SRCS:.c=.o)


CC	= gcc
RM	= rm -f
CFLAGS	= -Wall -Wextra -Werror

NAME	= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

bonus:			$(BONUS_OBJS)
				ar rcs $(NAME)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)
				$(RM) libft.so

re:				fclean all

.PHONY:			all clean fclean re bonus
