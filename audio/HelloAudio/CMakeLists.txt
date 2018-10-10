
cmake_minimum_required(VERSION 2.8.1)

project(HelloAudio)
add_executable(HelloAudio main.cpp)

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

target_link_libraries(HelloAudio
    sndfile
)
  



