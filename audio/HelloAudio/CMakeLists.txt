cmake_minimum_required(VERSION 3.0.2)

project(HelloAudio)

set(CMAKE_CXX_FLAGS "-std=c++11")

# Include dir
find_path(LIBSNDFILE_INCLUDE_DIR
	NAMES 
      sndfile.h
	PATHS 
      /usr/include
      /usr/local/include
      /opt/local/include
)

#find the packages
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

# Library
find_library(LIBSNDFILE_LIBRARY
	NAMES 
      sndfile libsndfile-1
	PATHS 
      ${LIBSNDFILE_PKGCONF_LIBRARY_DIRS}
      /usr/lib 
      /usr/local/lib
      /opt/local/lib
)

include_directories(HelloAudio 
      ${CMAKE_CURRENT_SOURCE_DIR}/include/
      ${OPENGL_INCLUDE_DIRS} 
      ${GLUT_INCLUDE_DIRS}
)

set(LIBSNDFILE_INCLUDE_DIR ${LIBSNDFILE_INCLUDE_DIR})
set(LIBSNDFILE_LIBRARY ${LIBSNDFILE_LIBRARY})

if(LIBSNDFILE_INCLUDE_DIR AND LIBSNDFILE_LIBRARY)
  set(LIBSNDFILE_FOUND TRUE)
endif(LIBSNDFILE_INCLUDE_DIR AND LIBSNDFILE_LIBRARY)

if(LIBSNDFILE_FOUND)
  message(STATUS "Found LibSND : ${LIBSNDFILE_INCLUDE_DIR}")
else(LIBSNDFILE_FOUND)
  message(STATUS "LibSND not found")
endif(LIBSNDFILE_FOUND)

# Local header files here ONLY
SET(TARGET_H
    ../include/AudioHandler.h  
    ../include/GuiHandler.h 
   )

# Local source files here
SET(TARGET_SRC
      ../src/AudioHandler.cpp 
      ../src/GuiHandler.cpp
      ../src/main.cpp 
    )

add_executable(HelloAudio ${TARGET_H} ${TARGET_SRC})      


target_link_libraries(HelloAudio
    sndfile
    ${OPENGL_LIBRARIES} 
    ${GLUT_LIBRARY}

)
  



