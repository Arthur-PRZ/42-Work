NAME = a.out
CC = c++ -Wall -Wextra -Werror -std=c++98
SRC = main.cpp \
      ScalarConverter.cpp \
	  utils.cpp

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) 

%.o: %.cpp	
	$(CC) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re