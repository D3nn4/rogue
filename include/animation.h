#ifndef __ANIMATION_H__
#define __ANIMATION_H__


#define LINK_FRONT "img/link_front.bmp"
#define LINK_BACK "img/link_back.bmp"
#define LINK_RIGHT "img/link_right.bmp"
#define LINK_LEFT "img/link_left.bmp"

#define MOB "img/mob1.bmp"
/*
typedef struct 	t_anim {
	struct 	t_anim *first_frame;
	struct 	t_anim *frame;
	struct 	t_anim *next;
}				s_anim;
*/
struct 	t_SDL;

void persoGoLeft(struct t_SDL *data);
void persoGoRight(struct t_SDL *data);
void persoGoUp(struct t_SDL *data);
void persoGoDown(struct t_SDL *data);

#endif // __ANIMATION_H__