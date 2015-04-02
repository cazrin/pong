#include <stdlib.h>

#include "game.h"

Game *Game_init(GLFWwindow *window) {
	Game* game = malloc(sizeof(Game));

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
	game->paddles[1] = Paddle_init(game, window_width - 10, window_height / 2 - 50);

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
}
