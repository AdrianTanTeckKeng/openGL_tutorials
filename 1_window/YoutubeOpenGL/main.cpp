#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

int main()
{
	// Initialize GLFW(a program that interfaces with OpenGL to draw windows)
	glfwInit();

	// Tell GLFW version of OpenGL
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create window
	GLFWwindow* window = glfwCreateWindow(800, 800, "OpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Window fails to load." << std::endl;
		glfwTerminate();
		return -1;
	}

	// Make window current context
	glfwMakeContextCurrent(window);

	// Code to render window
	gladLoadGL();
	glViewport(0, 0, 800, 800);

	glClearColor(0.07f, 0.11f, 0.15f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);

	// Loop to keep window from closing
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
	}
	// Terminate GLFW
	glfwTerminate();
	return 0;
}