#include "render_pass_queue.h"

using namespace lux;


void RenderPassQueue::enqueue(RenderPass *pass){
	for(int i = 0;i<m_queue.size();i++){
		if(m_queue[i]->getPriority() > pass->getPriority()){
			m_queue.insert(m_queue.begin() + i, pass);
			return;
		}
	}
	m_queue.push_back(pass);
}

void RenderPassQueue::dequeue(RenderPass *pass){
	for(int i = 0;i<m_queue.size();i++){
		if(m_queue[i] == pass){
			m_queue.erase(m_queue.begin() + i);
			return;
		}
	}
}
