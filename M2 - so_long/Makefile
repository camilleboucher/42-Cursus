# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Camille <private_mail>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/20 10:13:22 by Camille           #+#    #+#              #
#    Updated: 2026/02/12 21:23:35 by cboucher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long

LIBMLX_DIR := libmlx/
LIBMLX:= $(LIBMLX_DIR)libmlx.so
LIBMLXFLAG := -lSDL2
LIBMLXFLAG_DEBUG :=

LIBFT_DIR := libft/
LIBFT_NAME := libft.a
LIBFT := $(LIBFT_DIR)$(LIBFT_NAME)
MAKEFLAGS += --no-print-directory

LIBS := $(LIBFT_DIR)
INCLUDES := -Iinclude $(addprefix -I, $(addsuffix include, $(LIBS)))
LIBS := $(LIBMLX_DIR)
INCLUDES += $(addprefix -I, $(addsuffix includes, $(LIBS)))

CC := cc
CFLAGS := -Wall -Werror -Wextra $(INCLUDES)
ifeq ($(DEBUG),true)
    CFLAGS += -g
    LIBMLXFLAG_DEBUG := DEBUG=true
endif

SRC_DIR := src/
ALGO_DIR := algorithm/

SRC_BASENAMES := so_long error_handling map play hooks assets rendering gameplay
SRCS := $(addprefix $(SRC_DIR), $(addsuffix .c,$(SRC_BASENAMES)))

OBJ_DIR := .build/
OBJS := $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

all: starting_compilation $(NAME) check_compilation

$(NAME): $(LIBFT) $(LIBMLX) $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@ $(LIBFT) $(LIBMLX) $(LIBMLXFLAG)

starting_compilation:
	@echo "Compiling $(NAME)..."

check_compilation:
	@[ -f "$(NAME)" ] && echo "$(NAME) compiled successfully" || echo "compilation error"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) -j

$(LIBMLX):
	git clone https://github.com/seekrs/MacroLibX.git -b v2.2.6 $(LIBMLX_DIR) --depth=1
	$(LIBMLXFLAG_DEBUG) $(MAKE) -C $(LIBMLX_DIR) -j

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(LIBMLX_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

bonus: all

.PHONY: all clean fclean re starting_compilation check_compilation
