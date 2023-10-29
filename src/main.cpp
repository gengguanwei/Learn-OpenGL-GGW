#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main() {
	glfwInit();
	GLFWwindow* window = glfwCreateWindow(1024, 768, "example", NULL, NULL);
	glfwMakeContextCurrent(window);
	gladLoadGL();
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
	}
	return 0;
}