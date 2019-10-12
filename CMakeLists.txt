
cmake_minimum_required(VERSION 3.15) # common to every CLion project
set(CMAKE_CXX_STANDARD 14)
project(Simulation) # project name


set(OpenGlLinkers -lglut -lGLU -lGL -lglfw -lGLEW) # setting all the Glut libraries as one variable.


################################################

add_executable(Simulation main.cpp shader.cpp shader.hpp) #common to all clion project
target_link_libraries(Simulation ${OpenGlLinkers}) # linking opengl libraries to the project

#################################################