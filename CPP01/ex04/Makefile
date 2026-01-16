NAME = replace

FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

main.o: main.cpp
	c++ $(FLAGS) -c $< -o $@

$(NAME): main.o
	c++ $(FLAGS) main.o -o $(NAME)

clean:
	rm -f main.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean