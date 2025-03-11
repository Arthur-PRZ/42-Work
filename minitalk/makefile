NAME_SERV = server
NAME_CLIENT = client

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT_PATH = libft/libft.a
FC_SERV = src/server.c \
			src/utils.c
FC_CLIENT = src/client.c \
			src/utils.c

FO_SERV = $(FC_SERV:.c=.o)
FO_CLIENT = $(FC_CLIENT:.c=.o)

all: $(NAME_SERV) $(NAME_CLIENT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME_SERV): $(FO_SERV) $(LIBFT_PATH)
	echo "Compiling server..."
	$(CC) $(CFLAGS) $(FO_SERV) $(LIBFT_PATH) -o $(NAME_SERV)

$(NAME_CLIENT): $(FO_CLIENT) $(LIBFT_PATH)
	echo "Compiling client..."
	$(CC) $(CFLAGS) $(FO_CLIENT) $(LIBFT_PATH) -o $(NAME_CLIENT)

$(LIBFT_PATH):
	make -sC libft/

clean:
	echo "Cleaning object files"
	rm -f $(FO_SERV) $(FO_CLIENT)
	make clean -sC libft/

fclean: clean
	echo "Removing executables"
	rm -rf $(NAME_SERV) $(NAME_CLIENT)
	make fclean -sC libft/

re: fclean all

.PHONY: all clean fclean re
