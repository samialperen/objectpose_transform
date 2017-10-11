cmake_minimum_required(VERSION 2.8.3)
project(objectpose_transform)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  geometry_msgs
  tf
)

catkin_package(
  #INCLUDE_DIRS include
  LIBRARIES humanpose_transform
  CATKIN_DEPENDS roscpp rospy std_msgs tf geometry_msgs
  DEPENDS system_lib
)
###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if you package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
#catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES compute_cdist
#  CATKIN_DEPENDS roscpp visualization_msgs robot_model_helper compute_cdist
#  DEPENDS assimp Eigen mlpack
#)

include_directories(${catkin_INCLUDE_DIRS})

add_executable(objectpose_transform src/objectpose_transform.cpp)
add_executable(platetransform src/platetransform.cpp)
add_executable(forktransform src/forktransform.cpp)
target_link_libraries(objectpose_transform ${catkin_LIBRARIES})
target_link_libraries(platetransform ${catkin_LIBRARIES})
target_link_libraries(forktransform ${catkin_LIBRARIES})
add_dependencies(objectpose_transform ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(platetransform ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(forktransform ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})






