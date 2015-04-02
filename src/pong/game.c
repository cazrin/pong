#include <stdlib.h>

#include "game.h"
#include "physics.h"

Game *Game_init(GLFWwindow *window) {
	Game* game = malloc(sizeof(Game));
	game->window = window;

	float current_time = glfwGetTime();
	game->current_frame = current_time;
	game->last_frame = current_time;

	// Set viewport size (helps with retina displays)
	int frame_width, frame_height;
	glfwGetFramebufferSize(window, &frame_width, &frame_height);

	glViewport(0, 0, frame_width, frame_height);

	// Configure OpenGL for 2D
	int window_width, window_height;
	glfwGetWindowSize(window, &window_width, &window_height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0f, window_width, 0.0f, window_height, 0.0f, 1.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Create game entities
	game->ball = Ball_init(game, window_width/2, window_height/2);

	game->number_of_paddles = 2;
	game->paddles = calloc(sizeof(Paddle), game->number_of_paddles);

	game->paddles[0] = Paddle_init(game, 0, window_height / 2 - 50);
	game->paddles[0]->move_up_key = GLFW_KEY_W;
	game->paddles[0]->move_down_key = GLFW_KEY_S;

	game->paddles[1] = Paddle_init(game, window_width - 10, window_height / 2 - 50);
	game->paddles[1]->move_up_key = GLFW_KEY_UP;
	game->paddles[1]->move_down_key = GLFW_KEY_DOWN;

	game->number_of_walls = 4;
	game->walls = calloc(sizeof(Wall), game->number_of_walls);

	game->walls[0] = Wall_init(game, "BottomWall", 0, 0, window_width, 10);
	game->walls[1] = Wall_init(game, "TopWall", 0, window_height - 10, window_width, 10);
	game->walls[2] = Wall_init(game, "LeftWall", -10, 0, 10, window_height);
	game->walls[3] = Wall_init(game, "RightWall", window_width, 0, 10, window_height);

	return game;
}

void Game_destroy(Game *game) {
}

void Game_draw(Game *game) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	Ball_draw(game->ball);

	int i;
	for (i = 0; i < game->number_of_paddles; i++) {
		Paddle_draw(game->paddles[i]);
	}

	for (i = 0; i < game->number_of_walls; i++) {
		Wall_draw(game->walls[i]);
	}
}

void Game_update(Game *game) {
	float current_time = glfwGetTime();

	game->current_frame = current_time;
	float delta_time = game->current_frame - game->last_frame;
	game->last_frame = current_time;

	Ball_update(game->ball, delta_time);

	int i;
	for (i = 0; i < game->number_of_paddles; i++) {
		Paddle_update(game->paddles[i], delta_time);
	}

	Physics_update(game);
}
