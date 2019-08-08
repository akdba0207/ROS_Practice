cmake_minimum_required(VERSION 2.8.3)
project(begineer_tutorials)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
)

## Generate messages in the 'msg' folder
add_message_files(FILES 
msgTutorial.msg
)

## Generate services in the 'srv' folder
add_service_files(
  FILES
  srvTutorial.srv
)

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

## Generate added messages and services with any dependencies listed here
generate_messages(
  DEPENDENCIES
  std_msgs
)

################################################
## Declare ROS dynamic reconfigure parameters ##
################################################

## To declare and build dynamic reconfigure parameters within this
## package, follow these steps:
## * In the file package.xml:
##   * add a build_depend and a exec_depend tag for "dynamic_reconfigure"
## * In this file (CMakeLists.txt):
##   * add "dynamic_reconfigure" to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * uncomment the "generate_dynamic_reconfigure_options" section below
##     and list every .cfg file to be processed

## Generate dynamic reconfigure parameters in the 'cfg' folder
# generate_dynamic_reconfigure_options(
#   cfg/DynReconf1.cfg
#   cfg/DynReconf2.cfg
# )

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if your package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
 INCLUDE_DIRS include
 #LIBRARIES begineer_tutorials
 #CATKIN_DEPENDS roscpp rospy std_msgs message_generation
 #DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
include
  ${catkin_INCLUDE_DIRS}
)


## Declare a C++ executable
## With catkin_make all packages are built within a single CMake context
## The recommended prefix ensures that target names across packages don't collide
add_executable(${PROJECT_NAME}_pub src/publisher.cpp)
target_link_libraries(${PROJECT_NAME}_pub
  ${catkin_LIBRARIES}
)
add_dependencies(${PROJECT_NAME}_pub begineer_tutorials_generate_messages_cpp)

add_executable(${PROJECT_NAME}_sub src/subscriber.cpp)
target_link_libraries(${PROJECT_NAME}_sub
  ${catkin_LIBRARIES}
)
add_dependencies(${PROJECT_NAME}_sub begineer_tutorials_generate_messages_cpp)

add_executable(${PROJECT_NAME}_server src/server.cpp)
target_link_libraries(${PROJECT_NAME}_server
  ${catkin_LIBRARIES}
)
add_dependencies(${PROJECT_NAME}_server begineer_tutorials_generate_messages_cpp)

add_executable(${PROJECT_NAME}_client src/client.cpp)
target_link_libraries(${PROJECT_NAME}_client
  ${catkin_LIBRARIES}
)
add_dependencies(${PROJECT_NAME}_client begineer_tutorials_generate_messages_cpp)
