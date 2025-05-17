# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjorge <mjorge@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/14 14:32:17 by matthewjorg       #+#    #+#              #
#    Updated: 2025/05/17 05:37:13 by mjorge           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft/libft.a
SRC_DIR = srcs
OBJ_DIR = obj
INCLUDES = -Iincludes -Ilibft

SRCS = \
	$(SRC_DIR)/ft_printf.c \
	$(SRC_DIR)/handlers/handle_char.c \
	$(SRC_DIR)/handlers/handle_str.c \
	$(SRC_DIR)/handlers/handle_ptr.c \
	$(SRC_DIR)/handlers/handle_nbr.c \
	$(SRC_DIR)/handlers/handle_hex.c \
	$(SRC_DIR)/handlers/handle_unsigned.c \
	$(SRC_DIR)/utils/ft_strbase.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	ar rcs $@ $(OBJS)

$(LIBFT):
	$(MAKE) -C libft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re