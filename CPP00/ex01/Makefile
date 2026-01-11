NAME = PhoneBook

C++FLAGS = -Wall -Wextra -Werror -std=c++98

INCLUDES = Contact.hpp PhoneBook.hpp

SRCS = PhoneBook.cpp main.cpp Contact.cpp
OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(C++FLAGS) $(OBJS) -o $@

%.o: %.cpp $(INCLUDES)
	c++ $(C++FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all