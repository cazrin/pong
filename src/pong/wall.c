#include <stdlib.h>

#include "wall.h"

Wall *Wall_init(Game *game, char *name, float x, float y, int width, int height) {
	Wall *wall = malloc(sizeof(Wall));
	wall->game = game;

	wall->name = name;

	wall->position = (Position){ .x = x, .y = y };
	wall->size = (Size){ .width = width, .height = height };

	return wall;
}

void Wall_draw(Wall *wall) {
	float current_color[4];
	glGetFloatv(GL_CURRENT_COLOR, current_color);

	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_QUADS);
		glVertex2f(wall->position.x, wall->position.y);
		glVertex2f(wall->position.x + wall->size.width, wall->position.y);
		glVertex2f(wall->position.x + wall->size.width, wall->position.y + wall->size.height);
		glVertex2f(wall->position.x, wall->position.y + wall->size.height);
	glEnd();

	glColor3f(current_color[0], current_color[1], current_color[2]);
}
