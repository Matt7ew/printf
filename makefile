# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjorge <mjorge@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/14 14:32:17 by matthewjorg       #+#    #+#              #
#    Updated: 2025/05/17 08:06:46 by mjorge           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC_DIR = srcs
OBJ_DIR = obj
INCLUDES = -Iincludes

# Updated to match the actual filename - removed extra dot from ft_itoa..c
SRCS = \
	$(SRC_DIR)/ft_printf.c \
	$(SRC_DIR)/handlers/handle_char.c \
	$(SRC_DIR)/handlers/handle_str.c \
	$(SRC_DIR)/handlers/handle_ptr.c \
	$(SRC_DIR)/handlers/handle_nbr.c \
	$(SRC_DIR)/handlers/handle_hex.c \
	$(SRC_DIR)/handlers/handle_unsigned.c \
	$(SRC_DIR)/utils/ft_strbase.c \
	$(SRC_DIR)/utils/ft_strlen.c \
	$(SRC_DIR)/utils/ft_itoa.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: obj $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/handlers
	@mkdir -p $(OBJ_DIR)/utils

$(NAME): $(OBJS)
	@ar rcs $@ $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re