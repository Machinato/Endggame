#include "../inc/header.h"

int main() {
    SDL_Init(SDL_INIT_VIDEO);
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
        printf( "Unable to init SDL");
        SDL_Quit();
        return 1;
    }

    if (TTF_Init() != 0){
        printf("TTF error");
        SDL_Quit();
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Students VS Pillar", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    arcadeGameStart(window, renderer);
    arcadeGame(window, renderer);
    TTF_Quit();
    SDL_Quit();
}
