#ifndef GAME_H
#define GAME_H

#include <GLFW/glfw3.h>

typedef struct Game Game;

struct Game {
	GLFWwindow *window;

	float current_frame, last_frame;
};

Game* Game_init(GLFWwindow *window);
void Game_destroy(Game *game);
void Game_draw(Game *game);
void Game_update(Game *game);

#endif
