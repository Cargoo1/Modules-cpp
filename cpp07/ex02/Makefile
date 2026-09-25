SRCS = main.cpp
INCLUDES = Array.hpp
C++ = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror
OBJS = ${SRCS:.cpp=.o}
NAME = Array
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(C++) $(OBJS) -o $(NAME)

$(OBJS): $(SRCS) $(INCLUDES)
	$(C++) $(CFLAGS) -c $(SRCS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean $(NAME)
