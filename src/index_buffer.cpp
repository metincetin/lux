#include "index_buffer.h"
#include "glad/glad.h"
#include "memory.h"

lux::IndexBuffer* lux::IndexBuffer::create(std::vector<unsigned int> data){
	auto inst = new IndexBuffer();

	glGenBuffers(1, &inst->m_EBO);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, inst->m_EBO);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * data.size(), data.data(), GL_STATIC_DRAW);

	memory::allocate(data);

	inst->m_size = data.size();

	return inst;
}
