# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Camille <private_mail>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/20 10:13:22 by Camille           #+#    #+#              #
#    Updated: 2025/12/18 16:03:07 by Camille          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

LIBFT_DIR := libft/
LIBFT_NAME := libft.a
LIBFT := $(LIBFT_DIR)$(LIBFT_NAME)
MAKEFLAGS += --no-print-directory

CC := cc
CFLAGS := -Wall -Werror -Wextra -Iinclude -I$(LIBFT_DIR)include
ifeq ($(DEBUG),1)
    CFLAGS += -g
endif

SRC_DIR := src/
SRC_BASENAMES := push_swap
SRCS := $(addprefix $(SRC_DIR), $(addsuffix .c,$(SRC_BASENAMES)))

OBJ_DIR := .build/
OBJS := $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $^ -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
