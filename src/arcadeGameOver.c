#include "../inc/header.h"

void arcadeGameOver(SDL_Window* window, SDL_Renderer* renderer, TTF_Font* font, int n) {
    int wd;
    int hg;
    SDL_GetWindowSize(window, &wd, &hg);
    SDL_Surface* iconSurface = SDL_LoadBMP("../resources/textures/icon.bmp");
    SDL_Texture* iconTexture = SDL_CreateTextureFromSurface(renderer, iconSurface);
    SDL_Rect iconRect;
    SDL_QueryTexture(iconTexture, NULL, NULL, &iconRect.w, &iconRect.h);
    iconRect.w /= 2;
    iconRect.h /= 2;
    iconRect.x = wd / 2 - iconRect.w / 2;
    iconRect.y = hg / 2 - iconRect.h / 2;
    SDL_FreeSurface(iconSurface);
    SDL_RenderCopy(renderer, iconTexture, NULL, &iconRect);

    SDL_Color textColor = { 255, 255, 255, 255 }; // white color for text
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, "Game over", textColor);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_Rect textRect;
    SDL_QueryTexture(textTexture, NULL, NULL, &textRect.w, &textRect.h);
    textRect.w /= 2;
    textRect.h /= 2;
    textRect.x = wd / 2 - textRect.w / 2;
    textRect.y = iconRect.y + 90;
    SDL_FreeSurface(textSurface);
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);

    /*char msg[20];
    int_to_char_array(n, msg);
    SDL_Texture *num = renderText(msg, font, textColor, renderer);
    SDL_Rect numRect;
    SDL_QueryTexture(num, NULL, NULL, &numRect.w, &numRect.h);
    numRect.x = wd / 2 - numRect.w / 2;
    numRect.y = numRect.y + 50;
    SDL_RenderCopy(renderer, num, NULL, &numRect);*/

    SDL_RenderPresent(renderer);

    SDL_Event e;
    bool quit = 0;

    while (!quit) {
        SDL_PollEvent(&e);
        if (e.type == SDL_QUIT) {
            quit = true;
        }
        if (e.type == SDL_KEYDOWN) {
            quit = true;
        }
    }
    printf("You have reached %d points\n", n);
    // Clean up
    SDL_DestroyTexture(textTexture);
    SDL_DestroyTexture(iconTexture);
    //SDL_DestroyTexture(num);
    arcadeGame(window, renderer);
}
