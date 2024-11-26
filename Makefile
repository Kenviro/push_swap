NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3

SRC = error.c push_swap.c valid_arg.c

OBJ = $(SRC:.c=.o)

HEADERS = push_swap.h

LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/Libft.a

INCLUDES = -I $(LIBFT_DIR)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all