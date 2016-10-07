#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>

#include "creation.h"

void getFloorTile (s_SDL *data)
{
	data->bg_load = SDL_LoadBMP(BG_TILE);
	SDL_SetColorKey(data->bg_load, SDL_TRUE, SDL_MapRGB(data->bg_load->format, 255, 255, 255));

	if ( !data->bg_load ) {
	        fprintf(stdout,"Échec de chargement du bg (%s)\n",SDL_GetError());
	        exitAll(data);
	}
	data->bg_texture = SDL_CreateTextureFromSurface(data->renderer, data->bg_load); 
	if ( !data->bg_texture ) {
            fprintf(stdout,"Échec de création de la texture du bg (%s)\n",SDL_GetError());
            exitAll(data);
    }
}
void generateBg(s_SDL *data)
{
	int nb_tile_w = 32;
	int nb_tile_h = 16;
	int tile_x = ROOM_X;
	int tile_y = ROOM_Y;
	int x = 0;
	int y = 0;
	getFloorTile(data);
	for (y = 0; y < nb_tile_h; ++y)	{
		for (x = 0; x < nb_tile_w; ++x) {
			tile_x = ROOM_X + (x * TILE_w);
			tile_y = ROOM_Y + (y * TILE_w);
			SDL_Rect tile = {tile_x, tile_y, TILE_w, TILE_w};
			SDL_RenderCopy(data->renderer,data->bg_texture,NULL,&tile);			
		}
	}
}

/*
void createBg(s_SDL *data)
{
	SDL_Rect bg = {ROOM_X, ROOM_Y, ROOM_W, ROOM_H};
	data->bg_load = SDL_LoadBMP("img/stonefloor.bmp");
	if ( !data->bg_load ) {
	        fprintf(stdout,"Échec de chargement du bg (%s)\n",SDL_GetError());
	        exitAll(data);
	}
	data->bg_texture = SDL_CreateTextureFromSurface(data->renderer, data->bg_load); 
	if ( !data->bg_texture ) {
            fprintf(stdout,"Échec de création de la texture du bg (%s)\n",SDL_GetError());
            exitAll(data);
    }
	SDL_RenderCopy(data->renderer,data->bg_texture,NULL,&bg);
	SDL_SetRenderDrawColor(data->renderer, 0, 0, 0, 100);
}
*/