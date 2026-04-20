NAME = push_swap
BONUS_NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

INC = -I inc -I $(LIBFT_DIR)

# ===================== Source files =====================
SRC_DIR = src

SRCS = $(SRC_DIR)/main.c \
       $(SRC_DIR)/parse.c \
       $(SRC_DIR)/parse_utils.c \
       $(SRC_DIR)/stack_init.c \
       $(SRC_DIR)/stack_utils.c \
       $(SRC_DIR)/stack_utils2.c \
       $(SRC_DIR)/errorandfree.c \
       $(SRC_DIR)/op_swap.c \
       $(SRC_DIR)/op_push.c \
       $(SRC_DIR)/op_rotate.c \
       $(SRC_DIR)/op_reverse.c \
       $(SRC_DIR)/sort_tiny.c \
       $(SRC_DIR)/sort_small.c \
       $(SRC_DIR)/sort_simple.c \
       $(SRC_DIR)/sort_medium.c \
       $(SRC_DIR)/sort_medium_utils.c \
       $(SRC_DIR)/sort_complex.c \
       $(SRC_DIR)/sort_complex_cost.c \
       $(SRC_DIR)/sort_complex_move.c \
       $(SRC_DIR)/sort_complex_target.c \
       $(SRC_DIR)/sort_complex_utils.c \
       $(SRC_DIR)/disorder.c \
       $(SRC_DIR)/sort_dispatch.c \
       $(SRC_DIR)/bench.c

# Shared sources (everything except main.c)
SHARED_SRCS = $(SRC_DIR)/parse.c \
              $(SRC_DIR)/parse_utils.c \
              $(SRC_DIR)/stack_init.c \
              $(SRC_DIR)/stack_utils.c \
              $(SRC_DIR)/stack_utils2.c \
              $(SRC_DIR)/errorandfree.c

BONUS_SRCS = $(SRC_DIR)/checker.c \
             $(SRC_DIR)/checker_ops.c \
             $(SHARED_SRCS)

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# ===================== Rules =====================
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(INC) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(INC) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c inc/push_swap.h
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
