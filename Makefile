NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3

SRC = error.c push_swap.c valid_arg.c valid_string.c push_op.c \
swap_op.c reverse_r_op.c rotate_op.c parse.c sort_small.c lst.c \
index.c quick_sort.c utils.c

OBJ = $(SRC:.c=.o)

HEADERS = push_swap.h

LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/Libft.a

INCLUDES = -I $(LIBFT_DIR)

GREEN = \033[32m
RESET = \033[0m

all: header $(LIBFT) $(NAME)

header:
	@echo "$(GREEN)"
	@echo "----------------------------------------------------------------"
	@echo "|     _     ___       __                _       _            __|"
	@echo "|    (_)___/ (_)___  / /_   ____  _____(_)___ _(_)___  ___  / /|"
	@echo "|   / / __  / / __ \/ __/  / __ \/ ___/ / __ \`/ / __ \/ _ \/ / |"
	@echo "|  / / /_/ / / /_/ / /_   / /_/ / /  / / /_/ / / / / /  __/ /  |"
	@echo "| /_/\__,_/_/\____/\__/   \____/_/  /_/\__, /_/_/ /_/\___/_/   |"
	@echo "|                                     /____/                   |"
	@echo "----------------------------------------------------------------"
	@echo "$(RESET)"

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ) $(LIBFT_DIR)/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all
