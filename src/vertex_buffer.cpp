
#include "vertex_buffer.h"
#include "glad/glad.h"
#include "memory.h"

lux::VertexBuffer *lux::VertexBuffer::create(VertexStructure structure, std::vector<float> data) {
    auto buffer = new VertexBuffer();


	glGenBuffers(1, &buffer->m_VBO);
	glGenVertexArrays(1, &buffer->m_VAO);

	glBindVertexArray(buffer->m_VAO);

	glBindBuffer(GL_ARRAY_BUFFER, buffer->m_VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * data.size(), data.data(), GL_STATIC_DRAW);

	size_t stride = 0;
	for(size_t i = 0;i<structure.getSize();i++) {
		auto entry = structure.getEntry(i);
		stride += std::get<1>(entry) * sizeof(float);
	}
	for(size_t i = 0;i<structure.getSize();i++) {
		auto entry = structure.getEntry(i);
		auto size = std::get<1>(entry);

		auto offset = i * size * sizeof(float);
		glVertexAttribPointer(i, size, GL_FLOAT, GL_FALSE, stride, (void*) offset);
		glEnableVertexAttribArray(i);
	}

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

    lux::memory::allocate(buffer);

    return buffer;
}
