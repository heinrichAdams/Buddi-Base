#include "Display.h"
#include "WindowHandler.h"
#include <SDL2/SDL.h>


extern Window_Handler window_handler;

void UpdateBackBuffer(void)
{

    SDL_SetRenderDrawColor(window_handler.renderer, 10, 10, 50, 255);
    SDL_RenderClear(window_handler.renderer);

}

void UpdateFrontBuffer(void)
{

    SDL_RenderPresent(window_handler.renderer);

}

SDL_Texture* LoadTextureFromFile(char* filePath)
{
    SDL_Texture* texture = NULL;

    // Send load data to log
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO,
    "loading image from path: %s", filePath);

    texture = IMG_LoadTexture(window_handler.renderer, filePath);

    return texture;

}

void DrawTexture(SDL_Texture* texture, int xPos, int yPos)
{
    SDL_Rect surface;

    surface.x = xPos;
    surface.y = yPos;

    // Retrieve attributes of a texture
    SDL_QueryTexture(texture, NULL, NULL, &surface.w, &surface.h);

    SDL_RenderCopy(window_handler.renderer, texture, NULL, &surface);

}