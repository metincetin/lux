#include "vertex_buffer.h"
#include "index_buffer.h"

namespace lux{
	class Mesh{
		public:
			VertexBuffer* getVertexBuffer() const { return m_vertexBuffer; }
			IndexBuffer* getIndexBuffer() const { return m_indexBuffer; }
			void setVertexBuffer(VertexBuffer* value) { m_vertexBuffer = value; }
			void setIndexBuffer(IndexBuffer* value) { m_indexBuffer = value; }
		private:
			VertexBuffer * m_vertexBuffer;
			IndexBuffer * m_indexBuffer;
	};
}
