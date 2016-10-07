#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>

#include "creation.h"
#include "animation.h"
void windowEvent(SDL_Event *event, s_SDL *data)
{
	if (event->window.event == SDL_WINDOWEVENT_CLOSE) {
 		exitAll(data);
 		exit(0);
    }
}

void keybordEvent(SDL_Event *event, s_SDL *data)
{
	if (event->key.keysym.scancode == SDL_SCANCODE_LEFT)
		data->perso->x -= 1;
	else if (event->key.keysym.scancode == SDL_SCANCODE_RIGHT)
		data->perso->x += 1;
	else if (event->key.keysym.scancode == SDL_SCANCODE_DOWN)
		data->perso->y += 1;
	else if (event->key.keysym.scancode == SDL_SCANCODE_UP)
		data->perso->y -= 1;
}

void manageEvent(SDL_Event *event, s_SDL *data)
{
	SDL_PollEvent(event);
    	if (event->type == SDL_WINDOWEVENT)
    		windowEvent(event, data);
    	else if (event->type == SDL_KEYDOWN)
    		keybordEvent(event, data);

	generateAll(data);
}