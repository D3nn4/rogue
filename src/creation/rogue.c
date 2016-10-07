#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>

#include "creation.h"
void exitAll (s_SDL *data)
{
	SDL_DestroyWindow(data->window);
	SDL_DestroyRenderer(data->renderer);
	SDL_Quit();
}
s_SDL *createSSDL()
{
	s_SDL *data = malloc(sizeof(*data));
	if (!data){
		fprintf(stderr,"Erreur de création de la data\n");
		exit(0);
	}
	creationWin(data);
	creationRenderer(data);
	data->perso_load = NULL;
    data->perso_texture = NULL;
    data->bg_load = NULL;
    data->bg_texture = NULL;
    return data;
}

void rogue()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) != 0 ){
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        return;
    }
    s_SDL *SDL_data = createSSDL();
    SDL_Event event;
  


    SDL_Delay(1000);
    exitAll(SDL_data);	
}