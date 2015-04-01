#ifndef GAME_H
#define GAME_H

#include <GLFW/glfw3.h>

#include "ball.h"
#include "types.h"

struct Game {
	GLFWwindow *window;
	float current_frame, last_frame;

	Ball *ball;
};

Game *Game_init(GLFWwindow *window);
void Game_destroy(Game *game);
void Game_draw(Game *game);
void Game_update(Game *game);

#endif
