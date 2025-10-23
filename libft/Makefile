# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Camille <private_mail>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/20 10:13:22 by Camille           #+#    #+#              #
#    Updated: 2025/10/20 10:13:27 by Camille          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS = 	\
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \

OBJS = $(SRCS:.c=.o)

NAME = libft.a

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME)
	rm -f $(OBJS)

re: fclean $(NAME)

.PHONY: all clean fclean re
