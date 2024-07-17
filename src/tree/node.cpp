#include "node.h"
#include <algorithm>
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtx/quaternion.hpp>

void lux::tree::Node::addChild(Node *node){
	if (std::find(m_children.begin(), m_children.end(), node) != m_children.end()) {
		m_children.push_back(node);
		node->m_parent = this;
		node->setWorldMatrix(m_localToWorld);
	}
}


void lux::tree::Node::setPosition(glm::vec3 value){
	m_position = value;
	generateLocalMatrix();
}

void lux::tree::Node::setEuler(glm::vec3 value){
	m_rotation = glm::quat(value);
	generateLocalMatrix();
}

void lux::tree::Node::setRotation(glm::quat value){
	m_rotation = value;
	generateLocalMatrix();
}

void lux::tree::Node::setScale(glm::vec3 value){
	m_scale = value;
	generateLocalMatrix();
}

void lux::tree::Node::generateLocalMatrix(){
	auto matrix = glm::identity<glm::mat4x4>();
	matrix = glm::translate(matrix, getPosition());
	auto rotationMatrix = glm::toMat4(getRotation());

	matrix = matrix * rotationMatrix;

	matrix = glm::scale(matrix, getScale());

	m_localToWorld = matrix;
	updateChildrenWorldMatrices();
}

void lux::tree::Node::updateChildrenWorldMatrices() {
	for(auto c : m_children){
		c->setWorldMatrix(m_localToWorld);
	}
}

void lux::tree::Node::setWorldMatrix(glm::mat4x4 value){
	m_worldMatrix = value;
}


void lux::tree::Node::removeChild(Node *node){
	if (node->m_parent != this) return;

	auto res = std::find(m_children.begin(), m_children.end(), node);
	if (res != m_children.end())
	{
		m_children.erase(res);
		node->m_parent = nullptr;
	}
}

