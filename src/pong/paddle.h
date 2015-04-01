#ifndef PADDLE_H
#define PADDLE_H

#include "game.h"
#include "position.h"
#include "size.h"
#include "types.h"

struct Paddle {
	Game *game;

	Position position;
	Size size;
};

Paddle *Paddle_init(Game *game, float x, float y);
void Paddle_draw(Paddle *paddle);
void Paddle_update(Paddle *paddle, float delta_time);

#endif
