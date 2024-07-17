#include "OBJ_Loader.h"
#include "glad/glad.h"
#include "lux.h"
#include <GLFW/glfw3.h>
#include <cmath>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>

#include "shaders.h"
#include "vertex_structure.h"

class MeshRenderPass : public lux::RenderPass {
  public:
    MeshRenderPass(lux::Mesh *mesh, lux::MaterialDefinition *material) {
        m_mesh = mesh;
        m_material = material;
    }

  private:
    lux::Mesh *m_mesh;
    lux::MaterialDefinition *m_material;

    void execute(lux::RenderState *state) override {
        auto r = lux::renderer::getRenderingImplementation();

        state->setProgramState(m_material->getProgramState());
        r->clear(lux::Color::black(), 1);

        state->setVertexBuffer(m_mesh->getVertexBuffer());
        state->setIndexBuffer(m_mesh->getIndexBuffer());

        state->setViewMatrix(glm::lookAt(
            glm::vec3(fmod(0, 10.f), 0, 10), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)));
        glm::mat4 projection =
            glm::perspective(glm::radians(40.f), 1.f, 0.1f, 100.f);
        state->setProjectionMatrix(projection);

        state->updateViewProjection();
        state->applyUniforms();

        state->drawIndexed();
    }
};

lux::Mesh *createMesh() {

    auto vertexStructure = lux::VertexStructure();
    vertexStructure.add(lux::Entry::Position, 3);
    vertexStructure.add(lux::Entry::Normal, 3);

    auto loader = new objl::Loader();
    loader->LoadFile("assets/suzanne.obj");

    auto mesh = new lux::Mesh();

    auto objMesh = loader->LoadedMeshes[0];

    auto vbData = std::vector<float>();
    auto ibData = objMesh.Indices;

    for (auto v : loader->LoadedMeshes[0].Vertices) {
        vbData.push_back(v.Position.X);
        vbData.push_back(v.Position.Y);
        vbData.push_back(v.Position.Z);
        vbData.push_back(v.Normal.X);
        vbData.push_back(v.Normal.Y);
        vbData.push_back(v.Normal.Z);
    }

    auto vertexBuffer = lux::VertexBuffer::create(vertexStructure, vbData);
    auto indexBuffer = lux::IndexBuffer::create(ibData);

    mesh->setVertexBuffer(vertexBuffer);
    mesh->setIndexBuffer(indexBuffer);

    return mesh;
}

int main() {
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    auto win = glfwCreateWindow(600, 600, "Mesh", 0, 0);

    glfwMakeContextCurrent(win);
    lux::renderer::initialize((lux::Luxglproc)glfwGetProcAddress);

    auto mesh = createMesh();

    auto vs = new lux::Shader(vertexShaderSource, lux::Stage::Vertex);
    auto fs = new lux::Shader(fragmentShaderSource, lux::Stage::Fragment);

    auto material = new lux::MaterialDefinition(vs, fs);

    auto renderPass = new MeshRenderPass(mesh, material);

    lux::renderer::getQueue()->enqueue(renderPass);

    while (!glfwWindowShouldClose(win)) {
        lux::renderer::renderLoop();

        glfwPollEvents();
        glfwSwapBuffers(win);
    }

    glfwDestroyWindow(win);
    glfwTerminate();

    return 0;
}
