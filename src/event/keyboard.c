#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>

#include "creation.h"
#include "animation.h"

void keybordEvent(SDL_Event *event, s_SDL *data)
{	
	if (event->key.keysym.scancode == SDL_SCANCODE_LEFT)
		persoGoLeft(data);
	else if (event->key.keysym.scancode == SDL_SCANCODE_RIGHT)
		persoGoRight(data);
	else if (event->key.keysym.scancode == SDL_SCANCODE_DOWN)
		persoGoDown(data);
	else if (event->key.keysym.scancode == SDL_SCANCODE_UP)
		persoGoUp(data);
}