#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>

#include "creation.h"
#include "animation.h"

void generatePerso(s_SDL *data, s_perso *perso)
{
	SDL_Rect tile = {perso->box.x, perso->box.y, TILE_w, TILE_w};
	perso->load = SDL_LoadBMP(perso->tile_name);
	if ( !perso->load ) {
	        fprintf(stdout,"Échec de chargement du perso (%s)\n",SDL_GetError());
	        exitAll(data);
	}
	SDL_SetColorKey(perso->load, SDL_TRUE, SDL_MapRGB(perso->load->format, 0, 0, 255));
	perso->texture = SDL_CreateTextureFromSurface(data->renderer, perso->load); 
	if ( !perso->texture ) {
            fprintf(stdout,"Échec de création de la texture du perso (%s)\n",SDL_GetError());
            exitAll(data);
    }
    SDL_RenderCopy(data->renderer,perso->texture,NULL,&tile);
}
void creationPerso(s_SDL *data)
{
	int center_x = ROOM_W/2 + ROOM_X;
	int center_y = ROOM_H/2 + ROOM_Y;
	data->perso = malloc(sizeof(*data->perso));
	if (!data->perso){
		fprintf(stderr,"Erreur de création du perso\n");
		exitAll(data);
	}
	data->perso->box.x = center_x;
	data->perso->box.y = center_y;
	data->perso->box.w = TILE_w;
	data->perso->box.h = TILE_w;
	data->perso->health = 100;
	data->perso->damage = 10;
	data->perso->tile_name = LINK_FRONT;
	generatePerso(data, data->perso);
	
}