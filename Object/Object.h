//
// Created by biomfire on 10/12/19.
//

#ifndef SIMULATION_OBJECT_H
#define SIMULATION_OBJECT_H

#include <vector>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <string>
#include <GL/glew.h>
#include <fstream>
#include "LoadObject/ObjFileParser.h"

class Object{
public:
    GLuint  vao;
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec2> uv;
    std::vector<glm::vec3> normals;

public:
    explicit Object(std::string path){
        ObjFileParser praser (path);
        vertices = praser.getVertices();
        uv = praser.getUv();
        normals = praser.getNormals();
        vao = 0;
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);
        GLuint vbo;
        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), vertices.data(), GL_STATIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(
                0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
                3,                  // size
                GL_FLOAT,           // type
                GL_FALSE,           // normalized?
                0,                  // stride
                nullptr          // array buffer offset
        );
    }
    void draw(){
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0,vertices.size());
    }

};


#endif //SIMULATION_OBJECT_H
