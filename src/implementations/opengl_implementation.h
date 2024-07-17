#ifndef OPENGL_IMPLEMENTATION_H
#define OPENGL_IMPLEMENTATION_H
#include "../rendering_implementation.h"
#include <GL/gl.h>
#include "../data_types.hpp"
#include "glad/glad.h"

namespace lux::implementations {
class OpenGLImplementation : public lux::RenderingImplementation {
  public:
    void clear(lux::Color color, float depth) override {
        glClearColor(color.r, color.g, color.b, color.a);
		glClearDepth(depth); 
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
    void clearColor(lux::Color color) override {
        glClearColor(color.r, color.g, color.b, color.a);
    	glClear(GL_COLOR_BUFFER_BIT);
    }

    void setProgramState(ProgramState programState) override {
        m_programState = programState;
    }

	void present() override;
	void clearDepth(float depth) override { 
		glClearDepth(depth); 
		glClear(GL_DEPTH_BUFFER_BIT);
	}
	void blit(RenderTarget *rtpFrom) override;
  private:
	ProgramState m_programState;
};
} // namespace lux::implementations
#endif
