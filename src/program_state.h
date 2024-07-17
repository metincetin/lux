#ifndef PROGRAM_STATE_H
#define PROGRAM_STATE_H
#include "material_definition.h"

namespace lux {
	enum CullFace { Front, Back, Both };
	struct ProgramState {
		CullFace cullFace;
		bool depthWrite;
		unsigned int glProgram;
	};
} // namespace lux
#endif
