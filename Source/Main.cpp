#include "Main.h"

int main( int argc, char* args[] )
{

    // Start SDL and create window
    if (!init())
    {
        printf("Failed to initialize\n");
    }
    else
    {
        if (loadMedia())
        {
            // Main loop flag
            bool loop = true;

            // Event Handler
            SDL_Event event;

            while(loop)
            {
                // Handle event queue
                while(SDL_PollEvent(&event) != 0)
                {
                    // If user requests quit
                    if (event.type == SDL_QUIT)
                    {
                        loop = false;
                    }
                }

                // Clear screen
                setRendererColor(gRenderer, DEFAULT_COLOR);
                SDL_RenderClear(gRenderer);

                // Set stuff to renderer
                loopEvents();

                // Update screen
                SDL_RenderPresent(gRenderer);
            }
        }
    }

    close();

	return 0;
}

bool loadMedia()
{
    bool status = true;

    // Load media here

    return status;
}

void loopEvents()
{
    // Put main loop events here

    return;
}
