SRCS = main.cpp RPN.cpp
INCLUDES = RPN.hpp
C++ = c++
CFLAGS = -std=c++98 -Wall -Werror -Wextra -g3
OBJS = ${SRCS:.cpp=.o}
RM = rm -f
NAME = RPN

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
