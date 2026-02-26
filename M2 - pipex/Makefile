# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Camille <private_mail>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/20 10:13:22 by Camille           #+#    #+#              #
#    Updated: 2026/02/26 21:15:52 by cboucher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := pipex

LIBFT_DIR := libft/
LIBFT_NAME := libft.a
LIBFT := $(LIBFT_DIR)$(LIBFT_NAME)
MAKEFLAGS += --no-print-directory

LIBS := $(LIBFT_DIR)
INCLUDES := -Iinclude $(addprefix -I, $(addsuffix include, $(LIBS)))

CC := cc
CFLAGS := -Wall -Werror -Wextra $(INCLUDES)
ENV_DEBUG :=
ifeq ($(DEBUG),true)
    CFLAGS += -g
    ENV_DEBUG := DEBUG=true
endif

SRC_DIR := src/

SRC_BASENAMES := pipex commands
SRCS := $(addprefix $(SRC_DIR), $(addsuffix .c,$(SRC_BASENAMES)))

OBJ_DIR := .build/
OBJS := $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

all: starting_compilation $(NAME) check_compilation

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@ $(LIBFT)

starting_compilation:
	@echo "Compiling $(NAME)..."

check_compilation:
	@[ -f "$(NAME)" ] && echo "$(NAME) compiled successfully" || echo "compilation error"

$(LIBFT):
	@$(ENV_DEBUG) $(MAKE) -C $(LIBFT_DIR) -j

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

.PHONY: all clean fclean re starting_compilation check_compilation
