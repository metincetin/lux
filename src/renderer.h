#ifndef RENDERER_H
#define RENDERER_H
#include "glad/glad.h"
#include "render_pass_queue.h"
#include "rendering_implementation.h"
#include <iterator>

namespace lux {

	typedef void (*Luxglproc)(void);

	class renderer {
	public:
		static void initialize(Luxglproc proc);
		static void finalize();

		static void renderLoop();
		static RenderPassQueue* getQueue() { return m_renderPassQueue; }

		static RenderState * getState() { return m_renderState; }
		static RenderingImplementation* getRenderingImplementation() { return m_renderingImplementation; }
	private:
		static RenderPassQueue * m_renderPassQueue;
		static RenderState * m_renderState;
		static RenderingImplementation * m_renderingImplementation;
	};

}

#endif