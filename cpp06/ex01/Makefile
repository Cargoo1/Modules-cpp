SRCS = main.cpp Serializer.cpp
INCLUDES = Serializer.hpp
C++ = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3
NAME = serializer
OBJS = ${SRCS:.cpp=.o}

all: $(NAME)

$(NAME): $(OBJS)
	$(C++) -o $(NAME) $(OBJS)

$(OBJS): $(SRCS) $(INCLUDES)
	$(C++) $(CFLAGS) -c $(SRCS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
