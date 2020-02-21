//#include "game.h"
#include "Font.h"
//#include "GLFW/glfw3.h"
#include "Engine/Window.h"


// * WARNING: THIS IS ALL TEST CODE FOR NOW * //


// TODO: Abstract input in separate class
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}



int main()
{
	Font font("Font/Pixel.FNT");

	Window* window = new Window(1280, 720, "Test Window");

	// Initialize Glad
	if (!window->InitGlad())
	{
		return -1;
	}

	// Set key callback <- Also pull this out to an input class later
	glfwSetKeyCallback(window->GetGLFWWindowHandle(), key_callback);

	// Infinite loop until closed
	while (!glfwWindowShouldClose(window->GetGLFWWindowHandle()))
	{
		// Do things
		font.draw("I sucks", 0, 0);
		// Poll Events
		glfwPollEvents();
	}

	// Terminate GLFW <- Maybe pull this out to a core shutdown method or something
	delete(window);
	glfwTerminate();

	return 0;

	// OLD CODE //
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
