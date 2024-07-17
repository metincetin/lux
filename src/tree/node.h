#ifndef NODE_H
#define NODE_H

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <vector>

#include "../memory.h"

namespace lux::tree {
class Node {
  public:
    Node() {
        m_scale = glm::vec3(1, 1, 1);
        generateLocalMatrix();

        memory::allocate(this);
    }
    Node(glm::vec3 position) {
        m_position = position;
        m_scale = glm::vec3(1, 1, 1);
        generateLocalMatrix();

        memory::allocate(this);
    }
    Node(glm::vec3 position, glm::vec3 eulerAngles) {
        m_position = position;
        m_rotation = glm::quat(eulerAngles);
        m_scale = glm::vec3(1, 1, 1);
        generateLocalMatrix();

        memory::allocate(this);
    }
    Node(glm::vec3 position, glm::vec3 eulerAngles, glm::vec3 scale) {
        m_position = position;
        m_rotation = glm::quat(eulerAngles);
        m_scale = scale;
        generateLocalMatrix();

        memory::allocate(this);
    }

    ~Node() { memory::free(sizeof(*this)); }
    void addChild(Node *node);
    void removeChild(Node *node);

    void setPosition(glm::vec3);
    void setScale(glm::vec3);
    void setEuler(glm::vec3);
    void setRotation(glm::quat);

    glm::vec3 getPosition() const { return m_position; }
    glm::vec3 getScale() const { return m_scale; }
    glm::quat getRotation() const { return m_rotation; }

  private:
    std::vector<Node *> m_children;
    Node *m_parent;

    glm::vec3 m_position;
    glm::quat m_rotation;
    glm::vec3 m_scale;

    glm::mat4x4 m_localToWorld;
    glm::mat4x4 m_worldMatrix;


	void setWorldMatrix(glm::mat4x4);
	void updateChildrenWorldMatrices();

    void generateLocalMatrix();
};
} // namespace lux::tree
#endif
