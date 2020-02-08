#pragma once
#include "Core.h"

class Window
{
public:
	Window(int width, int height, const char* title);
	~Window();
	// Add method called every frame (Update)
	// Getters for width, height and Window handle
	GLFWwindow* GetGLFWWindowHandle();
	// Initializes Glad (its here because I will call it outside the constructor)
	bool InitGlad();
	// TODO: Add a temp boolean tag to return an error in case window failed to be created (Maybe a better solution is to just make another method for the creation)

private:
	int _Width;
	int _Height;
	const char* _Title;

	GLFWwindow* _Window;

	void InitGLFW();
};

