SRCS = main.cpp Bureaucrat.cpp
INCLUDES = Bureaucrat.hpp
CFLAGS = -Werror -Wall -Wextra -std=c++98 -g3
OBJS = ${SRCS:.cpp=.o}
NAME = exceptions

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
