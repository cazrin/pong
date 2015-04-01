#include <GLFW/glfw3.h>

#include "game.h"

int main(int argc, char *argv[]) {
	GLFWwindow *window;

	if (!glfwInit())
		return -1;

	window = glfwCreateWindow(640, 480, "Pong", NULL, NULL);

	if (!window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	Game *game = Game_init(window);

	while(!glfwWindowShouldClose(window)) {
		Game_update(game);
		Game_draw(game);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	Game_destroy(game);

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}
