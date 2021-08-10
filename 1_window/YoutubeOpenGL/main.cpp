#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

int main()
{
	// Using GLFW to create window

	// Initialize GLFW
	glfwInit();

	// Tell GFLW which version of OpenGL we are using
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create window object
	GLFWwindow* window = glfwCreateWindow(800, 800, "YoutubeOpenGL", NULL, NULL);

	// Error checking
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	// Context in openGL
	glfwMakeContextCurrent(window);

	// Use glad to change windows
	gladLoadGL();
	glViewport(0, 0, 800, 800);

	// Preparing back buffer
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);

	// Loop to prevent window from closing
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
	}
	
	glfwDestroyWindow(window);

	// Terminate GLFW
	glfwTerminate();
}