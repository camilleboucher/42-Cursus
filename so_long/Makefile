# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Camille <private_mail>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/20 10:13:22 by Camille           #+#    #+#              #
#    Updated: 2026/01/19 17:51:35 by Camille          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long

LIBMLX_DIR := MacroLibX/
LIBMLX:= $(LIBMLX_DIR)libmlx.so -lSDL2

LIBFT_DIR := libft/
LIBFT_NAME := libft.a
LIBFT := $(LIBFT_DIR)$(LIBFT_NAME)
MAKEFLAGS += --no-print-directory

LIBS := $(LIBMLX_DIR) $(LIBFT_DIR)
INCLUDES := -Iinclude $(addprefix -I, $(addsuffix include, $(LIBS)))

CC := cc
CFLAGS := -Wall -Werror -Wextra $(INCLUDES)
ifeq ($(DEBUG),true)
    CFLAGS += -g
    LIBMLX := $(LIBMLX_DIR)libmlx_debug.so -lSDL2
endif

SRC_DIR := src/
ALGO_DIR := algorithm/

SRC_BASENAMES := so_long
SRCS := $(addprefix $(SRC_DIR), $(addsuffix .c,$(SRC_BASENAMES)))

OBJ_DIR := .build/
OBJS := $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $^ -o $@ $(LIBMLX)

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

bonus: all

.PHONY: all clean fclean re
