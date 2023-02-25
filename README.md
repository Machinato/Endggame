#Compil command 

gcc -o m renderText.c arcadeMainGame.c arcadeIntInChar.c arcadeGameStart.c arcadeGameplay.c arcadeGameOver.c -g -O2 -D_REENTRANT -I/usr/include/SDL2 -DHAVE_OPENGLES2 -DHAVE_OPENGL -DHAVE_SDL_TTF -g -lSDL2_test -lSDL2 -lSDL2_ttf
