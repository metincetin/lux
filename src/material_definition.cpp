#include "material_definition.h"
#include "glad/glad.h"
#include "rendering_implementation.h"

void lux::MaterialDefinition::setFloat(const char * name, float value){
	auto uniformLocation = glGetUniformLocation(m_program, name);
	glUniform1f(uniformLocation, value);
}

void lux::MaterialDefinition::setInt(const char * name, int value){
	auto uniformLocation = glGetUniformLocation(m_program, name);
	glUniform1i(uniformLocation, value);
}

void lux::MaterialDefinition::setVec2(const char * name, glm::vec2 value){
	auto uniformLocation = glGetUniformLocation(m_program, name);
	glUniform2f(uniformLocation, value.x, value.y);
}

void lux::MaterialDefinition::setVec3(const char * name, glm::vec3 value){
	auto uniformLocation = glGetUniformLocation(m_program, name);
	glUniform3f(uniformLocation, value.x, value.y, value.z);
}

void lux::MaterialDefinition::setVec4(const char * name, glm::vec4 value){
	auto uniformLocation = glGetUniformLocation(m_program, name);
	glUniform4f(uniformLocation, value.x, value.y, value.z, value.w);
}

void lux::MaterialDefinition::setColor(const char * name, Color color){
	auto uniformLocation = glGetUniformLocation(m_program, name);
	glUniform4f(uniformLocation, color.r, color.g, color.b, color.a);
}
