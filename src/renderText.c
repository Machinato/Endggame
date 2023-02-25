#include "../inc/header.h"

SDL_Texture* renderText(char *message, TTF_Font *font, SDL_Color color, SDL_Renderer *renderer) {
    SDL_Surface *surf = TTF_RenderText_Blended(font, message, color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);
    SDL_FreeSurface(surf);
    return texture;
}
