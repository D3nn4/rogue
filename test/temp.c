#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void havebg(SDL_Window *pWindow)
{
	SDL_Surface* bgsprite = SDL_LoadBMP("x.bmp");
			if ( bgsprite ) {
				SDL_Rect bgdest = {0,100, 0, 0};
			    SDL_Surface *bgtemp = SDL_GetWindowSurface(pWindow);
			    SDL_BlitSurface(bgsprite, NULL, bgtemp, &bgdest); // Copie du sprite
			    SDL_UpdateWindowSurface(pWindow); 
			}
			else
			{
			    fprintf(stdout,"Échec de chargement du sprite (%s)\n",SDL_GetError());
			}
}
int main()
{
    /* Initialisation simple */
    if (SDL_Init(SDL_INIT_VIDEO) != 0 ){
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        return EXIT_FAILURE;
    }

    {
        /* Création de la fenêtre */
        SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_UNDEFINED,
        							SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);

        if( pWindow )
        {
        	havebg(pWindow);
        	SDL_Surface* pSprite = SDL_LoadBMP("runningcat.bmp");
			if ( pSprite )
			{
				SDL_Rect dest = {0,100, 0, 0};
			    SDL_Surface *temp = SDL_GetWindowSurface(pWindow);
			    int w = 512;
			    int h = 256;
			    SDL_Rect anim[8] = 
			    {
			    	{0 * w, 0 *h, w, h},
			    	{1 * w, 0 *h, w, h},
			    	{0 * w, 1 *h, w, h},
			    	{1 * w, 1 *h, w, h},
			    	{0 * w, 2 *h, w, h},
			    	{1 * w, 2 *h, w, h},
			    	{0 * w, 3 *h, w, h},
			    	{1 * w, 3 *h, w, h}
			    };
			    int i = 0;
			    while (true) {
			    	SDL_Rect * ta_maman = &anim[i];
			    	SDL_BlitSurface(pSprite, ta_maman, temp, &dest); // Copie du sprite
			    	SDL_UpdateWindowSurface(pWindow); // Mise à jour de la fenêtre pour prendre en compte la copie du sprite
			    	SDL_Delay(75); /* Attendre trois secondes, que l'utilisateur voit la fenêtre */
			    	i = (i + 1)%8;
			    }			    
			    SDL_FreeSurface(pSprite); // Libération de la ressource occupée par le sprite
			}
			else
			{
			    fprintf(stdout,"Échec de chargement du sprite (%s)\n",SDL_GetError());
			}
            SDL_Delay(3000); /* Attendre trois secondes, que l'utilisateur voit la fenêtre */
            
        }
        else
        {
            fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
        }
        SDL_DestroyWindow(pWindow);
    }

    SDL_Quit();

    return EXIT_SUCCESS;
}