#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

int main()
{
	// Initialize glfw
	glfwInit();

	// Pass openGL version to glfw
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Now create a window
	GLFWwindow* window = glfwCreateWindow(800, 800, "YoutubeGL", NULL, NULL);

	// Check window is created
	if (window == NULL)
	{
		std::cout << "Window is not created." << std::endl;
		glfwTerminate();
		return -1;
	}

	//  Pass context to windows
	glfwMakeContextCurrent(window);

	// Load glad function
	gladLoadGL();

	// Set up viewport
	glViewport(0, 0, 800, 800);

	// Render color to back buffer and swap with front buffer
	glClearColor(0.07f, 0.11f, 0.15f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);

	// Create loop to prevent window from closing prematurely.
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	glfwTerminate();
}