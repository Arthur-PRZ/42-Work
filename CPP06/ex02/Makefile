NAME = a.out
CC = c++ -Wall -Wextra -Werror -std=c++98
SRCS = srcs/Base.cpp \
      srcs/main.cpp 

OBJ = $(SRCS:.cpp=.o)

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