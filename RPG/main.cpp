//#include "game.h"
#include <GLFW/glfw3.h>

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int main()
{
	// Initialize GLFW
	if (!glfwInit())
	{
		return 1;
	}

	// Create GLFW Window
	GLFWwindow* window = glfwCreateWindow(640, 480, "Test Window", 0, 0);
	if (!window)
	{
		glfwTerminate();
		return 1;
	}

	// Set key callback
	glfwSetKeyCallback(window, key_callback);

	// Switching context
	//glfwMakeContextCurrent(window);
	
	// Infinite loop until closed
	while (!glfwWindowShouldClose(window))
	{
		// Do things

		// Poll Events
		glfwPollEvents();
	}

	// Terminate GLFW
	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
	// OLD CODE
	/*
	srand(time(NULL));

	game game;
	game.InitGame();

	Inventory inv;
	inv.AddItem(item());

	inv.DebugPrint();

	Character char_default;
	while (game.GetPlaying())
	{
		game.MainMenu();
	} */
}
