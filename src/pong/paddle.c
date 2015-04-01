#include <stdlib.h>

#include "paddle.h"

Paddle *Paddle_init(Game *game, float x, float y) {
	Paddle *paddle = malloc(sizeof(Paddle));
	paddle->game = game;

	paddle->size = (Size){ .width = 10.f, .height = 100.f };
	paddle->position = (Position){
		.x = x,
		.y = y
	};

	return paddle;
}

void Paddle_draw(Paddle *paddle) {
	float current_color[4];
	glGetFloatv(GL_CURRENT_COLOR, current_color);

	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_QUADS);
		glVertex2f(paddle->position.x, paddle->position.y);
		glVertex2f(paddle->position.x + paddle->size.width, paddle->position.y);
		glVertex2f(paddle->position.x + paddle->size.width, paddle->position.y + paddle->size.height);
		glVertex2f(paddle->position.x, paddle->position.y + paddle->size.height);
	glEnd();

	glColor3f(current_color[0], current_color[1], current_color[2]);
}

void Paddle_update(Paddle *paddle, float delta_time) {
}
