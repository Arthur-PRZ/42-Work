NAME_SERV = server
NAME_CLIENT = client
NAME_SERV_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT_PATH = libft/libft.a

FC_SERV = src/server.c \
			src/utils.c
FC_CLIENT = src/client.c \
			src/utils.c

FC_SERV_BONUS = src/server_bonus.c \
			src/utils_bonus.c
FC_CLIENT_BONUS = src/client_bonus.c \
			src/utils_bonus.c

FO_SERV = $(FC_SERV:.c=.o)
FO_CLIENT = $(FC_CLIENT:.c=.o)
FO_SERV_BONUS = $(FC_SERV_BONUS:.c=.o)
FO_CLIENT_BONUS = $(FC_CLIENT_BONUS:.c=.o)

all: $(NAME_SERV) $(NAME_CLIENT)

bonus: $(NAME_SERV_BONUS) $(NAME_CLIENT_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME_SERV): $(FO_SERV) $(LIBFT_PATH)
	echo "Compiling server..."
	$(CC) $(CFLAGS) $(FO_SERV) $(LIBFT_PATH) -o $(NAME_SERV)

$(NAME_CLIENT): $(FO_CLIENT) $(LIBFT_PATH)
	echo "Compiling client..."
	$(CC) $(CFLAGS) $(FO_CLIENT) $(LIBFT_PATH) -o $(NAME_CLIENT)

$(NAME_SERV_BONUS): $(FO_SERV_BONUS) $(LIBFT_PATH)
	echo "Compiling server bonus..."
	$(CC) $(CFLAGS) $(FO_SERV_BONUS) $(LIBFT_PATH) -o $(NAME_SERV_BONUS)

$(NAME_CLIENT_BONUS): $(FO_CLIENT_BONUS) $(LIBFT_PATH)
	echo "Compiling client bonus..."
	$(CC) $(CFLAGS) $(FO_CLIENT_BONUS) $(LIBFT_PATH) -o $(NAME_CLIENT_BONUS)

$(LIBFT_PATH):
	make -sC libft/

clean:
	echo "Cleaning object files"
	rm -f $(FO_SERV) $(FO_CLIENT) $(FO_SERV_BONUS) $(FO_CLIENT_BONUS)
	make clean -sC libft/

fclean: clean
	echo "Removing executables"
	rm -rf $(NAME_SERV) $(NAME_CLIENT) $(NAME_SERV_BONUS) $(NAME_CLIENT_BONUS)
	make fclean -sC libft/

re: fclean all

re_bonus: fclean bonus

.PHONY: all bonus clean fclean re re_bonus
