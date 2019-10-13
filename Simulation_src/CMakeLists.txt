cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 14)
add_executable(
        Simulation
        main.cpp
        shader.cpp
        shader.hpp
        Object/Object.cpp
        Object/Object.h
        LoadResources/LoadObject/ObjFileParser.cpp
        LoadResources/LoadObject/ObjFileParser.h
        Controls.cpp
        Controls.h
        LoadResources/LoadTexture/DdsFileParser.cpp
        LoadResources/LoadTexture/DdsFileParser.h
        LoadResources/FileManager.cpp
        LoadResources/FileManager.h)
target_link_libraries(Simulation ${OpenGlLinkers})