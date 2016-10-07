#ifndef __CREATION_H__
#define __CREATION_H__
#include <SDL2/SDL.h>

#define WINDOW_W 1280
#define WINDOW_H 720
#define ROOM_W 1024
#define ROOM_H 512
#define ROOM_X 140
#define ROOM_Y 110
#define TILE_w 32

#define LINK_FRONT "img/link_front.bmp"
#define LINK_BACK "img/link_back.bmp"
#define LINK_RIGHT "img/link_right.bmp"
#define LINK_LEFT "img/link_left.bmp"

typedef struct 	t_perso {
	SDL_Surface* load;
    SDL_Texture* texture;
    char *tile_name;
    int x;
    int y;
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
void creationPerso(s_SDL *data);

void generateAll(s_SDL *data);
void generateBg(s_SDL *data);
void generateWall(s_SDL *data);
void generatePerso(s_SDL *data);

void freeAll(s_SDL **data);
void exitAll (s_SDL *data);


#endif // __CREATION_H__