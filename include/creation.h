#ifndef __CREATION_H__
#define __CREATION_H__
#include <SDL2/SDL.h>

#include "animation.h"

#define WINDOW_W 1280
#define WINDOW_H 720
#define ROOM_W 1024
#define ROOM_H 512
#define ROOM_X 140
#define ROOM_Y 110
#define TILE_w 32
#define NB_TILE_W 32
#define NB_TILE_H 16

#define WALL_TILE "img/grass_wall.bmp"
#define FLOOR_TILE "img/grass_floor.bmp"


typedef enum tile_type {
	WALL,
	FLOOR
} t_tile_type;

typedef struct 	t_perso {
	SDL_Surface* load;
    SDL_Texture* texture;
    char *tile_name;
    SDL_Rect box;
   // s_anim *anim;
    int health;
    int damage;
}				s_perso;

typedef struct 	s_tile {
	SDL_Surface* load;
    SDL_Texture* texture;
    char *path;
    t_tile_type type;
}				t_tile;

typedef struct 	t_SDL {
	t_tile_type **map;
	SDL_Window *window;
	SDL_Renderer *renderer;
    t_tile *floor;    
    t_tile *wall;
    s_perso *perso;
    s_perso *mob;
}				s_SDL;

void rogue();
void creationWin(s_SDL *data);
void creationRenderer(s_SDL *data);
void creationPerso(s_SDL *data);
void creationMob(s_SDL *data);
void createMap(s_SDL *data);
void getTile(t_tile *tile, s_SDL *data);
void getMapEnum (s_SDL *data);
void createTTiles(s_SDL *data);

void generateAll(s_SDL *data);
void generateMap(s_SDL *data);
void generatePerso(s_SDL *data, s_perso *perso);


void freeAll(s_SDL **data);
void exitAll (s_SDL *data);


#endif // __CREATION_H__