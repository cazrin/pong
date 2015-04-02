#ifndef BALL_H
#define BALL_H

#include "collision.h"
#include "game.h"
#include "position.h"
#include "size.h"
#include "types.h"
#include "vector2d.h"

struct Ball {
	Game *game;

	Vector2D direction;
	Position original_position, position;
	Size size;

	float speed;
};

Ball *Ball_init(Game *game, float x, float y);
void Ball_collision(Ball *ball, Collision *collision);
void Ball_draw(Ball *ball);
void Ball_reset(Ball *ball);
void Ball_update(Ball *ball, float delta_time);

#endif
