CC = cc
# FLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
LIBFT_DIR = libft/
NAME = pipex
HEADER = pipex.h
SRC = pipex_main.c
O_SRC = $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT): $(LIBFT_DIR)
	make -C $<

$(NAME): $(O_SRC) $(HEADER)
	$(CC) $(FLAGS) $(O_SRC) $(LIBFT) libftprintf.a -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(O_SRC)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all $(NAME) $(LIBFT) clean fclean re