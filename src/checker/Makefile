NAME = checker

CC = cc
INCLUDES = ../../includes
CFLAGS = -Wextra -Werror -Wall -g -I$(INCLUDES)
COMPILE = $(CC) $(CFLAGS) -c 
ARCHIVE = ar rc $(NAME)

LIBFT_DIR = ../../libft.plus

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
YELLOW=\033[0;33m
RESET=\033[0m

SRC =	../algo.c \
		../minisort.c \
		../find_bestmoves.c \
		../lis.c \
		../parsing.c \
		../moves/push.c \
		../moves/r-rotate.c \
		../moves/rotate.c \
		../moves/swap.c \
		../algo_utils.c \
		../utils.c \
		./moves/push.c \
		./moves/r-rotate.c \
		./moves/rotate.c \
		./moves/swap.c \
		./checker_parsing.c \
		./checker_main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

libft:
	make all -C $(LIBFT_DIR)

$(NAME): libft $(OBJ)
	$(CC) $(CFLAGS) -I. -I$(INCLUDES) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "$(GREEN)	CHECKER COMPILED! ✅$(RESET)"

RM = rm -f

clean:
	$(RM) $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all