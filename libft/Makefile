NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_isdigit.c ft_strlen.c ft_strcmp.c ft_atoi.c ft_split.c \
       ft_putstr_fd.c ft_putchar_fd.c ft_putnbr_fd.c ft_strdup.c \
       ft_substr.c ft_strjoin.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
