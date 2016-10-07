#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "creation.h"
#include "event.h"
void exitAll (s_SDL *data)
{
	SDL_DestroyTexture(data->bg_texture);
	SDL_FreeSurface(data->bg_load);
	SDL_DestroyRenderer(data->renderer);
	SDL_DestroyWindow(data->window);
	freeAll(&data);
	
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
	creationPerso(data);
	//createAnim(data);
	data->bg_load = NULL;
    data->bg_texture = NULL;
    data->wall_load = NULL;
    data->wall_texture = NULL;
    return data;
}

void generateAll(s_SDL *data)
{
	SDL_RenderClear(data->renderer);
   	generateBg(data);
   	generateWall(data);
   	generatePerso(data);
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