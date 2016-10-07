#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>

#include "creation.h"

void creationRenderer(s_SDL *data)
{
	data->renderer = SDL_CreateRenderer(data->window,-1,SDL_RENDERER_ACCELERATED); // Création d'un SDL_Renderer utilisant l'accélération matérielle
	if ( !data->renderer ) {
	    fprintf(stdout,"Échec de création du renderer (%s)\n",SDL_GetError());
		exitAll(data);
	}

}
