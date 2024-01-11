CC = cc
FLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
LIBFT_DIR = libft/
GNL = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c 
NAME = pipex
BONUS = pipex_bonus
HEADER = src/pipex.h
BONUS_HEADER = bonus/src/pipex_bonus.h
FILES = pipex_main.c pipex_read.c pipex_execute.c pipex_cmd.c pipex_function.c
SRC = $(addprefix src/, $(FILES))
OBJ = $(addprefix obj/, $(FILES:.c=.o))
BONUS_FILES = pipex_main_bonus.c pipex_read_bonus.c pipex_execute_bonus.c pipex_cmd_bonus.c pipex_function_bonus.c pipex_heredoc_bonus.c
BONUS_SRC = $(addprefix bonus/src/, $(BONUS_FILES))
BONUS_OBJ = $(addprefix bonus/obj/, $(BONUS_FILES:.c=.o))

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) libftprintf/libftprintf.a -o $(NAME)

$(LIBFT): $(LIBFT_DIR)
	@make -C $<

bonus: $(LIBFT) $(BONUS)

$(BONUS): $(BONUS_OBJ)
	$(CC) $(FLAGS) $(BONUS_OBJ) $(LIBFT) $(GNL) libftprintf/libftprintf.a -o $(NAME)

obj/%.o: src/%.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

bonus/obj/%.o: bonus/src/%.c $(BONUS_HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: bonus all $(LIBFT) clean fclean re