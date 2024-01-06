CC = cc
# FLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
LIBFT_DIR = libft/
NAME = pipex
HEADER = pipex.h
BONUS_HEADER = pipex_bonus.h
SRC = pipex_main.c pipex_read.c pipex_execute.c pipex_utils.c pipex_cmd.c
O_SRC = $(SRC:.c=.o)
BONUS_SRC = pipex_main_bonus.c pipex_read_bonus.c pipex_execute_bonus.c pipex_utils_bonus.c pipex_cmd_bonus.c
O_BONUS_SRC = $(BONUS_SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT): $(LIBFT_DIR)
	@make -C $<

$(NAME): $(O_SRC) $(HEADER)
	$(CC) $(FLAGS) $(O_SRC) $(LIBFT) libftprintf/libftprintf.a -o $(NAME)

bonus: $(LIBFT) $(BONUS)

$(BONUS): $(O_BONUS_SRC) $(BONUS_HEADER)
	$(CC) $(FLAGS) $(O_BONUS_SRC) $(LIBFT) libftprintf/libftprintf.a -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(O_SRC)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all $(NAME) $(LIBFT) clean fclean re
