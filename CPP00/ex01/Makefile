NAME = PhoneBook

FLAGS = -Wall -Wextra -Werror -std=c++98

INCLUDES = Contact.hpp PhoneBook.hpp

SRCS = PhoneBook.cpp main.cpp Contact.cpp
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

.PHONY: clean