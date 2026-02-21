SRCS = main.cpp AMateria.cpp ICharacter.cpp Character.cpp Garbage.cpp Ice.cpp \
	   Cure.cpp IMateriaSource.cpp MateriaSource.cpp
INCLUDES = AMateria.hpp ICharacter.hpp Character.hpp Garbage.hpp Ice.hpp Cure.hpp \
		   IMateriaSource.hpp MateriaSource.hpp
CFLAGS = -Werror -Wall -Wextra -std=c++98 -g3
OBJS = ${SRCS:.cpp=.o}
NAME = thegame

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
