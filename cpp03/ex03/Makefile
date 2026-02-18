SRCS = main.cpp ClapTrap.cpp FragTrap.cpp ScravTrap.cpp DiamondTrap.cpp
INCLUDES = ClapTrap.hpp FragTrap.hpp ScravTrap.hpp DiamondTrap.hpp
CFLAGS = -Wshadow -Wno-shadow -Werror -Wall -Wextra -std=c++98
OBJS = ${SRCS:.cpp=.o}
NAME = FragTrap

all: $(NAME)

$(NAME): $(OBJS)
	g++ -o $(NAME) $(OBJS)

$(OBJS): $(SRCS) $(INCLUDES)
	g++ $(CFLAGS) -c $(SRCS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
