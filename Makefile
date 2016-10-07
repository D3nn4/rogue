NAME = rogue

SRC = 	src/main.c \
		src/creation/rogue.c \
		src/creation/renderer.c \
		src/creation/window.c \
		src/creation/background.c \
		src/creation/wall.c \
		src/creation/perso.c \
		src/creation/free.c \
		src/event/keyboard.c \
		src/event/event.c \
		src/animation/movement.c
		
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
