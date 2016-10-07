#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>

#include "creation.h"

void getWallTile (s_SDL *data)
{
	data->wall_load = SDL_LoadBMP(WALL_TILE);
	SDL_SetColorKey(data->wall_load, SDL_TRUE, SDL_MapRGB(data->wall_load->format, 255, 255, 255));
	if ( !data->wall_load ) {
	        fprintf(stdout,"Échec de chargement du wall (%s)\n",SDL_GetError());
	        exitAll(data);
	}
	data->wall_texture = SDL_CreateTextureFromSurface(data->renderer, data->wall_load); 
	if ( !data->wall_texture ) {
            fprintf(stdout,"Échec de création de la texture du bg (%s)\n",SDL_GetError());
            exitAll(data);
    }
}
void generateWall(s_SDL *data)
{
	int nb_tile_w = 32;
	int nb_tile_h = 16;
	int tile_x = ROOM_X;
	int tile_y = ROOM_Y;
	int x = 0;
	int y = 0;
	getWallTile(data);
	for (y = 0; y < nb_tile_h; ++y)	{
		for (x = 0; x < nb_tile_w; ++x) {
			tile_x = ROOM_X + (x * TILE_w);
			tile_y = ROOM_Y + (y * TILE_w);
			SDL_Rect tile = {tile_x, tile_y, TILE_w, TILE_w};
			if (y == 0 || y == nb_tile_h - 1
				|| x == 0 || x == nb_tile_w - 1) {
				SDL_RenderCopy(data->renderer,data->wall_texture,NULL,&tile);
				
			}			
		}
	}
}