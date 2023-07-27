# dopixels
dopixels is a rendering engine for pixel rendering in C made for use in my game engine disponens omnia :)

## usage
dopixels is an SDL library and sdl must be installed

do pixels has five functions and a struct, its not too complicated lol :p
```C
/*This struct is a wrapper for all the SDL content*/
struct screen { SDL_Event event, SDL_Window *window, SDL_Renderer *renderer, SDL_Texture *texture, Uint32 *pixels, int size[2] };
/*The screen pointer is your screen struct (shown above), with width and height being your windows width height
  there is no significant return type, the setup function being here to initialize your screen*/
int _ren_setup(struct screen *screen, int width, int height);
/*Clears the window with the specified color (color is formatted as hexadecimal: 0xAARRGGBB, A being alpha
  R being red, G being green, B being blue, for example red is 0xFFFF0000)*/
_ren_clear(struct screen *screen, Uint32 color);
/*does all the window handling so you dont have to (making sure the window closes, rendering the
  pixel buffer, and clearing the renderer) returns 1 if quit and 0 if not quit*/
int _ren_handle(struct screen *screen);
/*draws a pixel at (x, y) with color (color)*/
_ren_drawpx(struct screen *screen, int x, int y, Uint32 color);
/*quits the program and destroys all the SDL stuff in your screen*/
int _ren_quit(struct screen *screen);
/*draws a rectangle at (x1, y1) with size (x2 - x1, y2 - y1) with color (color)*/
int _ren_drawrect(struct screen *screen, int x1, int y1, int x2, int y2, Uint32 color);
/*draws a Uint32 array (color) to the screen at (_x, _y) with size (xsz, ysz) which should be set
  to the size of the sprite or less (otherwise a segfault may occur)*/
int _ren_drawsprite(struct screen *screen, int _x, int _y, int xsz, int ysz, Uint32 *color);
```
Here is an example usage that renders a line on your window :)
```C
#include "_ren.h"

int main() {
  struct screen screen;
  _ren_setup(&screen, 400, 400);
  _ren_clear(&screen, 0x00000000);
  for(int i = 0; i < 400; i++) _ren_drawpx(i, i, 0xFFFFFFFF);
  while(_ren_handle(&screen));
  _ren_quit(&screen);
}
```

note: sdl is included as <SDL2/SDL.h> in _ren.h

## changelog

1.1 added rect drawrect and drawsprite UwU
1.0 created the program :)
