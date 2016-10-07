NAME = test

SRC = 	test.c

LDFLAGS=-lSDL2

HEADER = 

OBJDIR = build

all : $(NAME)

$(NAME) : 
	gcc -ggdb3 -Wall -Wextra $(HEADER) -c $(SRC) 
	gcc -o $(NAME)   *.o ${LDFLAGS}

clean : 
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all
