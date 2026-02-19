SRCS = main.cpp Animal.cpp Cat.cpp Dog.cpp
INCLUDES = Animal.hpp Cat.hpp Dog.hpp
CFLAGS = -Werror -Wall -Wextra -std=c++98 -g3
OBJS = ${SRCS:.cpp=.o}
NAME = animal

all: $(NAME)

$(NAME): $(OBJS)
	c++ -o $(NAME) $(OBJS)

$(OBJS): $(SRCS) $(INCLUDES)
	c++ $(CFLAGS) -c $(SRCS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
