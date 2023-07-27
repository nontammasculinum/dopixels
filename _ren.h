#include <stdio.h>

#include <SDL2/SDL.h>

#ifndef _RENH
#define _RENH

#define UINT32MAX 0xFFFFFFFF

struct screen {
	SDL_Event    event;
	SDL_Window   *window;
	SDL_Renderer *renderer;
	SDL_Texture  *texture;
	Uint32       *pixels;
	int           size[2];
};

int _ren_setup(struct screen *screen, int width, int height);
int _ren_clear(struct screen *screen, Uint32 color);
int _ren_handle(struct screen *screen);
int _ren_quit(struct screen *screen);
int _ren_drawpx(struct screen *screen, int x, int y, Uint32 color);

#endif
