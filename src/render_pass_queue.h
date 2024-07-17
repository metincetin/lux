#ifndef RENDER_PASS_QUEUE_H
#define RENDER_PASS_QUEUE_H

#include "render_pass.h"
#include <vector>

namespace lux {

class RenderPassQueue {
private:
  std::vector<lux::RenderPass*> m_queue;

public:
  void enqueue(lux::RenderPass *pass);
  void dequeue(lux::RenderPass *pass);

   [[nodiscard]] std::vector<lux::RenderPass*>::iterator begin() { return m_queue.begin(); };
   [[nodiscard]] std::vector<lux::RenderPass*>::iterator end() { return m_queue.end(); };
};
}

#endif
