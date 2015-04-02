#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"
#include "paddle.h"

Paddle *Paddle_init(Game *game, float x, float y) {
	Paddle *paddle = malloc(sizeof(Paddle));
	paddle->game = game;

	paddle->size = (Size){ .width = 10.f, .height = 100.f };
	paddle->position = (Position){
		.x = x,
		.y = y
	};

	paddle->move_speed = 500.0f;

	return paddle;
}

void Paddle_collision(Paddle *paddle, Collision *collision) {
	if (strcmp(collision->entity_name, "BottomWall") == 0) {
		Wall *wall = collision->entity;
		paddle->position.y = wall->position.y + wall->size.height;
	}

	if (strcmp(collision->entity_name, "TopWall") == 0) {
		Wall *wall = collision->entity;
		paddle->position.y = wall->position.y - paddle->size.height;
	}
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
	if (Input_key_pressed(paddle->game, paddle->move_up_key)) {
		paddle->position.y += paddle->move_speed * delta_time;
	}

	if (Input_key_pressed(paddle->game, paddle->move_down_key)) {
		paddle->position.y -= paddle->move_speed * delta_time;
	}
}
