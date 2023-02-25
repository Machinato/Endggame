#include "../inc/header.h"

void arcadeGameStart(SDL_Window *window, SDL_Renderer *renderer) {
    TTF_Font *font = TTF_OpenFont("../resources/fonts/OpenSans-Regular.ttf", 60);
    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
    SDL_Surface *strScreen = SDL_LoadBMP("../resources/textures/strScreen.bmp");
    SDL_Texture *textureOfStrScreen = SDL_CreateTextureFromSurface(renderer, strScreen);
    SDL_FreeSurface(strScreen);
    SDL_RenderClear(renderer);
    SDL_Rect dstrect;
    SDL_QueryTexture(textureOfStrScreen, NULL, NULL, &dstrect.w, &dstrect.h);
    int wd;
    int hg;
    SDL_GetWindowSize(window, &wd, &hg);
    dstrect.w = wd;
    dstrect.h = hg;
    dstrect.x = 0;
    dstrect.y = 0;
    SDL_RenderCopy(renderer, textureOfStrScreen, NULL, &dstrect);

    SDL_Color clr = { 235, 235, 235, 255 };
    SDL_Texture *textB = renderText("Press any key to start or Esc to quit", font, clr, renderer);

    SDL_Rect textRec;
    SDL_QueryTexture(textB, NULL, NULL, &textRec.w, &textRec.h);
    textRec.x = dstrect.x + dstrect.w / 2 - textRec.w / 2;
    textRec.y = 4 * dstrect.h / 5;
    SDL_RenderCopy(renderer, textB, NULL, &textRec);
    SDL_RenderPresent(renderer);

    SDL_Event e;
    bool quit = 0;

    while (!quit) {
        SDL_PollEvent(&e);
        if (e.type == SDL_QUIT) {
            quit = true;
            SDL_Quit();
        }
        else if (e.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
            quit = true;
            SDL_Quit();
        }
        else if (e.type == SDL_KEYDOWN) {
            quit = true;
        }
    }

    SDL_RenderClear(renderer);
    SDL_Delay(600);
    TTF_CloseFont(font);
    SDL_DestroyTexture(textureOfStrScreen);
    SDL_DestroyTexture(textB);
}
