NAME = ScalarConverter

CXX = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp ScalarConverter.cpp PrintType.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp ScalarConverter.hpp PrintType.hpp
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
