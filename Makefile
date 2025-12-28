# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macbookpro2019 <macbookpro2019@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/28 13:54:18 by macbookpro2       #+#    #+#              #
#    Updated: 2025/12/28 14:06:17 by macbookpro2      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = push_swap

CC      = cc
CFLAGS  = -Wall -Wextra -Werror
CPPFLAGS= -Iincludes

SRC_DIR = src

SRCS = \
    $(SRC_DIR)/main.c \
    $(SRC_DIR)/utils.c \
    $(SRC_DIR)/parse_args.c \
    $(SRC_DIR)/parse_utils.c \
    $(SRC_DIR)/compress.c \
    $(SRC_DIR)/op_utils.c \
    $(SRC_DIR)/op_swap.c \
    $(SRC_DIR)/op_push.c \
    $(SRC_DIR)/op_rotate.c \
    $(SRC_DIR)/op_rev_rotate.c \
    $(SRC_DIR)/sort_helpers.c \
    $(SRC_DIR)/sort_small.c \
    $(SRC_DIR)/sort_radix.c \
    $(SRC_DIR)/sort.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c includes/push_swap.h
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
