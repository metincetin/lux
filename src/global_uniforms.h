#ifndef GLOBAL_UNIFORMS_H
#define GLOBAL_UNIFORMS_H

#include "data_types.hpp"
#include <glm/glm.hpp>
#include <map>
#include <vector>

class GlobalUniforms{
	public:
		static void setFloat(const char * name, float value){
			m_floatValues[name] = value;
		}
		static void setVec2(const char * name, glm::vec2);
		static void setVec3(const char * name, glm::vec3);
		static void setVec4(const char * name, glm::vec4);
		static void setInt(const char * name, int);
		static void setColor(const char * name, lux::Color);

	private:
		static std::map<const char*, float> m_floatValues;
		static std::map<const char*, int> m_intValues;
		static std::map<const char*, glm::vec2> m_vec2Values;
		static std::map<const char*, glm::vec3> m_vec3Values;
		static std::map<const char*, glm::vec4> m_vec4Values;
};

#endif
