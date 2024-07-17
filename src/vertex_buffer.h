#ifndef VERTEX_BUFFER_H
#define VERTEX_BUFFER_H

#include "memory.h"
#include <vector>

#include "vertex_structure.h"

namespace lux {
class VertexBuffer {
  public:
    static VertexBuffer *create(VertexStructure, std::vector<float>);

	unsigned int getVBO() const { return m_VBO; }
	unsigned int getVAO() const { return m_VAO; }

  private:
    ~VertexBuffer() { lux::memory::free(sizeof(*this)); }

	unsigned int m_VBO;
	unsigned int m_VAO;
};
} // namespace lux

#endif
