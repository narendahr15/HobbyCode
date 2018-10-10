cmake_minimum_required(VERSION 2.8.3)

project(first_package)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  sensor_msgs
  std_srvs
)

catkin_package()

include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(first_package src/helloWorld.cpp)
add_dependencies(first_package ${catkin_EXPORTED_TARGETS})
target_link_libraries(first_package ${catkin_LIBRARIES})

install(DIRECTORY include/${PROJECT_NAME}/
        DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
        FILES_MATCHING PATTERN "*.h"
        PATTERN ".svn" EXCLUDE
)


