#pragma once
#include "GLFW/glfw3.h"

class Window
{
public:
	Window(int width, int height, const char* title);
	~Window();
	// Add method called every frame (Update)
	// Getters for width, height and Window handle
	GLFWwindow* GetGLFWWindowHandle();
	// TODO: Add a temp boolean tag to return an error in case window failed to be created (Maybe a better solution is to just make another method for the creation)

private:
	int _Width;
	int _Height;
	const char* _Title;

	GLFWwindow* _Window;
};

