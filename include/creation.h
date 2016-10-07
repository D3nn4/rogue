#ifndef __CREATION_H__
#define __CREATION_H__
#include <SDL2/SDL.h>

typedef struct 	t_SDL {
	SDL_Window* window;
	SDL_Renderer *renderer;
	SDL_Surface* perso_load;
    SDL_Texture* perso_texture;
    SDL_Surface* bg_load;
    SDL_Texture* bg_texture;
}				s_SDL;
void rogue();
void creationWin(s_SDL *data);
void creationRenderer(s_SDL *data);
void createBg(s_SDL *data);
void exitAll (s_SDL *data);


#endif // __CREATION_H__