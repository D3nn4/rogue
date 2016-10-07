#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>

#include "creation.h"

void manageEvent(SDL_Event *event, s_SDL *data)
{
	SDL_PollEvent(event);
    	if (event->type == SDL_WINDOWEVENT) {
    		if (event->window.event == SDL_WINDOWEVENT_CLOSE) {
    	 		exitAll(data);
    	 		exit(0);
    		}
	   	}
}