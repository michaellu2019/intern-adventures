files = ./src/typewriter.c ./src/global.c ./src/main.c

libs = -lncurses

build:
	gcc -g3 $(files) $(libs) -o ./main