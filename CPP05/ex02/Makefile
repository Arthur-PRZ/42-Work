NAME = a.out
CC = c++ -Wall -Wextra -Werror -std=c++98
SRC = src/main.cpp \
      src/Bureaucrat.cpp \
      src/ShrubberyCreationForm.cpp \
      src/PresidentialPardonForm.cpp \
      src/RobotomyRequestForm.cpp \
      src/AForm.cpp
OBJ = $(SRC:.cpp=.o)

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
