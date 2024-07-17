cmake_minimum_required(VERSION 3.8)
project(lux)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


set(SOURCE
        external/glad/src/glad.c
        src/renderer.h
        src/renderer.cpp
        src/memory.cpp
        src/memory.h
        src/render_pass.h
        src/render_pass_queue.h
        src/render_pass_queue.cpp

        src/render_state.h
        src/program_state.h

        src/vertex_buffer.h
        src/vertex_buffer.cpp

        src/index_buffer.h
        src/index_buffer.cpp

        src/tree/node.h
        src/tree/node.cpp

		src/material_definition.h
		src/shader.h

		src/rendering_implementation.h

		src/implementations/opengl_implementation.h
		src/implementations/opengl_implementation.cpp

		src/data_types.hpp
		src/lux.h
		src/vertex_structure.h
)

find_package(glm REQUIRED)

include_directories(external/glad/include/)

add_library(lux SHARED ${SOURCE})

target_link_libraries(lux glfw glm::glm)

add_subdirectory(examples)
