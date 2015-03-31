#include <GLFW/glfw3.h>

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

	while(!glfwWindowShouldClose(window)) {
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}
