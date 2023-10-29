#include <iostream>
#include <cmath>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

struct point {
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
};

static void render() {
	float dis = 0.7f;
	point A, B, C;
	A.x = 0.0f; A.y = (float)(dis / sqrt(3));
	B.x = -dis / 2; B.y = -(float)((dis / 2) * (sqrt(3) / 3));
	C.x = -B.x; C.y = B.y;
	constexpr int n = 300;
	constexpr float pi = 3.1415926535897f;
	float outer_radius = 0.3f;
	float inner_radius = outer_radius / 2.5f;
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	for (int i = 0; i < n; i++) {
		float angle = i / (float)n * pi * 2;
		float angle_next = (i + 1) / (float)n * pi * 2;
		if (angle > (pi * 5 / 6) && angle < (pi * 7 / 6)) continue;
		glVertex3f(outer_radius * sinf(angle) + A.x, outer_radius * cosf(angle) + A.y, 0.0f);
		glVertex3f(outer_radius * sinf(angle_next) + A.x, outer_radius * cosf(angle_next) + A.y, 0.0f);
		glVertex3f(inner_radius * sinf(angle) + A.x, inner_radius * cosf(angle) + A.y, 0.0f);

		glVertex3f(inner_radius * sinf(angle) + A.x, inner_radius * cosf(angle) + A.y, 0.0f);
		glVertex3f(inner_radius * sinf(angle_next) + A.x, inner_radius * cosf(angle_next) + A.y, 0.0f);
		glVertex3f(outer_radius * sinf(angle_next) + A.x, outer_radius * cosf(angle_next) + A.y, 0.0f);
	}
	glColor3f(0.0f, 1.0f, 0.0f);
	for (int i = 0; i < n; i++) {
		float angle = i / (float)n * pi * 2;
		float angle_next = (i + 1) / (float)n * pi * 2;
		if (angle > (pi * 1 / 6) && angle < (pi / 2)) continue;
		glVertex3f(outer_radius * sinf(angle) + B.x, outer_radius * cosf(angle) + B.y, 0.0f);
		glVertex3f(outer_radius * sinf(angle_next) + B.x, outer_radius * cosf(angle_next) + B.y, 0.0f);
		glVertex3f(inner_radius * sinf(angle) + B.x, inner_radius * cosf(angle) + B.y, 0.0f);

		glVertex3f(inner_radius * sinf(angle) + B.x, inner_radius * cosf(angle) + B.y, 0.0f);
		glVertex3f(inner_radius * sinf(angle_next) + B.x, inner_radius * cosf(angle_next) + B.y, 0.0f);
		glVertex3f(outer_radius * sinf(angle_next) + B.x, outer_radius * cosf(angle_next) + B.y, 0.0f);
	}
	glColor3f(0.0f, 0.0f, 1.0f);
	for (int i = 0; i < n; i++) {
		float angle = i / (float)n * pi * 2;
		float angle_next = (i + 1) / (float)n * pi * 2;
		if (angle < (pi / 6) || angle > (pi * 11 / 6)) continue;
		glVertex3f(outer_radius * sinf(angle) + C.x, outer_radius * cosf(angle) + C.y, 0.0f);
		glVertex3f(outer_radius * sinf(angle_next) + C.x, outer_radius * cosf(angle_next) + C.y, 0.0f);
		glVertex3f(inner_radius * sinf(angle) + C.x, inner_radius * cosf(angle) + C.y, 0.0f);

		glVertex3f(inner_radius * sinf(angle) + C.x, inner_radius * cosf(angle) + C.y, 0.0f);
		glVertex3f(inner_radius * sinf(angle_next) + C.x, inner_radius * cosf(angle_next) + C.y, 0.0f);
		glVertex3f(outer_radius * sinf(angle_next) + C.x, outer_radius * cosf(angle_next) + C.y, 0.0f);
	}
	glEnd();
}

int main() {
	glfwInit();
	GLFWwindow* window = glfwCreateWindow(768, 768, "example", NULL, NULL);
	glfwMakeContextCurrent(window);
	gladLoadGL();
	glPointSize(64.0f);
	glEnable(GL_POINT_SMOOTH);
	while (!glfwWindowShouldClose(window)) {
		render();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	return 0;
}