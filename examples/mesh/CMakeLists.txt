project(lux_samples_mesh)

add_executable(lux_samples_mesh main.cpp)

target_link_libraries(lux_samples_mesh PRIVATE lux)
target_include_directories(lux_samples_mesh PRIVATE ${CMAKE_SOURCE_DIR}/src)

# move suzanne to build folder
file(COPY suzanne.obj DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/assets/)
