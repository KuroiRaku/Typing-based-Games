#include "Window.h"

static bool s_GLFWInitialized = false;

// Default constructor, creates a window with the given parameters and initializes GLFW
Window::Window(int width, int height, const char* title)
{
	this->_Width = width;
	this->_Height = height;
	this->_Title = title;

	InitGLFW();

	_Window = glfwCreateWindow(_Width, _Height, _Title, 0, 0);
	if (!_Window)
	{
		glfwTerminate();
	}

	// Sets the window as the current GLFW context
	glfwMakeContextCurrent(_Window);
}

// Default Destructor, destroys the window
Window::~Window()
{
	glfwDestroyWindow(_Window);
}

// Returns the direct handle to the window
GLFWwindow* Window::GetGLFWWindowHandle()
{
	return _Window;
}

// Initializes GLFW
void Window::InitGLFW()
{
	if (!s_GLFWInitialized)
	{
		int success = glfwInit();
		s_GLFWInitialized = true;
	}
}

// Initializes Glad
bool Window::InitGlad()
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		//std::cout << "Failed to initialize GLAD" << std::endl;
		glfwTerminate();
		glfwDestroyWindow(_Window);
		return false;
	}

	return true;
}