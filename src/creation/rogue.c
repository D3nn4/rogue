#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "creation.h"
#include "event.h"
void exitAll (s_SDL *data)
{
	SDL_DestroyTexture(data->floor->texture);
	SDL_DestroyTexture(data->wall->texture);
	SDL_FreeSurface(data->floor->load);
	SDL_FreeSurface(data->wall->load);
	SDL_DestroyRenderer(data->renderer);
	SDL_DestroyWindow(data->window);
	//freeAll(&data);
	
	SDL_Quit();
	exit(0);
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
	createMap(data);
	creationPerso(data);
	creationMob(data);
	//createAnim(data);
	
	return data;
}

void generateAll(s_SDL *data)
{
	SDL_RenderClear(data->renderer);
   	generateMap(data);
   	generatePerso(data, data->perso);
   	generatePerso(data, data->mob);
   	SDL_RenderPresent(data->renderer);
}

void rogue()
{	
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) != 0 ){
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        return;
    }
    s_SDL *SDL_data = createSSDL();
    SDL_Event event;
    generateAll(SDL_data);
    while (true)
    	manageEvent(&event, SDL_data);	
	exitAll(SDL_data);	
}