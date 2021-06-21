#ifndef SDL_FUNC_H_INCLUDED
#define SDL_FUNC_H_INCLUDED

#include <string>
#include <stdio.h>
#include <cmath>

#include "SDL.h"

#define WINDOW_NAME "Polygon Collisions - SDL"

// Initialization flags
#define FLAG_SDL_INIT   SDL_INIT_VIDEO | SDL_INIT_AUDIO
#define FLAG_RENDER     SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
#ifdef SDL_IMAGE_MAJOR_VERSION
#define FLAG_IMG_INIT   IMG_INIT_PNG
#endif

// Color keys
#define COLOR_KEY       0x0000FFFF
#define DEFAULT_COLOR   0xFF00FFFF

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Global variables
extern SDL_Window* gWindow;
extern SDL_Renderer* gRenderer;

// Function prototypes
bool init();
void close();
void setRendererColor(SDL_Renderer* renderer, uint32_t color);
void drawRect(SDL_Rect* rect, uint32_t color, bool fill);
void drawLine(SDL_Rect* points, uint32_t color);

#endif // SDL_FUNC_H_INCLUDED
