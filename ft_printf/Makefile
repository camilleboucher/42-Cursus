# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Camille <private_mail>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/20 10:13:22 by Camille           #+#    #+#              #
#    Updated: 2025/11/08 18:56:46 by Camille          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

CC := cc

CFLAGS := -Wall -Werror -Wextra

AR := ar

ARFLAGS := rcs

SRCS := ft_printf.c print_char.c print_string.c print_pointer.c

OBJS := $(SRCS:.c=.o)

INCLUDE_DIR := .

LIBFT := libft.a

LIBFT_DIR := libft

MAKEFLAGS += --no-print-directory

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_DIR)/$(LIBFT)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS) $(LIBFT_DIR)/$(LIBFT)

%.o: %.c
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(LIBFT_DIR)/$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) all

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
