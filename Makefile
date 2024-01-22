CC = cc
FLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
LIBFT_DIR = libft/
GNL = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

NAME = pipex
SRC_DIR = src/
OBJ_DIR = obj/
HEADER = $(SRC_DIR)pipex.h
FILES = pipex_main.c pipex_cmd.c pipex_function.c
SRC = $(addprefix $(SRC_DIR), $(FILES))
OBJ = $(addprefix $(OBJ_DIR), $(FILES:.c=.o))

BONUS = pipex_bonus
BONUS_SRC_DIR = bonus/src/
BONUS_OBJ_DIR = bonus/obj/
BONUS_HEADER = $(BONUS_SRC_DIR)pipex_bonus.h
BONUS_FILES = pipex_main_bonus.c pipex_execute_bonus.c pipex_cmd_bonus.c pipex_function_bonus.c pipex_heredoc_bonus.c
BONUS_SRC = $(addprefix $(BONUS_SRC_DIR), $(BONUS_FILES))
BONUS_OBJ = $(addprefix $(BONUS_OBJ_DIR), $(BONUS_FILES:.c=.o))

all: $(LIBFT) $(OBJ_DIR) $(NAME)

$(LIBFT): $(LIBFT_DIR)
	@make -C $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

bonus: $(LIBFT) $(BONUS_OBJ_DIR) $(BONUS)

$(BONUS_OBJ_DIR):
	mkdir -p $(BONUS_OBJ_DIR)

$(BONUS): $(BONUS_OBJ)
	$(CC) $(FLAGS) $(BONUS_OBJ) $(LIBFT) $(GNL) -o $(BONUS)

$(BONUS_OBJ_DIR)%.o: $(BONUS_SRC_DIR)%.c $(BONUS_HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)
	rmdir $(OBJ_DIR) $(BONUS_OBJ_DIR) 2>/dev/null || true

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all $(LIBFT) bonus clean fclean re