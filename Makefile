NAME = ft_printf
CFLAGS = -Wall -Wextra -Werror
CC = cc

test: $(NAME)
	./$(NAME)

$(NAME): ft_printf.c ./libft/libft.a
	make -C ./libft
	$(CC) $(CFLAGS) -g ft_printf.c -I./libft -L./libft -lft -o $(NAME)

clean:
	make -C ./libft clean
	rm -rf *.out *.o ft_printf