#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


int main() {

	// Initialize GLFW
	glfwInit();

	// Tell GLFW what version OpenGL we are using 3.3
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions 

	// Create a GLFWwindow object of 800 by 800 pixels, naming it "HelloWorld"
	GLFWwindow* window = glfwCreateWindow(800, 800, "HelloWorld", NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

	// Load GLAD so it configures OpenGL
	gladLoadGL();

	// Specify the viewpoer of OpwnGL in the Window
	// In this case he viewport goies from x = 0, y = 0, x = 800, y = 800 
	glViewport(0, 0, 800, 800);

	// Specify the color of the background
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	// Clear the back buffer and assign the new color to it
	glClear(GL_COLOR_BUFFER_BIT);
	// Swap the back buffer with the front buffer
	glfwSwapBuffers(window);

	// Main while loop
	while (!glfwWindowShouldClose(window)) {
		// Take care of all GLFW events
		glfwPollEvents();
	}

	// Deletes window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}