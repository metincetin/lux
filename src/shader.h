#ifndef SHADER_H
#define SHADER_H

#include "glad/glad.h"
#include <iostream>
namespace lux {

enum Stage { Vertex, Fragment };

class Shader {
  public:
    Shader(const char *src, Stage stage) {
        unsigned int stg = 0;
        switch (stage) {
        case Vertex:
            stg = GL_VERTEX_SHADER;
            break;
        case Fragment:
            stg = GL_FRAGMENT_SHADER;
            break;
        }

        m_glShader = glCreateShader(stg);
        glShaderSource(m_glShader, 1, &src, 0);
        glCompileShader(m_glShader);


        int success;
        char infoLog[512];

        glGetShaderiv(m_glShader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(m_glShader , 512, 0, infoLog);
            std::cout << "("<< ((stage == 0)? "VERTEX" : "FRAGMENT") <<") Shader compilation failed: \n"
                      << infoLog << std::endl;
        }
    }

    void attach(unsigned int program) const { glAttachShader(program, m_glShader);}

  private:
    unsigned int m_glShader;

};
} // namespace lux

#endif
