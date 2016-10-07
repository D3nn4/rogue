#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "creation.h"
#include "animation.h"

int generateCoord (int min, int max)
{
	srand(time(NULL));
	int coord = ( rand() % max ) + 1;
	if (coord < min)
		coord += min;
	return coord;
}

void creationMob(s_SDL *data)
{
	int min_x = ROOM_X + 32;
	int max_x = ROOM_X + ROOM_W + 2 * TILE_w; // 2 * TILE_w =>pour x demob a gauche et largeur wall tile 
	int min_y = ROOM_X;
	int max_y = ROOM_Y + ROOM_H - 2 * TILE_w; // same
	data->mob = malloc(sizeof(*data->mob));
	if (!data->mob){
		fprintf(stderr,"Erreur de création du mob\n");
		exitAll(data);
	}
	data->mob->box.x = generateCoord(min_x, max_x);
	data->mob->box.y = generateCoord(min_y, max_y);
	data->mob->box.w = TILE_w;
	data->mob->box.h = TILE_w;
	data->mob->health = 50;
	data->mob->damage = 5;
	data->mob->tile_name = MOB;
	generatePerso(data, data->mob);
}
