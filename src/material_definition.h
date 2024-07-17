#ifndef MATERIAL_DEFINITION_H
#define MATERIAL_DEFINITION_H

#include "program_state.h"
#include "rendering_implementation.h"
#include "shader.h"
#include <glm/fwd.hpp>
namespace lux {

struct Color;

struct MaterialDefinition {
  public:
    MaterialDefinition(Shader *vertex, Shader *fragment) {
        m_vertexShader = vertex;
        m_fragmentShader = fragment;

        m_program = new ProgramState();
		m_program->cullFace = Front;
		m_program->depthWrite = true;

        auto glProgram = glCreateProgram();
        vertex->attach(glProgram);
        fragment->attach(glProgram);
        glLinkProgram(glProgram);

        int success;
        char infoLog[512];

        glGetProgramiv(glProgram, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(glProgram, 512, 0, infoLog);
            std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n"
                      << infoLog << std::endl;
        }

        m_program->glProgram = glProgram;
    }

    void setFloat(const char *, float);
    void setInt(const char *, int);
    void setVec2(const char *, glm::vec2);
    void setVec3(const char *, glm::vec3);
    void setVec4(const char *, glm::vec4);
    void setColor(const char *, Color);

    ProgramState *getProgramState() const { return m_program; }

private:
    Shader *m_vertexShader;
    Shader *m_fragmentShader;
    ProgramState *m_program;
};
} // namespace lux

#endif
