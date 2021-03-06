#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include "shaderClass.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"

int main()
{
	// Initialize GLFW(the program that creates window and process inputs)
	glfwInit();


	// Tell GLFW which version of openGL we are using
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	// Create a window object
	GLFWwindow* window = glfwCreateWindow(800, 800, "OpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Window fails to load" << std::endl;
		glfwTerminate();
		return -1;
	}

	// Make window the current context
	glfwMakeContextCurrent(window);


	// Load GLAD(they know the address of openGL functions)
	gladLoadGL();
	glViewport(0, 0, 800, 800);	

	// Create Shader program
	Shader shaderProgram("default.vert", "default.frag");

	// Create vertices data
	GLfloat vertices[] =
	{
		// Coordinates // Colors //
		-0.5f, -0.5f * float(sqrt(3)) / 3,     0.0f, 0.8f, 0.3f, 0.02f,
		 0.5f, -0.5f * float(sqrt(3)) / 3,     0.0f, 0.8f, 0.3f, 0.02f,
		 0.0f,  0.5f * float(sqrt(3)) * 2 / 3, 0.0f, 1.0f, 0.6f, 0.32f,
		-0.25f, 0.5f * float(sqrt(3)) / 6,     0.0f, 0.9f, 0.45f, 0.17f,
		 0.25f, 0.5f * float(sqrt(3)) / 6,     0.0f, 0.9f, 0.45f, 0.17f,
		 0.0f, -0.5f * float(sqrt(3)) / 3,     0.0f, 0.8f, 0.3f,  0.02f
	};

	GLuint indices[] =
	{
		0, 3, 5,
		3, 2, 4,
		5, 4, 1
	};

	// Next, set up VAO and VBO
	
	VAO VAO1;
	VAO1.Bind();

	// Initialize and automatically bind
	VBO VBO1(vertices, sizeof(vertices));

	// Initialize and automatically bind
	EBO EBO1(indices, sizeof(indices));

	// Link position
	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 6*sizeof(float), (void*)0);
	// Link Color
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 6*sizeof(float), (void*)(3* sizeof(float)));

	//VAO1.Unbind();
	//VBO1.Unbind();
	//EBO1.Unbind();

	GLuint uniID = glGetUniformLocation(shaderProgram.ID, "scale");



	// Set up color buffer
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		shaderProgram.Activate();
		glUniform1f(uniID, 0.5);
		VAO1.Bind();
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	shaderProgram.Delete();
	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	// Termiante GLFW
	glfwTerminate();
	return 0;
}