# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Camille <private_mail>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/20 10:13:22 by Camille           #+#    #+#              #
#    Updated: 2025/11/11 10:15:00 by Camille          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

CC := cc

CFLAGS := -Wall -Werror -Wextra

AR := ar

ARFLAGS := rcs

SRCS := ft_printf.c print_char.c print_string.c print_pointer.c \
		print_decimal.c print_unsigned_decimal.c print_hexadecimal.c \
		print_percent_sign.c

OBJS := $(SRCS:.c=.o)

LIBFT_DIR := libft/

LIBFT := $(LIBFT_DIR)libft.a

MAKEFLAGS += --no-print-directory

ifeq ($(DEBUG),1)
    CFLAGS += -g
endif

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@cp $(LIBFT) $(NAME)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
