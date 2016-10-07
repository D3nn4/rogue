#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>

#include "creation.h"
#include "event.h"

void windowEvent(SDL_Event *event, s_SDL *data)
{
	if (event->window.event == SDL_WINDOWEVENT_CLOSE) {
 		exitAll(data);
 		exit(0);
    }
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