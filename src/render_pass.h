#ifndef RENDER_PASS_H
#define RENDER_PASS_H

namespace lux {

class RenderState;

class RenderPass {
public:

  virtual void execute(lux::RenderState *state) = 0;

  virtual int getPriority() const { return 0; };
};
} // namespace lux

#endif
