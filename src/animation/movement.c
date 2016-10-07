#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>

#include "creation.h"
#include "animation.h"

void persoGoLeft(s_SDL *data)
{
	int left = ROOM_X + 32;
	//si pas de mur
	if(data->perso->x - 1 > left)
		data->perso->x -= 1;
	data->perso->tile_name = LINK_LEFT;

	//si enemi
	//attaquer
}

void persoGoRight(s_SDL *data)
{
	int right = ROOM_X + ROOM_W - 32;
	//si pas de mur
	if(data->perso->x + 1 + TILE_w < right)
		data->perso->x += 1;
	data->perso->tile_name = LINK_RIGHT;
	//si enemi
	//attaquer
}

void persoGoUp(s_SDL *data)
{
	int top = ROOM_X ;
	//si pas de mur
	if(data->perso->y - 1 > top)
		data->perso->y -= 1;
	data->perso->tile_name = LINK_BACK;
	//si enemi
	//attaquer
}

void persoGoDown(s_SDL *data)
{
	int bottom = ROOM_Y + ROOM_H - 32;
	//si pas de mur
	if (data->perso->y + 1 + TILE_w < bottom)
		data->perso->y += 1;
	data->perso->tile_name = LINK_FRONT;
	//si enemi
	//attaquer
}