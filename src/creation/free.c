#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>

#include "creation.h"
void freeAll(s_SDL **data)
{
	s_SDL *to_remove = *data;
	s_perso *to_free = to_remove->perso;
	free(to_free);
	free(to_remove);
}