#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>

#include "creation.h"

void creationWin(s_SDL *data)
{
	data->window = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_UNDEFINED,
        							SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);	
    if( !data->window ) {
	 	fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
		exitAll(data);
    }
}