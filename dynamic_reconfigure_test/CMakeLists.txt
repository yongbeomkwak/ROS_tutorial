cmake_minimum_required(VERSION 2.8.3)
project(dynamic_reconfigure_test)

find_package(catkin REQUIRED COMPONENTS
     roscpp
     rospy
     dynamic_reconfigure
)

generate_dynamic_reconfigure_options(
     cfg/test.cfg
)

catkin_package(
     INCLUDE_DIRS include
     LIBRARIES dynamic_reconfigure_test
     CATKIN_DEPENDS roscpp rospy dynamic_reconfigure
     DEPENDS system_lib
)

include_directories(
     ${catkin_INCLUDE_DIRS}
)

add_executable(dynamic_reconfigure_test_exe src/dynamic_reconfigure_test.cpp)

target_link_libraries(dynamic_reconfigure_test_exe  ${catkin_LIBRARIES})

add_dependencies(dynamic_reconfigure_test_exe ${PROJECT_NAME}_gencfg)
