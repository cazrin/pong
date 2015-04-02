#include "ball.h"
#include "collision.h"
#include "paddle.h"
#include "position.h"
#include "physics.h"
#include "size.h"
#include "wall.h"

int aabb_collision(Position apos, Size asize, Position bpos, Size bsize);
int collision_between_ball_wall(Ball *ball, Wall *wall);
int collision_between_paddle_ball(Paddle *paddle, Ball *ball);
int collision_between_paddle_wall(Paddle *paddle, Wall *wall);

void Physics_update(Game *game) {
	int i;
	for (i = 0; i < game->number_of_paddles; i++) {
		Paddle *paddle = game->paddles[i];

		int j;
		for (j = 0; j < game->number_of_walls; j++) {
			Wall *wall = game->walls[j];

			if (collision_between_paddle_wall(paddle, wall)) {
				Collision *collision = Collision_init(wall->name, wall);
				Paddle_collision(paddle, collision);
			}

			if (collision_between_ball_wall(game->ball, wall)) {
				Collision *collision = Collision_init(wall->name, wall);
				Ball_collision(game->ball, collision);
			}
		}

		if (collision_between_paddle_ball(paddle, game->ball)) {
			Collision *collision = Collision_init("Paddle", paddle);
			Ball_collision(game->ball, collision);
		}
	}
}

int aabb_collision(Position apos, Size asize, Position bpos, Size bsize) {
	float ax1 = apos.x;
	float ax2 = apos.x + asize.width;
	float ay1 = apos.y;
	float ay2 = apos.y + asize.height;

	float bx1 = bpos.x;
	float bx2 = bpos.x + bsize.width;
	float by1 = bpos.y;
	float by2 = bpos.y + bsize.height;

	return ax1 < bx2 && ax2 > bx1 && ay1 < by2 && ay2 > by1;
}

int collision_between_ball_wall(Ball *ball, Wall *wall) {
	return aabb_collision(ball->position, ball->size, wall->position, wall->size);
}

int collision_between_paddle_wall(Paddle *paddle, Wall *wall) {
	return aabb_collision(paddle->position, paddle->size, wall->position, wall->size);
}

int collision_between_paddle_ball(Paddle *paddle, Ball *ball) {
	return aabb_collision(paddle->position, paddle->size, ball->position, ball->size);
}
