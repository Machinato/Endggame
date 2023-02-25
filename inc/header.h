#ifndef ourGame
#define ourGame

#include "../resources/SDL2/SDL.h"
#include "../resources/SDL2/SDL_ttf.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

SDL_Texture* renderText(char *message, TTF_Font *font, SDL_Color color, SDL_Renderer *renderer);

void int_to_char_array(int num, char char_array[]);
void arcadeGameOver(SDL_Window* window, SDL_Renderer* renderer, TTF_Font* font, int n);
void arcadeGame(SDL_Window *window, SDL_Renderer *renderer);
void arcadeGameStart(SDL_Window *window, SDL_Renderer *renderer);


#endif
