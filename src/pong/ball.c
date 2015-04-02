#include <stdlib.h>
#include <string.h>

#include "ball.h"
#include "input.h"
#include "wall.h"

Ball *Ball_init(Game *game, float x, float y) {
	Ball *ball = malloc(sizeof(Ball));
	ball->game = game;

	ball->original_position = (Position){
		.x = x - ball->size.width / 2,
		.y = y - ball->size.height / 2
	};

	ball->size = (Size){ .width = 10.0f, .height = 10.0f };

	Ball_reset(ball);

	return ball;
}

void Ball_collision(Ball *ball, Collision *collision) {
	if (strcmp(collision->entity_name, "Paddle") == 0) {
		Paddle *paddle = (Paddle *)collision->entity;

		if (ball->direction.x < 0) {
			ball->position.x = paddle->position.x + paddle->size.width;
		} else {
			ball->position.x = paddle->position.x - ball->size.width;
		}

		ball->direction.x = -ball->direction.x;
		ball->direction.y = ((ball->position.y - paddle->position.y) / paddle->size.height) - 0.5f;
	}

	if (strcmp(collision->entity_name, "BottomWall") == 0) {
		Wall *wall = (Wall *)collision->entity;

		ball->position.y = wall->position.y + wall->size.height;
		ball->direction.y = -ball->direction.y;
	}

	if (strcmp(collision->entity_name, "TopWall") == 0) {
		Wall *wall = (Wall *)collision->entity;

		ball->position.y = wall->position.y - ball->size.height;
		ball->direction.y = -ball->direction.y;
	}

	if (strcmp(collision->entity_name, "LeftWall") == 0) {
		ball->game->paddles[1]->score += 1;
		Ball_reset(ball);
	}

	if (strcmp(collision->entity_name, "RightWall") == 0) {
		ball->game->paddles[0]->score += 1;
		Ball_reset(ball);
	}
}

void Ball_draw(Ball *ball) {
	float current_color[4];
	glGetFloatv(GL_CURRENT_COLOR, current_color);

	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_QUADS);
		glVertex2f(ball->position.x, ball->position.y);
		glVertex2f(ball->position.x + ball->size.width, ball->position.y);
		glVertex2f(ball->position.x + ball->size.width, ball->position.y + ball->size.height);
		glVertex2f(ball->position.x, ball->position.y + ball->size.height);
	glEnd();

	glColor3f(current_color[0], current_color[1], current_color[2]);
}

void Ball_reset(Ball *ball) {
	ball->position = ball->original_position;
	ball->direction = (Vector2D){ .x = 1.0f, .y = -0.5f };
	ball->speed = 200.0f;
}

void Ball_update(Ball *ball, float delta_time) {
	ball->position.x += (ball->direction.x * ball->speed) * delta_time;
	ball->position.y += (ball->direction.y * ball->speed) * delta_time;
}
