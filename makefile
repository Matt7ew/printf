# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjorge <mjorge@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/14 14:32:17 by matthewjorg       #+#    #+#              #
#    Updated: 2025/05/17 02:52:27 by mjorge           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile for libftprintf.a
NAME = libftprintf.a
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Iincludes -I$(LIBFT_DIR)/includes

SRCS = ft_strbase.c printf.utils.c ft_printf_fl.c printf.c ft_bigX.c
OBJS_DIR = obj
OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@ar rcs $@ $(OBJS)
	@echo "libftprintf.a compiled ✅"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJS_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "Objects cleaned 🧹"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "Full clean 🧼"

re: fclean all

.PHONY: all clean fclean re