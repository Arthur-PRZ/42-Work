# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: artperez <artperez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 09:42:21 by artperez          #+#    #+#              #
#    Updated: 2025/02/03 10:24:12 by artperez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT_PATH = libft/libft.a
FC = src/main.c \
     src/utils.c \

FO = $(FC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_PATH):
	make -sC libft/

$(MLX_PATH):
	make -sC minilibx-linux/

$(NAME): $(FO) $(LIBFT_PATH) $(MLX_PATH)
	echo "Compiling push_swap"
	$(CC) $(CFLAGS) $(FO) $(LIBFT_PATH) -o $(NAME)

clean:
	rm -f $(FO)
	make clean -sC libft/

fclean: clean
	rm -rf $(NAME)
	make fclean -sC libft/

re: fclean all

.PHONY: all clean fclean re