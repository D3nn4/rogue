#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>

#include "creation.h"
#include "animation.h"

void persoGoLeft(s_SDL *data)
{
	int left = ROOM_X + 32;
	SDL_Rect perso_rect = data->perso->box;
	--perso_rect.x;
	SDL_bool intersection = SDL_HasIntersection(&perso_rect, &data->mob->box);
	if (intersection)
		printf("intersection\n");
	else if (data->perso->box.x - 1 > left)
		data->perso->box.x -= 1;
	data->perso->tile_name = LINK_LEFT;
}

void persoGoRight(s_SDL *data)
{
	int right = ROOM_X + ROOM_W - 32;
	SDL_Rect perso_rect = data->perso->box;
	++perso_rect.x;
	SDL_bool intersection = SDL_HasIntersection(&perso_rect, &data->mob->box);
	if (intersection)
		printf("intersection\n");
	else if (data->perso->box.x + 1 + TILE_w < right)
		data->perso->box.x += 1;
	data->perso->tile_name = LINK_RIGHT;
}

void persoGoUp(s_SDL *data)
{
	int top = ROOM_X;
	SDL_Rect perso_rect = data->perso->box;
	--perso_rect.y;
	SDL_bool intersection = SDL_HasIntersection(&perso_rect, &data->mob->box);
	if (intersection)
		printf("intersection\n");
	else if (data->perso->box.y - 1 > top)
		data->perso->box.y -= 1;
	data->perso->tile_name = LINK_BACK;
}

void persoGoDown(s_SDL *data)
{
	int bottom = ROOM_Y + ROOM_H - 32;
	SDL_Rect perso_rect = data->perso->box;
	++perso_rect.y;
	SDL_bool intersection = SDL_HasIntersection(&perso_rect, &data->mob->box);
	if (intersection)
		printf("intersection\n");
	else if (data->perso->box.y + 1 + TILE_w < bottom && !intersection)
		data->perso->box.y += 1;
	data->perso->tile_name = LINK_FRONT;
}