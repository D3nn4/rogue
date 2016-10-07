#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>

#include "creation.h"
#include "animation.h"

void generatePerso(s_SDL *data)
{
	s_perso *perso = data->perso;
	SDL_Rect tile = {perso->x, perso->y, TILE_w, TILE_w};
	perso->load = SDL_LoadBMP(perso->tile_name);
	SDL_SetColorKey(perso->load, SDL_TRUE, SDL_MapRGB(perso->load->format, 255, 255, 255));
	if ( !perso->load ) {
	        fprintf(stdout,"Échec de chargement du perso (%s)\n",SDL_GetError());
	        exitAll(data);
	}
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
	data->perso->x = center_x;
	data->perso->y = center_y;
	data->perso->health = 100;
	data->perso->damage = 10;
	data->perso->tile_name = LINK_FRONT;
	generatePerso(data);
	
}