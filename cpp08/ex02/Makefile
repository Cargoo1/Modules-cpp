SRCS = main.cpp
INCLUDES = MutantStack.hpp
C++ = c++
CFLAGS = -std=c++98 -Wall -Werror -Wextra
OBJS = ${SRCS:.cpp=.o}
RM = rm -f
NAME = MutantStack

all: $(NAME)

$(NAME): $(OBJS)
	$(C++) $(OBJS) -o $(NAME)

$(OBJS): $(SRCS) $(INCLUDES)
	$(C++) $(CFLAGS) -c $(SRCS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
