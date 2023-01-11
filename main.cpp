/****************************************************************
 * This is the main rendering window for the game engine. This
 * program runs on OpenGL and GLFW.
 * 
 * Author(s):
 *   - Ryan Kwong
 * Status:
 *   - In progress: Can rendeer basic 2D objects. Currently
 * working towards texturing. Reference video
 * https://www.youtube.com/watch?v=45MIykWJ-C4&ab_channel=freeCodeCamp.org
*****************************************************************/


//Misc header files

#include <iostream>//for debugging
#include <glad/glad.h>//glad for OpenGL
#include <GLFW/glfw3.h>//GLFW for OpenGL
#include <stb/stb_image.h>

//GFX header files
#include "shaderClass.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"

//Engine heaer files
#include "sfx.h"

int main() {
	//Initialize GLFW
	glfwInit();

	//Define version of GLFW we are using
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLfloat verticies[] = {
		//Coordinates(XYZ)                    Colors(RGB)
		//          Coordinates(XYZ)           Colors(RGB)
		-0.5f, -0.5f, 0.0f,                 0.8f, 0.3f, 0.2f,
		-0.5f, 0.5f, 0.0f,                  0.8f, 0.3f, 0.2f,
		0.5f, 0.5f, 0.0f,                   1.0f, 0.6f, 0.32f,
		0.5f, -0.5f, 0.0f,                  0.9f, 0.45f, 0.17f,
	};

	GLuint indicies[] = {
		0, 2, 1,
		0, 3, 2
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

	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();

	GLuint uniID = glGetUniformLocation(shaderProgram.ID, "scale");

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
		glUniform1f(uniID, 0.5f);
		VAO1.Bind();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
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
