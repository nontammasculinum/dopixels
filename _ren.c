#include "_ren.h"

int _ren_setup(struct screen *screen, int width, int height) {
	SDL_Init(SDL_INIT_VIDEO);
	screen->window = SDL_CreateWindow("SDL2 Pixel Drawing", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
    screen->renderer = SDL_CreateRenderer(screen->window, -1, 0);
    screen->texture = SDL_CreateTexture(screen->renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, width, height);
    screen->pixels = malloc(width * height * sizeof(Uint32));
	screen->size[0] = width;
	screen->size[1] = height;
}

int _ren_clear(struct screen *screen, Uint32 color) {
	memset(screen->pixels, color, screen->size[0] * screen->size[1] * sizeof(Uint32));
}

int _ren_handle(struct screen *screen) {
	SDL_UpdateTexture(screen->texture, NULL, screen->pixels, screen->size[0] * sizeof(Uint32));
	SDL_WaitEvent(&(screen->event));
	switch (screen->event.type) {
		case SDL_QUIT:
			return 1;
	}
	SDL_RenderClear(screen->renderer);
	SDL_RenderCopy(screen->renderer, screen->texture, NULL, NULL);
	SDL_RenderPresent(screen->renderer);
}

int _ren_quit(struct screen *screen) {
	free(screen->pixels);
	SDL_DestroyTexture(screen->texture);
	SDL_DestroyRenderer(screen->renderer);
	SDL_DestroyWindow(screen->window);
	SDL_Quit();
}

int _ren_drawpx(struct screen *screen, int x, int y, Uint32 color) {
	screen->pixels[x + y * screen->size[0]] = color;
}

