NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I./libft
LIBFT = ./libft/libft.a

SRCS = ft_printf.c print_hex.c print_ptr.c print_int.c print_uint.c print_chr.c print_str.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft
	cp ./libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)


%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make -C ./libft clean
	rm -f $(OBJS)


fclean: clean
	make -C ./libft fclean
	rm -f $(NAME)

re: fclean all

test: fclean all
	cc -g main.c libftprintf.a -I. -I./libft -L./libft -lft
	./a.out
# 	rm ./a.out