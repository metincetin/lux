#ifndef INDEX_BUFFER_H
#define INDEX_BUFFER_H

#include "memory.h"
#include <vector>

namespace lux {
class IndexBuffer {
  public:
    static IndexBuffer *create(std::vector<unsigned int>);

    unsigned int getEBO() const { return m_EBO; }

    size_t size() const { return m_size;}

  private:
    ~IndexBuffer() { lux::memory::free(sizeof(*this)); }

    unsigned int m_EBO;
    size_t m_size;
};
} // namespace lux
#endif
