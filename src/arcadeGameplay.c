#include "../inc/header.h"

void arcadeGame(SDL_Window *window, SDL_Renderer *renderer) {
    TTF_Font *font = TTF_OpenFont("../resources/fonts/OpenSans-Regular.ttf", 60);
    SDL_Color clr = { 15, 15, 15, 255 };
    SDL_Surface *surf = SDL_LoadBMP("../resources/textures/bg.bmp");
    SDL_Texture *background = SDL_CreateTextureFromSurface(renderer, surf);
    SDL_FreeSurface(surf);
    surf = SDL_LoadBMP("../resources/textures/personS.bmp");
    SDL_Texture *personS = SDL_CreateTextureFromSurface(renderer, surf);
    SDL_FreeSurface(surf);
    surf = SDL_LoadBMP("../resources/textures/personSmr.bmp");
    SDL_Texture *personSmr = SDL_CreateTextureFromSurface(renderer, surf);
    SDL_FreeSurface(surf);
    surf = SDL_LoadBMP("../resources/textures/personB.bmp");
    SDL_Texture *personB = SDL_CreateTextureFromSurface(renderer, surf);
    SDL_FreeSurface(surf);
    surf = SDL_LoadBMP("../resources/textures/personBmr.bmp");
    SDL_Texture *personBmr = SDL_CreateTextureFromSurface(renderer, surf);
    SDL_FreeSurface(surf);
    surf = SDL_LoadBMP("../resources/textures/personD.bmp");
    SDL_Texture *personD = SDL_CreateTextureFromSurface(renderer, surf);
    SDL_FreeSurface(surf);
    surf = SDL_LoadBMP("../resources/textures/pillE.bmp");
    SDL_Texture *pillE = SDL_CreateTextureFromSurface(renderer, surf);
    SDL_FreeSurface(surf);
    surf = SDL_LoadBMP("../resources/textures/pillL.bmp");
    SDL_Texture *pillL = SDL_CreateTextureFromSurface(renderer, surf);
    SDL_FreeSurface(surf);
    surf = SDL_LoadBMP("../resources/textures/pillR.bmp");
    SDL_Texture *pillR = SDL_CreateTextureFromSurface(renderer, surf);
    SDL_FreeSurface(surf);
    surf = SDL_LoadBMP("../resources/textures/redSq.bmp");
    SDL_Texture *redSq = SDL_CreateTextureFromSurface(renderer, surf);
    SDL_FreeSurface(surf);
    SDL_Surface *scr;

    SDL_Rect dstrect;
    int wd;
    int hg;
    SDL_GetWindowSize(window, &wd, &hg);
    dstrect.w = wd;
    dstrect.h = hg;
    dstrect.x = 0;
    dstrect.y = 0;

    srand(time(NULL));
    int arr[120];
    int i = 0;
    while (i < 120) {
        int m = (rand() % 4) + 1;
        for (int j = 0; j < m && i < 120; j++, i++) {
            arr[i] = 0;
            i++;
            if (i >= 120) {
                break;
            }
            arr[i] = 1;
        }
        m = (rand() % 4) + 1;
        for (int j = 0; j < m && i < 120; j++, i++) {
            arr[i] = 0;
            i++;
            if (i >= 120) {
                break;
            }
            arr[i] = -1;
        }
    }
    
    int timer = 3000;
    int score = 0;
    SDL_Texture *scoreLbl;
    char f[20]; 
    int_to_char_array(score, f);
    scr = TTF_RenderText_Solid(font, f, clr);
    scoreLbl = SDL_CreateTextureFromSurface(renderer, scr);
    SDL_FreeSurface(scr);

    int floor = 100;
    Uint8 *kArr = (Uint8*)SDL_GetKeyboardState(NULL);
    int cd = 0;
    int pp = -1;
    i = 119;
    SDL_Event e;
    bool quit = 0;
    int conf = 90;
    int conf2 = 85;
    int conf3 = 195;
    bool dd = false;
    
    while (!quit) {
        if (dd == true && cd == 0) {
            quit = true;
        }
        SDL_RenderClear(renderer);
        SDL_PumpEvents();
        SDL_PollEvent(&e);
        SDL_QueryTexture(background, NULL, NULL, &dstrect.w, &dstrect.h);
        dstrect.x = 0;
        dstrect.y = 0; 
        dstrect.w = wd;
        dstrect.h = hg;
        SDL_RenderCopy(renderer, background, NULL, &dstrect);
        if (e.type == SDL_QUIT) {
            quit = true;
            SDL_Quit();
            return;
        }
        else if (e.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
            quit = true;
            SDL_Quit();
            return;
        }
        i--;
        if (arr[i % 119] == pp || arr[(i + 1) % 119] == pp) {
            dd = true;
            SDL_QueryTexture(personD, NULL, NULL, &dstrect.w, &dstrect.h);
            dstrect.w /= 3;
            dstrect.h /= 3;
            dstrect.y = hg - floor - conf;
            if (pp == -1) {
                dstrect.x = wd / 2 - dstrect.w / 2 - 50 - conf2; //////change 50
            }
            else {
                dstrect.x = wd / 2 + 50 - conf2;
            }
            SDL_RenderCopy(renderer, personD, NULL, &dstrect);
            ///death renderer
        }
        i++;
        
        if (cd) {
            for (int j = 0; j < 6; j++) {
                if (arr[i % 119 + j] == 0) {
                    SDL_QueryTexture(pillE, NULL, NULL, &dstrect.w, &dstrect.h);
                    dstrect.w /= 3;
                    dstrect.h /= 3;
                    dstrect.x = wd / 2 - dstrect.w / 2;
                    dstrect.y = hg - floor - (j + 1) * dstrect.h + dstrect.h / cd - conf3;
                    SDL_RenderCopy(renderer, pillE, NULL, &dstrect);
                }
                else if (arr[i % 119 + j] == -1) {
                    SDL_QueryTexture(pillL, NULL, NULL, &dstrect.w, &dstrect.h);
                    dstrect.w /= 3;
                    dstrect.h /= 3;
                    dstrect.x = wd / 2 - dstrect.w / 2;/////
                    dstrect.y = hg - floor - (j + 1) * dstrect.h + dstrect.h / cd - conf3;
                    SDL_RenderCopy(renderer, pillL, NULL, &dstrect);
                }
                else if (arr[i % 119 + j] == 1) {
                    SDL_QueryTexture(pillR, NULL, NULL, &dstrect.w, &dstrect.h);
                    dstrect.w /= 3;
                    dstrect.h /= 3;
                    dstrect.x = wd / 2 - dstrect.w / 2;/////
                    dstrect.y = hg - floor - (j + 1) * dstrect.h + dstrect.h / cd - conf3;
                    SDL_RenderCopy(renderer, pillR, NULL, &dstrect);
                }
                //renderer of every visible pillar part 
            }

            if (pp == -1 && dd == false) {
                if (cd > 7) {
                    SDL_QueryTexture(personB, NULL, NULL, &dstrect.w, &dstrect.h);
                    dstrect.x = wd / 2 - 100 - conf2;
                    dstrect.y = hg - floor - conf;
                    dstrect.w /= 3;
                    dstrect.h /= 3;
                    SDL_RenderCopy(renderer, personB, NULL, &dstrect);
                }
                else {
                    SDL_QueryTexture(personS, NULL, NULL, &dstrect.w, &dstrect.h);
                    dstrect.x = wd / 2 - 100 - conf2;
                    dstrect.y = hg - floor - conf;
                    dstrect.w /= 3;
                    dstrect.h /= 3;
                    SDL_RenderCopy(renderer, personS, NULL, &dstrect);
                }
            }
            else if (pp == 1 && dd == false) {
                if (cd > 7) {
                    SDL_QueryTexture(personBmr, NULL, NULL, &dstrect.w, &dstrect.h);
                    dstrect.x = wd / 2 + 100 - conf2;
                    dstrect.y = hg - floor - conf;
                    dstrect.w /= 3;
                    dstrect.h /= 3;
                    SDL_RenderCopy(renderer, personBmr, NULL, &dstrect);
                }
                else {
                    SDL_QueryTexture(personSmr, NULL, NULL, &dstrect.w, &dstrect.h);
                    dstrect.x = wd / 2 + 100 - conf2;
                    dstrect.y = hg - floor - conf;
                    dstrect.w /= 3;
                    dstrect.h /= 3;
                    SDL_RenderCopy(renderer, personSmr, NULL, &dstrect);
                }
            }
            //person renderer
            //explosion renderer?
            cd--;
        }
        else {
            for (int j = 0; j < 7; j++) {
                if (arr[i % 119 + j] == 0) {
                    SDL_QueryTexture(pillE, NULL, NULL, &dstrect.w, &dstrect.h);
                    dstrect.w /= 3;
                    dstrect.h /= 3;
                    dstrect.x = wd / 2 - dstrect.w / 2;
                    dstrect.y = hg - floor - j * dstrect.h + dstrect.h - conf3;
                    SDL_RenderCopy(renderer, pillE, NULL, &dstrect);
                }
                else if (arr[i % 119 + j] == -1) {
                    SDL_QueryTexture(pillL, NULL, NULL, &dstrect.w, &dstrect.h);
                    dstrect.w /= 3;
                    dstrect.h /= 3;
                    dstrect.x = wd / 2 - dstrect.w / 2;/////
                    dstrect.y = hg - floor - j * dstrect.h + dstrect.h - conf3;
                    SDL_RenderCopy(renderer, pillL, NULL, &dstrect);
                }
                else if (arr[i % 119 + j] == 1) {
                    SDL_QueryTexture(pillR, NULL, NULL, &dstrect.w, &dstrect.h);
                    dstrect.w /= 3;
                    dstrect.h /= 3;
                    dstrect.x = wd / 2 - dstrect.w / 2;/////
                    dstrect.y = hg - floor - j * dstrect.h + dstrect.h - conf3;
                    SDL_RenderCopy(renderer, pillR, NULL, &dstrect);
                }
                
                //renderer of every visible pillar part
            }
            if (kArr[SDL_SCANCODE_LEFT] == 1 && dd == false) {
                i++;
                cd = 15;
                pp = -1;
                score++;
                timer += 100;
            }
            else if (kArr[SDL_SCANCODE_RIGHT] == 1 && dd == false) {
                i++;
                cd = 15;
                pp = 1;
                score++;
                timer += 100;
            }

            if (pp == -1 && dd == false) {
                SDL_QueryTexture(personS, NULL, NULL, &dstrect.w, &dstrect.h);
                dstrect.x = wd / 2 - 100 - conf2;
                dstrect.y = hg - floor - conf;
                dstrect.w /= 3;
                dstrect.h /= 3;
                SDL_RenderCopy(renderer, personS, NULL, &dstrect);
            }
            else if (pp == 1 && dd == false) {
                SDL_QueryTexture(personSmr, NULL, NULL, &dstrect.w, &dstrect.h);
                dstrect.x = wd / 2 + 100 - conf2;
                dstrect.y = hg - floor - conf;
                dstrect.w /= 3;
                dstrect.h /= 3;
                SDL_RenderCopy(renderer, personSmr, NULL, &dstrect);
            }
            //person renderer
        }
        

        if (timer > 3000) {
            timer = 3000;
        }
        timer -= 2 + (i / 50);
        if (timer < 0) {
            quit = true;
        }

        SDL_QueryTexture(redSq, NULL, NULL, &dstrect.w, &dstrect.h);
        dstrect.x = wd - 320;
        dstrect.y = 50;
        dstrect.w = timer / 10;
        dstrect.h = 30;
        SDL_RenderCopy(renderer, redSq, NULL, &dstrect);

        f[20]; 
        int_to_char_array(score, f);
        scr = TTF_RenderText_Solid(font, f, clr);
        scoreLbl = SDL_CreateTextureFromSurface(renderer, scr);
        SDL_FreeSurface(scr);
        SDL_QueryTexture(scoreLbl, NULL, NULL, &dstrect.w, &dstrect.h);
        dstrect.x = 50;
        dstrect.y = 50;
        SDL_RenderCopy(renderer, scoreLbl, NULL, &dstrect);
        SDL_RenderPresent(renderer);
        SDL_Delay(20);
    }
    SDL_DestroyTexture(background);
    SDL_DestroyTexture(personS);
    SDL_DestroyTexture(personSmr);
    SDL_DestroyTexture(personB);
    SDL_DestroyTexture(personBmr);
    SDL_DestroyTexture(personD);
    SDL_DestroyTexture(pillE);
    SDL_DestroyTexture(pillL);
    SDL_DestroyTexture(pillR);
    SDL_DestroyTexture(redSq);
    SDL_DestroyTexture(scoreLbl);
    
    arcadeGameOver(window, renderer, font, score);
}
