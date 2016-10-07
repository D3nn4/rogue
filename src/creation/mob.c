#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>

#include "creation.h"
#include "animation.h"
/*
int generateCoord (int min, int max)
{
	srand(time(NULL));
	int coord = ( rand() % max ) + 1;
	if (coord < min)
		coord += min;
	return coord;
}
void generateMob(s_SDL *data)
{
	s_perso *mob = data->mob;
	SDL_Rect tile = {mob->x, mob->y, TILE_w, TILE_w};
	mob->load = SDL_LoadBMP(mob->tile_name);
	SDL_SetColorKey(mob->load, SDL_TRUE, SDL_MapRGB(mob->load->format, 255, 255, 255));
	if ( !mob->load ) {
	        fprintf(stdout,"Échec de chargement du mob (%s)\n",SDL_GetError());
	        exitAll(data);
	}
	mob->texture = SDL_CreateTextureFromSurface(data->renderer, mob->load); 
	if ( !mob->texture ) {
            fprintf(stdout,"Échec de création de la texture du mob (%s)\n",SDL_GetError());
            exitAll(data);
    }
    SDL_RenderCopy(data->renderer,mob->texture,NULL,&tile);
}
void creationMob(s_SDL *data)
{
	int center_x = ROOM_W/2 + ROOM_X;
	int center_y = ROOM_H/2 + ROOM_Y;
	data->mob = malloc(sizeof(*data->mob));
	if (!data->mob){
		fprintf(stderr,"Erreur de création du mob\n");
		exitAll(data);
	}
	data->mob->x = generateCoord();
	data->mob->y = center_y;
	data->mob->health = 50;
	data->mob->damage = 5;
	data->mob->tile_name = LINK_FRONT;
	generatePerso(data);
	
}
*/