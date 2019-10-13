
cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 14)
project(Simulation)


set(OpenGlLinkers -lglut -lGLU -lGL -lglfw -lGLEW)


################################################
include_directories(Simulation_src)
add_subdirectory(Simulation_src)
add_subdirectory(Simulation_test)

#################################################