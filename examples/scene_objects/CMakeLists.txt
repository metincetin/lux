project(lux_samples_scene)

add_executable(lux_samples_scene main.cpp)

target_link_libraries(lux_samples_scene PRIVATE lux)
target_include_directories(lux_samples_scene PRIVATE ${CMAKE_SOURCE_DIR}/src)
