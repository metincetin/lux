project(lux_samples_helloworld)

add_executable(lux_samples_helloworld main.cpp)
target_link_libraries(lux_samples_helloworld PRIVATE lux glfw)
target_include_directories(lux_samples_helloworld PRIVATE ${CMAKE_SOURCE_DIR}/src)