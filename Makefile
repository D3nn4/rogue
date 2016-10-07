NAME = rogue

SRC = 	src/main.c \
		src/creation/* 
		
LDFLAGS=-lSDL2

HEADER = -Iinclude/

OBJDIR = build

all : $(NAME)

$(NAME) : 
	gcc -ggdb3 -Wall -Wextra $(HEADER) -c $(SRC) 
	gcc -o $(NAME)   *.o ${LDFLAGS}
	mv *.o $(OBJDIR)

clean : 
	rm -f $(OBJDIR)/*.o

fclean : clean
	rm -f $(NAME)

re : fclean all
