#include <stdlib.h>

#include "ball.h"
#include "input.h"

Ball *Ball_init(Game *game, float x, float y) {
	Ball *ball = malloc(sizeof(Ball));
	ball->game = game;

	ball->size = (Size){ .width = 10.0f, .height = 10.0f };
	ball->position = (Position){
		.x = x - ball->size.width / 2,
		.y = y - ball->size.height / 2
	};

	return ball;
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

void Ball_update(Ball *ball, float delta_time) {
}
