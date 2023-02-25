CC = gcc

flags := -g -O2 -D_REENTRANT -I/usr/include/SDL2 -DHAVE_OPENGLES2 -DHAVE_OPENGL -DHAVE_SDL_TTF -g -lSDL2_test -lSDL2 -lSDL2_ttf
name := Students_VS_Pillars

SRC = $(wildcard src/*.c)

all: $(name)
	$(CC) -o $(name) $(SRC) $(flags)

clean:
	rm -rf $(name)

uninstall:
	rm -rf $(name)

reinstall:
	make uninstall
	make
