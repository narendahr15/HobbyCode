cmake_minimum_required(VERSION 2.8.9)

project(hello_gl)
add_executable(hello_gl main.cpp)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} )
target_link_libraries(hello_gl ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
