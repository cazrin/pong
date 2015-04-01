#ifndef BALL_H
#define BALL_H

#include "game.h"
#include "position.h"
#include "size.h"
#include "types.h"

struct Ball {
	Game *game;

	Position position;
	Size size;
};

Ball *Ball_init(Game *game, float x, float y);
void Ball_draw(Ball *ball);
void Ball_update(Ball *ball, float delta_time);

#endif
