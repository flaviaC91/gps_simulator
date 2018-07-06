cmake_minimum_required(VERSION 2.8.3)
project(gps_simulator)

add_definitions(-std=c++11)

find_package(catkin_simple REQUIRED)
catkin_simple(ALL_DEPS_REQUIRED)

find_package(Eigen REQUIRED)
include_directories(${Eigen_INCLUDE_DIRS})

cs_add_library(gps_simulator src/gps_simulator.cpp)

cs_add_executable(gps_simulator_node src/gps_simulator_node.cpp)
target_link_libraries(gps_simulator_node  gps_simulator)

cs_install()
#cs_install_scripts()
cs_export()