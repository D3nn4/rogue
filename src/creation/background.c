#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>

#include "creation.h"

void createBg(s_SDL *data)
{
	SDL_Rect bg = {140, 110, 1000, 500};
	data->bg_load = SDL_LoadBMP("img/stonefloor.bmp");
	if ( !data->bg_load ) {
	        fprintf(stdout,"Échec de chargement du bg (%s)\n",SDL_GetError());
	        exit(0);
	}
	data->bg_texture = SDL_CreateTextureFromSurface(data->renderer, data->bg_load); 
	if ( !data->bg_texture ) {
            fprintf(stdout,"Échec de création de la texture du bg (%s)\n",SDL_GetError());
            exit(0);
    }
	SDL_RenderCopy(data->renderer,data->bg_texture,NULL,&bg);
	SDL_SetRenderDrawColor(data->renderer, 0, 0, 0, 100);
}