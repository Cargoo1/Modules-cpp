SRCS = main.cpp Zombie.cpp newZombie.cpp randomChumps.cpp
INCLUDES = Zombie.hpp
OBJS = $(SRCS:.cpp=.o)
CC = c++
CFLAGS = -Werror -Wall -Wextra -std=c++98
NAME = brainz

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
