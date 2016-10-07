#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>

#include "creation.h"

void generateMap(s_SDL *data)
{
	int tile_x = ROOM_X;
	int tile_y = ROOM_Y;
	int x = 0;
	int y = 0;
	for (y = 0; y < NB_TILE_H; ++y)	{
		for (x = 0; x < TILE_w; ++x) {
			tile_x = ROOM_X + (x * TILE_w);
			tile_y = ROOM_Y + (y * TILE_w);
			SDL_Rect tile = {tile_x, tile_y, TILE_w, TILE_w};
			SDL_RenderCopy(data->renderer,data->floor->texture,NULL,&tile);
			if (data->map[y][x] == WALL)
				SDL_RenderCopy(data->renderer,data->wall->texture,NULL,&tile);			
		}
	}
}
void getTile(t_tile *tile, s_SDL *data)
{
	tile->load = SDL_LoadBMP(tile->path);
	SDL_SetColorKey(tile->load, SDL_TRUE, SDL_MapRGB(tile->load->format, 0, 0, 255));
	if ( !tile->load ) {
	        fprintf(stdout,"Échec de chargement du wall (%s)\n",SDL_GetError());
	        exitAll(data);
	}
	tile->texture = SDL_CreateTextureFromSurface(data->renderer, tile->load); 
	if ( !tile->texture ) {
            fprintf(stdout,"Échec de création de la texture du bg (%s)\n",SDL_GetError());
            exitAll(data);
    }
}
void createTTiles(s_SDL *data)
{
	data->floor = malloc(sizeof(*data->floor));
	if (!data->floor)
		exitAll(data);	
	data->floor->path = FLOOR_TILE;
	data->floor->type = FLOOR;
	data->wall = malloc(sizeof(*data->wall));
	if (!data->wall)
		exitAll(data);	
	data->wall->path = WALL_TILE;
	data->wall->type = WALL;
	getTile(data->wall, data);
	getTile(data->floor, data);
}

void getMapEnum (s_SDL *data)
{
	data->map = malloc(sizeof(*data->map) * NB_TILE_H);
	if (!data->map)
		exitAll(data);
	int x = 0;
	int y = 0;
	for (y = 0; y < NB_TILE_H; ++y)	{
		data->map[y] = malloc(sizeof(**data->map) * NB_TILE_W);
		if (!data->map[y])
			exitAll(data);
		for (x = 0; x < NB_TILE_W; ++x) {
			if (y == 0 || y == NB_TILE_H - 1
				|| x == 0 || x == NB_TILE_W - 1)
				data->map[y][x] = WALL;
			else
				data->map[y][x] = FLOOR;
		}
	}
}

void createMap(s_SDL *data)
{
	createTTiles(data);
	getMapEnum (data);
	generateMap(data);	
}