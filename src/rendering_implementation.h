#ifndef RENDERING_IMPLEMENTATION_H
#define RENDERING_IMPLEMENTATION_H
#include "data_types.hpp"
#include "render_state.h"

namespace lux {

class RenderTarget {
    void *data;
};

class RenderingImplementation {
  public:
    virtual void clear(lux::Color, float) = 0;
    virtual void clearColor(lux::Color color) = 0;
    virtual void clearDepth(float depth) = 0;
    virtual void blit(RenderTarget *rtpFrom) = 0;

    virtual void setProgramState(ProgramState programState) = 0;

    virtual void present() = 0;

    void setRenderState(RenderState *value) { m_renderState = value; }

  private:
    RenderState *m_renderState = nullptr;
};
} // namespace lux
#endif
