#include "renderer.h"

#include <GLFW/glfw3.h>
#include <cstdio>
#include <thread>

#include "memory.h"

int main() {
	printf("LUX SAMPLES: Windowing\n");

	if (!glfwInit()) {
		printf("Could not initialize glfw");
	}

	GLFWwindow *win = glfwCreateWindow(600, 600, "GLFW Test", 0, 0);


	glfwMakeContextCurrent(win);

	lux::renderer::initialize((lux::Luxglproc)glfwGetProcAddress);

	while(!glfwWindowShouldClose(win)) {
		glfwPollEvents();
		lux::renderer::renderLoop();
	}

	auto mem = lux::memory::getUsage();
	printf("MemUsage: %lu %s", lux::memory::getUsage(), mem > 1 ? "bytes" : "byte");
	lux::renderer::finalize();

	glfwDestroyWindow(win);

	glfwTerminate();
}
