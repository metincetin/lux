#ifndef COMMON_H
#define COMMON_H
#include "renderer.h"
#include <GLFW/glfw3.h>


inline void start() {
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    auto win = glfwCreateWindow(600, 600, "Mesh", 0, 0);

    glfwMakeContextCurrent(win);
    lux::renderer::initialize((lux::Luxglproc)glfwGetProcAddress);

    while (!glfwWindowShouldClose(win)) {
        lux::renderer::renderLoop();

        glfwPollEvents();
        glfwSwapBuffers(win);
    }
}

#endif
