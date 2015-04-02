#ifndef WALL_H
#define WALL_H

#include "game.h"
#include "position.h"
#include "size.h"

struct Wall {
	Game *game;

	Position position;
	Size size;

	char *name;
};

Wall *Wall_init(Game *game, char *name, float x, float y, int width, int height);
void Wall_draw(Wall *wall);

#endif
