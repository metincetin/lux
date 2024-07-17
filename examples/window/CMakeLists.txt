project(lux_samples_window)

add_executable(lux_samples_window main.cpp)

target_link_libraries(lux_samples_window PRIVATE lux)
target_include_directories(lux_samples_window PRIVATE ${CMAKE_SOURCE_DIR}/src)