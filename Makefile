NAME = push_swap
NAME_BONUS = checker

CC = cc
INCLUDES = ./includes
CFLAGS = -Wextra -Werror -Wall -g -I$(INCLUDES)
COMPILE = $(CC) $(CFLAGS) -c
ARCHIVE = ar rc $(NAME)

LIBFT_DIR = ./libft.plus

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
YELLOW=\033[0;33m
RESET=\033[0m

SRC =	./src/algo.c \
		./src/minisort.c \
		./src/find_bestmoves.c \
		./src/lis.c \
		./src/parsing.c \
		./src/moves/push.c \
		./src/moves/r-rotate.c \
		./src/moves/rotate.c \
		./src/moves/swap.c \
		./src/utils.c \
		./src/main.c 

SRC_BONUS =	./src/parsing.c \
			./src/utils.c \
			./src/checker/moves/push.c \
			./src/checker/moves/rotate.c \
			./src/checker/moves/r-rotate.c \
			./src/checker/moves/swap.c \
			./src/checker/checker_parsing.c \
			./src/checker/checker_main.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

libft:
	make all -C $(LIBFT_DIR)

$(NAME): libft $(OBJ)
	$(CC) $(CFLAGS) -I. -I$(INCLUDES) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "$(GREEN)	PUSH SWAP COMPILED! 🧮✅$(RESET)"

bonus: $(OBJ_BONUS)
	$(CC) $(CFLAGS) -I. -I$(INCLUDES) $(OBJ_BONUS) -L$(LIBFT_DIR) -lft -o $(NAME_BONUS)
	@echo "$(GREEN)	CHECKER COMPILED! ✅$(RESET)"

RM = rm -f

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_BONUS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

re: fclean all