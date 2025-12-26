NAME    = push_swap

CC      = cc
CFLAGS  = -Wall -Wextra -Werror
CPPFLAGS= -Iincludes

SRC_DIR = src

SRCS = \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/utils.c \
	$(SRC_DIR)/parse.c \
	$(SRC_DIR)/compress.c \
	$(SRC_DIR)/stack.c \
	$(SRC_DIR)/ops.c \
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
