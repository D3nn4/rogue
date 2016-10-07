#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>

#include "creation.h"

void creationWin(s_SDL *data)
{
	data->window = SDL_CreateWindow("Rogue",SDL_WINDOWPOS_UNDEFINED,
        							SDL_WINDOWPOS_UNDEFINED, WINDOW_W, WINDOW_H,
        							SDL_WINDOW_SHOWN);	
    if( !data->window ) {
	 	fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
		exitAll(data);
    }
}