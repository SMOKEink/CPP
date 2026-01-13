NAME = 

FLAGS = -Wall -Wextra -Werror -std=c++98

INCLUDES = Weapon.hpp HumanA.hpp HumanB.hpp

SRCS = main.c Weapon.cpp HumanA.cpp HumanB.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	c++ $(FLAGS) -c $< -o $@

$(NAME): $(OBJS) $(INCLUDES)
	c++ $(FLAGS) $(OBJS) -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
