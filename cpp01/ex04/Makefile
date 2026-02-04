SRCS = main.cpp
INCLUDES =
OBJS = $(SRCS:.cpp=.o)
CC = c++
CFLAGS = -Werror -Wall -Wextra -std=c++98 -g3
NAME = violence

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

$(OBJS): $(SRCS) $(INCLUDES)
	$(CC) $(CFLAGS) -c $(SRCS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
