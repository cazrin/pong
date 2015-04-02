#include "collision.h"
#include "paddle.h"
#include "physics.h"
#include "wall.h"

int collision_between(Paddle *paddle, Wall *wall);

void Physics_update(Game *game) {
	int i;
	for (i = 0; i < game->number_of_paddles; i++) {
		Paddle *paddle = game->paddles[i];

		int j;
		for (j = 0; j < game->number_of_walls; j++) {
			Wall *wall = game->walls[j];

			if (collision_between(paddle, wall)) {
				Collision *collision = Collision_init(wall->name, wall);
				Paddle_collision(paddle, collision);
			}
		}
	}
}

int collision_between(Paddle *paddle, Wall *wall) {
	float ax1 = paddle->position.x;
	float ax2 = paddle->position.x + paddle->size.width;
	float ay1 = paddle->position.y;
	float ay2 = paddle->position.y + paddle->size.height;

	float bx1 = wall->position.x;
	float bx2 = wall->position.x + wall->size.width;
	float by1 = wall->position.y;
	float by2 = wall->position.y + wall->size.height;

	return ax1 < bx2 && ax2 > bx1 && ay1 < by2 && ay2 > by1;
}
