#include "SDL_Func.h"

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;

bool init()
{
    // Return flag
    bool status = true;

    // Initialize SDL
    if (SDL_Init(FLAG_SDL_INIT) < 0)
    {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        status = false;
    }
    else
    {
        // Set texture filtering to linear
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        {
            printf("Warning: Linear Texture filtering not enabled!");
        }

        // Create window
        gWindow = SDL_CreateWindow(WINDOW_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL)
        {
            printf("Window could not be created! %s\n", SDL_GetError());
            status = false;
        }
        else
        {
            // Create renderer
            gRenderer = SDL_CreateRenderer(gWindow, -1, FLAG_RENDER);
            if (gRenderer == NULL)
            {
                printf("Renderer could not be created! %s\n", SDL_GetError());
                status = false;
            }
            else
            {
                // Initialize renderer color
                setRendererColor(gRenderer, DEFAULT_COLOR);
#ifdef SDL_IMAGE_MAJOR_VERSION
                // Initialize PNG loading
                if (!(IMG_Init(FLAG_IMG_INIT) & FLAG_IMG_INIT))
                {
                    printf("SDL_image could not initialize! SDL_Image Error: %s\n", IMG_GetError());
                    status = false;
                }
#endif
#ifdef SDL_TTF_MAJOR_VERSION
                // Initialize TTF Fonts
                if (TTF_Init() == -1)
                {
                    printf("SDL_ttf could not initialize! SDL_TTF error: %s\n", TTF_GetError());
                    status = false;
                }
#endif

#ifdef SDL_MIXER_MAJOR_VERSION
                // Initialize SDL Mixer
                if ( Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 2048) < 0)
                {
                    printf("SDL_Mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
                    status = false;
                }
#endif // SDL_MIXER_MAJOR_VERSION

            }
        }
    }

    return status;
}

void close()
{
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    gRenderer = NULL;

    // Quit SDL Subsystems
    SDL_Quit();
#if SDL_IMAGE_MAJOR_VERSION
    IMG_Quit();
#endif // SDL_IMAGE_MAJOR_VERSION
#ifdef SDL_TTF_MAJOR_VERSION
    TTF_Quit();
#endif // SDL_TTF_MAJOR_VERSION
#ifdef SDL_MIXER_MAJOR_VERSION
    Mix_Quit();
#endif // SDL_MIXER_MAJOR_VERSION
}

// Set renderer color
void setRendererColor(SDL_Renderer* renderer, uint32_t color)
{
    SDL_SetRenderDrawColor(gRenderer, (color >> 24) & 0xFF,
                                                    (color >> 16) & 0xFF,
                                                    (color >> 8) & 0xFF,
                                                    color & 0xFF);
}

void drawRect(SDL_Rect* rect, uint32_t color, bool fill)
{
    setRendererColor(gRenderer, color);

    if (fill) { SDL_RenderFillRect(gRenderer, rect); }
    else { SDL_RenderDrawRect(gRenderer, rect); }
}
void drawLine(SDL_Rect* points, uint32_t color)
{
    setRendererColor(gRenderer, color);

    SDL_RenderDrawLine(gRenderer, points->x, points->y,
                       points->x + points->w, points->y + points->h);
}
