SRCS = main.cpp Fixed.cpp FixedOverloads.cpp FixedOverloadFunctions.cpp
INCLUDES = Fixed.hpp
CFLAGS = -Werror -Wall -Wextra -std=c++98
OBJS = ${SRCS:.cpp=.o}
NAME = Fixed-point

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
