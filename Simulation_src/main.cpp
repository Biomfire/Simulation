#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <vector>
#include "shader.hpp"
#include "Object/Object.h"
#include "Controls.h"

GLFWwindow *window;

void init() {
    if (!glfwInit())
        throw ("Failed to initialize GLFW\n");
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    window = glfwCreateWindow(1024, 768, "Simulation (CPP Project)", nullptr, nullptr);
    if (window == nullptr) {
        glfwTerminate();
        throw ("Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
    }
    glfwMakeContextCurrent(window); // Initialize GLEW
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
        throw "Failed to initialize GLEW\n";
    glfwPollEvents();
    glfwSetCursorPos(window, 1024 / 2, 768 / 2);
}


int main() {
    try {
        init();
    }
    catch (const char *e) {
        std::cerr << e;
    }
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    //glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glEnable(GL_CULL_FACE);
    GLuint programID = LoadShaders("/home/biomfire/Programing/Simulation/Simulation_src/SimpleVertexShader.vertexshader",
                                   "/home/biomfire/Programing/Simulation/Simulation_src/SimpleFragmentShader.fragmentshader");
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // NOLINT(hicpp-signed-bitwise)
    GLuint MatrixID = glGetUniformLocation(programID, "MVP");
    Object obj("/home/biomfire/Programing/Simulation/object.obj");
// Enable depth test
    glEnable(GL_DEPTH_TEST);
// Accept fragment if it closer to the camera than the former one
    glDepthFunc(GL_LESS);

    do {
        computeMatricesFromInputs();
        glm::mat4 ProjectionMatrix = getProjectionMatrix();
        glm::mat4 ViewMatrix = getViewMatrix();
        glm::mat4 ModelMatrix = glm::mat4(1.0);
        glm::mat4 MVP = ProjectionMatrix * ViewMatrix * ModelMatrix;
        glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
        glUseProgram(programID);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        obj.draw();
        glfwSwapBuffers(window);
        glfwPollEvents();
    } // Check if the ESC key was pressed or the window was closed
    while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
           glfwWindowShouldClose(window) == 0);
}