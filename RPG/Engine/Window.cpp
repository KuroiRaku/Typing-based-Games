#include "Window.h"

static bool s_GLFWInitialized = false;

Window::Window(int width, int height, const char* title)
{
	this->_Width = width;
	this->_Height = height;
	this->_Title = title;

	if (!s_GLFWInitialized)
	{
		int success = glfwInit();
		s_GLFWInitialized = true;
	}

	_Window = glfwCreateWindow(_Width, _Height, _Title, nullptr, nullptr);
	glfwMakeContextCurrent(_Window);

	if (!_Window)
	{
		glfwTerminate();
	}
}

Window::~Window()
{
	glfwDestroyWindow(_Window);
}

GLFWwindow* Window::GetGLFWWindowHandle()
{
	return _Window;
}