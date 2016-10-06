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
		SDL_Renderer *pRenderer;
		SDL_Surface* pSprite;
        SDL_Texture* pTexture;
        
        SDL_Rect dest = {0,100, 0, 0};
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
		
		pWindow = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_UNDEFINED,
        							SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);
		
        if( !pWindow ) {
  	        fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
    		exit(0);
        }
  		//havebg(pWindow);
    	pRenderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_ACCELERATED); // Création d'un SDL_Renderer utilisant l'accélération matérielle
		if ( !pRenderer ) {
		    fprintf(stdout,"Échec de création du renderer (%s)\n",SDL_GetError());
			exit(0);
		}
	    pSprite = SDL_LoadBMP("runningcat.bmp");
	    if ( !pSprite ) {
	        fprintf(stdout,"Échec de chargement du sprite (%s)\n",SDL_GetError());
	        exit(0);
	    }
		pTexture = SDL_CreateTextureFromSurface(pRenderer, pSprite); // Préparation du sprite
	    
        if ( !pTexture ) {
            fprintf(stdout,"Échec de création de la texture (%s)\n",SDL_GetError());
            exit(0);
        }

        /* MAIN LOOP */
	    int i = 0;
	    printf("before loop\n");
	    while (true) {
	    	SDL_Rect * ta_maman = &anim[i];
	    	SDL_RenderCopy(pRenderer,pTexture,NULL,&dest); // Copie du sprite grâce au SDL_Renderer
        	SDL_RenderPresent(pRenderer); // Affichage
        	SDL_Delay(75); /* Attendre trois secondes, que l'utilisateur voit la fenêtre */
        	i = (i + 1)%8;
	    }
        SDL_DestroyTexture(pTexture); // Libération de la mémoire associée à la texture
	    SDL_FreeSurface(pSprite); // Libération de la ressource occupée par le sprite
		SDL_DestroyRenderer(pRenderer); // Libération de la mémoire du SDL_Renderer	
        SDL_DestroyWindow(pWindow);
    }

    SDL_Quit();

    return EXIT_SUCCESS;
}