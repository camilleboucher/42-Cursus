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

BUILD_DIR = build/

SRCS = 	\
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \

OBJS = $(subst src,$(BUILD_DIR),$(SRCS:.c=.o))

INCLUDE = -I include

NAME = libft.a

all: $(NAME)

$(BUILD_DIR):
		@mkdir -p $@

$(NAME): $(BUILD_DIR) $(OBJS)
		@$(CC) $(OBJS) -o $(NAME)

$(BUILD_DIR)/%.o: $(SRC_DIR)%.c
		@$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $< 

clean:
		rm -f $(OBJS)
		rm -rf $(BUILD_DIR)

fclean:
		rm -f $(OBJS)
		rm -rf $(BUILD_DIR)
		rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
