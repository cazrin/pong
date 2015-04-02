#include <GLFW/glfw3.h>

#include "input.h"

int Input_key_pressed(Game *game, int key) {
	int state = glfwGetKey(game->window, key);
	return state == GLFW_PRESS || state == GLFW_REPEAT;
}
