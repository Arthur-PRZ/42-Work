# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: artperez <artperez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/20 09:13:42 by artperez          #+#    #+#              #
#    Updated: 2024/11/20 10:56:19 by artperez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

FC = printf.c \
	functions.c \
	functions2.c

FO = $(FC:.c=.o)

all: $(NAME)

$(NAME): $(FO) 
	ar rcs $(NAME) $(FO)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(FO)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re