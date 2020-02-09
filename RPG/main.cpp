//#include "game.h"
//#include "GLFW/glfw3.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Font.h"
#include "Engine/Window.h"

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}



int main()
{
	Font font("Font/Pixel.fnt");
	
	Window* window = new Window(1280, 720, "Test Window");

	// Set key callback
	glfwSetKeyCallback(window->GetGLFWWindowHandle(), key_callback);

	// Switching context
	//glfwMakeContextCurrent(window);
	
	// Infinite loop until closed
	while (!glfwWindowShouldClose(window->GetGLFWWindowHandle()))
	{
		// Do things
		font.draw("I sucks", 0, 0);
		// Poll Events
		glfwPollEvents();
	}

	// Terminate GLFW
	delete(window);
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