/****************************************************************
 * This is the main rendering window for the game engine. This
 * program runs on OpenGL and GLFW.
 * 
 * Author(s):
 *   - Ryan Kwong
*****************************************************************/
#include <iostream>//for debugging, get rid of later
#include <glad/glad.h>//glad for OpenGL
#include <GLFW/glfw3.h>//GLFW for OpenGL

#include "shaderClass.h"
#include "VAO.h"
#include "VBO.h"
#include "Ebo.h"

int main() {
	//Initialize GLFW
	glfwInit();



	//Define version of GLFW we are using
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLfloat verticies[] = {
		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
		0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
		0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f,
		-0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f,
		0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f,
		0.0f, -0.5f * float(sqrt(3)) / 3, 0.0f
	};

	GLuint indicies[] = {
		0, 3, 5,
		3, 2, 4,
		5, 4, 1
	};

	//Create window object with size 800x800
	GLFWwindow* window = glfwCreateWindow(800, 800, "Game Engine", NULL, NULL);

	//Check to see if window failed to create
	if (window == NULL) {
		std::cout << "Failed to create GLFW Window";
		glfwTerminate();
		return -1;
	}

	//Create a context for the window
	glfwMakeContextCurrent(window);

	//Initialize GLAD
	gladLoadGL();


	//Define new viewport from x=0 y=0 to x=800 y=800
	glViewport(0, 0, 800, 800);

	Shader shaderProgram("default.vert", "default.frag");

	VAO VAO1;
	VAO1.Bind();

	VBO VBO1(verticies, sizeof(verticies));
	EBO EBO1(indicies, sizeof(indicies));

	VAO1.LinkVBO(VBO1, 0);
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();

	//Make viewport blue
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	//Clear back buffer and assign a new color
	glClear(GL_COLOR_BUFFER_BIT);
	//Swap back buffer to front buffer
	glfwSwapBuffers(window);

	//Main window while loop
	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		shaderProgram.Activate();
		VAO1.Bind();
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
		glfwSwapBuffers(window);
		//Track all events
		glfwPollEvents();
	}

	//Delete VAO, VBO, EBO and shader program
	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	shaderProgram.Delete();

	//Delete window
	glfwDestroyWindow(window);
	//End GLFW
	glfwTerminate();
	//End program
	return 0;
}