#ifndef __EVENT_H__
#define __EVENT_H__


void manageEvent(SDL_Event *event, s_SDL *data);
void windowEvent(SDL_Event *event, s_SDL *data);
void keybordEvent(SDL_Event *event, s_SDL *data);

#endif // __EVENT_H__