#ifndef __CREATION_H__
#define __CREATION_H__
#include <SDL2/SDL.h>

#define ROOM_W 1024
#define ROOM_H 512
#define ROOM_X 140
#define ROOM_Y 110
#define TILE_w 32

typedef struct 	t_perso {
	
	SDL_Surface* perso_load;
    SDL_Texture* perso_texture;
    int x_perso;
    int y_perso;
    int health;
    int damage;
}				s_perso;

typedef struct 	t_SDL {
	SDL_Window* window;
	SDL_Renderer *renderer;
    SDL_Surface* bg_load;
    SDL_Texture* bg_texture;
    SDL_Surface* wall_load;
    SDL_Texture* wall_texture;
    s_perso *perso;
}				s_SDL;

void rogue();
void creationWin(s_SDL *data);
void creationRenderer(s_SDL *data);
void generateRenderer(s_SDL *data);
void generateBg(s_SDL *data);
void generateWall(s_SDL *data);
void exitAll (s_SDL *data);


#endif // __CREATION_H__