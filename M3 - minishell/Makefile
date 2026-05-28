# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/20 10:13:22 by Camille           #+#    #+#              #
#    Updated: 2026/05/16 14:56:17 by lifranco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME := minishell
BLUE  := \033[38;5;33m
RESET := \033[0m
GREEN  := \033[0;32m
CYAN   := \033[0;36m
YELLOW := \033[0;33m
RESET  := \033[0m
BOLD   := \033[1m

LIBFT_DIR := libft/
LIBFT_NAME := libft.a
LIBFT := $(LIBFT_DIR)$(LIBFT_NAME)
MAKEFLAGS += --no-print-directory

CC := cc
CFLAGS := -Wall -Werror -Wextra -Iinclude -I$(LIBFT_DIR)include
ifeq ($(DEBUG),true)
    CFLAGS += -g
endif

ifeq ($(FSANITIZE), true)
	CFLAGS += -fsanitize=address
endif

SRC_DIR := src/
HELPERS_DIR := helpers/
PARSE_DIR := parsing/
LEXER_DIR := parsing/lexer/
EXEC_DIR := exec/
EXPAND_DIR := expander/
BUILT_IN_DIR := built_in/
BTIN_HELPERS_DIR := built_in/helpers/

SRC_BASENAMES := minishell signals cleaning
HELPERS_BASENAMES := get_envp check_prompt check_only_spaces signals_utils
PARSE_BASENAMES := is_helpers fill_io parsing trim_quotes process fill_argv check_for_spaces
LEXER_BASENAMES := ft_lexlast lexer split_quotes ft_lexclear error_cleaning check_filename
EXEC_BASENAMES := exec built_in redirections fds_utils heredoc pipes children exit_code
EXPAND_BASENAMES := expand get_var is_in_sq
BUILT_IN_BASENAMES := ft_echo ft_cd ft_pwd ft_export ft_unset ft_env ft_exit
BTIN_HELPERS_BASENAMES := handle_append appending get_argc ft_getenv set_env unset handle_pipes_for_cd

SRCS := $(addprefix $(SRC_DIR), $(addsuffix .c,$(SRC_BASENAMES))) \
		$(addprefix $(SRC_DIR)$(HELPERS_DIR), $(addsuffix .c,$(HELPERS_BASENAMES))) \
		$(addprefix $(SRC_DIR)$(PARSE_DIR), $(addsuffix .c,$(PARSE_BASENAMES))) \
		$(addprefix $(SRC_DIR)$(LEXER_DIR), $(addsuffix .c,$(LEXER_BASENAMES))) \
		$(addprefix $(SRC_DIR)$(EXEC_DIR), $(addsuffix .c,$(EXEC_BASENAMES))) \
		$(addprefix $(SRC_DIR)$(EXPAND_DIR), $(addsuffix .c,$(EXPAND_BASENAMES))) \
		$(addprefix $(SRC_DIR)$(BUILT_IN_DIR), $(addsuffix .c,$(BUILT_IN_BASENAMES))) \
		$(addprefix $(SRC_DIR)$(BTIN_HELPERS_DIR), $(addsuffix .c,$(BTIN_HELPERS_BASENAMES)))

OBJ_DIR := .build/
OBJS := $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $^ -o $@ -lreadline
	@printf "\n\n\n\n\n$(BOLD) %-55s WELCOME TO\n\n"
	@printf "$(BLUE) █████   █████    ███████    █████  █████  █████████  ██████████$(RESET)  █████████  █████   █████ ██████████ █████       █████      \n"
	@printf "$(BLUE)░░███   ░░███   ███░░░░░███ ░░███  ░░███  ███░░░░░███░░███░░░░░█$(RESET) ███░░░░░███░░███   ░░███ ░░███░░░░░█░░███       ░░███       \n"
	@printf "$(BLUE) ░███    ░███  ███     ░░███ ░███   ░███ ░███    ░░░  ░███  █ ░$(RESET) ░███    ░░░  ░███    ░███  ░███  █ ░  ░███        ░███       \n"
	@printf "$(BLUE) ░███████████ ░███      ░███ ░███   ░███ ░░█████████  ░██████ $(RESET)  ░░█████████  ░███████████  ░██████    ░███        ░███       \n"
	@printf "$(BLUE) ░███░░░░░███ ░███      ░███ ░███   ░███  ░░░░░░░░███ ░███░░█ $(RESET)   ░░░░░░░░███ ░███░░░░░███  ░███░░█    ░███        ░███       \n"
	@printf "$(BLUE) ░███    ░███ ░░███     ███  ░███   ░███  ███    ░███ ░███ ░  █$(RESET)  ███    ░███ ░███    ░███  ░███ ░   █ ░███      █ ░███      █\n"
	@printf "$(BLUE) █████   █████ ░░░███████░   ░░████████  ░░█████████  ██████████░$(RESET)░█████████  █████   █████ ██████████ ███████████ ███████████\n"
	@printf "$(BLUE)░░░░░   ░░░░░    ░░░░░░░      ░░░░░░░░    ░░░░░░░░░  ░░░░░░░░░░ $(RESET) ░░░░░░░░░  ░░░░░   ░░░░░ ░░░░░░░░░░ ░░░░░░░░░░░ ░░░░░░░░░░░\n"
	@printf "\n"
	@printf "$(BOLD) by cboucher and lifranco\n\n\n\n\n$(RESET)"
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)
	@printf "$(GREEN)$(BOLD)%-20s [OK]$(RESET)\n" "libft"
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(YELLOW)Compiling$(RESET) %s\n" $<
	@printf "$(GREEN)%s %-1s [OK]\n" $<
clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@printf "$(GREEN)Cleaned everything!\n$(RESET)Enjoy the Free Space!\n"
re: fclean all

.PHONY: all clean fclean re
