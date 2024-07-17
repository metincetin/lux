#include "glad/glad.h"
#include "renderer.h"

#include "index_buffer.h"
#include "vertex_buffer.h"

#include "iostream"
#include <GL/gl.h>
#include <GLFW/glfw3.h>

#include "render_pass.h"
#include "render_state.h"

#include "shaders.h"
#include <cstdio>
#include <iterator>

#include "memory.h"
#include "vertex_structure.h"

class HelloWorldPass : public lux::RenderPass {

    lux::VertexBuffer *vertexBuffer;
    lux::IndexBuffer *indexBuffer;

    lux::MaterialDefinition * mat;

public:
    HelloWorldPass() {

        auto vs = new lux::Shader(vertexShaderSource, lux::Vertex);
        auto fs = new lux::Shader(fragmentShaderSource, lux::Fragment);
        mat = new lux::MaterialDefinition(vs, fs);

        float vertices[] = {
            0.5f,  0.5f,  0.0f,
            0.5f,  -0.5f, 0.0f,
            -0.5f, -0.5f, 0.0f,
            -0.5f, 0.5f,  0.0f
        };
        unsigned int indices[] = {
            0, 1, 3,
            1, 2, 3
        };

		lux::VertexStructure vstruct;

		vstruct.add(lux::Position, 3);

        vertexBuffer = lux::VertexBuffer::create(vstruct,
            std::vector<float>(std::begin(vertices), std::end(vertices)));
        indexBuffer = lux::IndexBuffer::create(
            std::vector<unsigned int>(std::begin(indices), std::end(indices)));
    }

    void execute(lux::RenderState *state) override {
        lux::renderer::getRenderingImplementation()->clearColor(lux::Color::black());
        state->setProgramState(mat->getProgramState());
        state->setVertexBuffer(vertexBuffer);
        state->setIndexBuffer(indexBuffer);
        state->drawIndexed();
        state->unbind();
    }
};

int main() {
    printf("LUX SAMPLES: Hello, rectangle!\n");

    if (!glfwInit()) {
        printf("Could not initialize glfw");
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *win = glfwCreateWindow(600, 600, "GLFW Test", 0, 0);

    glfwMakeContextCurrent(win);

    lux::renderer::initialize((lux::Luxglproc)glfwGetProcAddress);

    lux::renderer::getQueue()->enqueue(new HelloWorldPass());

    while (!glfwWindowShouldClose(win)) {

        lux::renderer::renderLoop();

        printf("Draw Calls: %u\n", lux::renderer::getState()->getDrawCalls());
        glfwSwapBuffers(win);
        glfwPollEvents();
    }

    auto mem = lux::memory::getUsage();
    printf("MemUsage: %lu %s", lux::memory::getUsage(),
           mem > 1 ? "bytes" : "byte");
    lux::renderer::finalize();

    glfwDestroyWindow(win);

    glfwTerminate();
}
