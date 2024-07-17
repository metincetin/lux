#include "renderer.h"

#include "implementations/opengl_implementation.h"
#include "render_pass_queue.h"
#include "memory.h"
#include "stdio.h"
#include "render_state.h"
#include "render_state.h"

using namespace lux;

RenderPassQueue * renderer::m_renderPassQueue;
RenderState * renderer::m_renderState;
RenderingImplementation* renderer::m_renderingImplementation;

void renderer::initialize(Luxglproc proc){
	if (!gladLoadGLLoader((GLADloadproc)proc)) {
		printf("Could not initialize GLAD");
	}

	m_renderPassQueue = new RenderPassQueue();
	lux::memory::allocate(m_renderPassQueue);

	m_renderState = new RenderState();
	lux::memory::allocate(m_renderState);

	m_renderingImplementation = new implementations::OpenGLImplementation();
}

void renderer::renderLoop() {
	m_renderState->reset();
	for(auto ptr = m_renderPassQueue->begin(); ptr < m_renderPassQueue->end(); ++ptr) {
		(*ptr)->execute(m_renderState);
	}
}


void renderer::finalize(){
}
