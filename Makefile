CC = cc
FLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
LIBFT_DIR = libft/
GNL = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c 
NAME = pipex
BONUS = pipex_bonus
HEADER = src/pipex.h
BONUS_HEADER = bonus/src/pipex_bonus.h
SRC_FILES = pipex_main.c pipex_read.c pipex_execute.c pipex_cmd.c pipex_function.c
SRC = $(addprefix src/, $(SRC_FILES))
O_SRC = $(addprefix obj/, $(SRC_FILES:.c=.o))
BONUS_SRC = pipex_main_bonus.c pipex_read_bonus.c pipex_execute_bonus.c pipex_cmd_bonus.c pipex_function_bonus.c pipex_heredoc_bonus.c
O_BONUS_SRC = $(BONUS_SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(NAME): $(O_SRC) $(HEADER)
	$(CC) $(FLAGS) $(O_SRC) $(LIBFT) libftprintf/libftprintf.a -o $(NAME)

$(LIBFT): $(LIBFT_DIR)
	@make -C $<

bonus: $(LIBFT) $(BONUS)

$(BONUS): $(O_BONUS_SRC) $(BONUS_HEADER)
	$(CC) $(FLAGS) $(O_BONUS_SRC) $(LIBFT) $(GNL) libftprintf/libftprintf.a -o $(NAME)

obj/%.o: src/%.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(O_SRC) $(O_BONUS_SRC)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: bonus all $(LIBFT) clean fclean re