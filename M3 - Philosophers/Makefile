# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Camille <private_mail>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/20 10:13:22 by Camille           #+#    #+#              #
#    Updated: 2026/07/05 16:55:59 by cboucher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := philo

BLUE  := \033[38;5;33m
GREEN  := \033[0;32m
CYAN   := \033[0;36m
YELLOW := \033[0;33m
BOLD   := \033[1m
RESET  := \033[0m

INCLUDES := -Iinclude

CC := cc
CFLAGS := -Wall -Werror -Wextra $(INCLUDES)
ifeq ($(DEBUG),true)
    CFLAGS += -g
endif
ifeq ($(FSANITIZE), true)
    CFLAGS += -fsanitize=address
endif

SRC_DIR := src/
UTILS_DIR := utils/
THREADS_FNS_DIR := threads_functions/

SRC_BASENAMES := main parsing philos_threads
UTILS_BASENAMES := ft_atoi ft_isdigit time_tools
THREADS_FNS_BASENAMES := forks states
SRCS := $(addprefix $(SRC_DIR), $(addsuffix .c,$(SRC_BASENAMES))) \
		$(addprefix $(SRC_DIR)$(UTILS_DIR), $(addsuffix .c,$(UTILS_BASENAMES))) \
		$(addprefix $(SRC_DIR)$(THREADS_FNS_DIR), $(addsuffix .c,$(THREADS_FNS_BASENAMES)))

OBJ_DIR := .build/
OBJS := $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)$(UTILS_DIR)
	@mkdir -p $(OBJ_DIR)$(THREADS_FNS_DIR)
	@printf "$(CYAN)Compiling$(RESET) $(BOLD)%s			$(GREEN)[OK]\n" $<
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)
	@printf "$(GREEN)Cleaned everything!\n$(RESET)Enjoy the Free Space!\n"

re: fclean all

.PHONY: all clean fclean re
