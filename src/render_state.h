#ifndef RENDER_STATE_H
#define RENDER_STATE_H

#include "glad/glad.h"
#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "index_buffer.h"
#include "material_definition.h"
#include "program_state.h"
#include "vertex_buffer.h"
#include "vertex_structure.h"

namespace lux {
class RenderState {
  public:
    void setVertexBuffer(VertexBuffer *vb) { glBindVertexArray(vb->getVAO()); }

    void setIndexBuffer(IndexBuffer *ib) {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ib->getEBO());
        indexBufferSize = ib->size();
    }

    void setViewMatrix(glm::mat4x4 value) { m_view = value; }
    void setProjectionMatrix(glm::mat4x4 value) { m_projection = value; }

    void setViewAndProjection(glm::mat4x4 view, glm::mat4x4 projection) {
        m_view = view;
        m_projection = projection;

        updateViewProjection();
    }

    void updateViewProjection() { m_viewProjection = m_projection * m_view; }

    void applyUniforms() {
        int vpLocation =
            glGetUniformLocation(m_programState->glProgram, "uViewProjection");

        glUniformMatrix4fv(vpLocation, 1, GL_FALSE,
                           glm::value_ptr(m_viewProjection[0]));
    }

    void unbind() { glBindVertexArray(0); }

    void setProgramState(ProgramState *value) {
        if (value == m_programState)
            return;
        m_programState = value;
        glUseProgram(value->glProgram);

        switch (value->cullFace) {
        case Front:
            glEnable(GL_CULL_FACE);
            glCullFace(GL_FRONT);
            glFrontFace(GL_CW);
        case Back:
            glEnable(GL_CULL_FACE);
            glCullFace(GL_BACK);
            glFrontFace(GL_CW);
        case Both:
            glDisable(GL_CULL_FACE);
            break;
        }

        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);
        glDepthMask(value->depthWrite ? GL_TRUE : GL_FALSE);
    }

    void drawIndexed() {
        glDrawElements(GL_TRIANGLES, indexBufferSize, GL_UNSIGNED_INT, 0);
        m_drawCalls++;
    }

    void drawInstanced(unsigned int instanceCount) {
        glDrawElementsInstanced(GL_TRIANGLES, indexBufferSize, GL_UNSIGNED_INT,
                                0, instanceCount);
        m_drawCalls++;
    }

    unsigned int getDrawCalls() const { return m_drawCalls; }

    void reset() { m_drawCalls = 0; }

  private:
    unsigned int m_drawCalls = 0;
    ProgramState *m_programState;
    glm::mat4x4 m_view;
    glm::mat4x4 m_projection;
    glm::mat4x4 m_viewProjection;
    size_t indexBufferSize;
};
} // namespace lux
#endif
