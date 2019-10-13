//
// Created by biomfire on 10/12/19.
//

#include <LoadResources/FileManager.h>
#include "Object.h"

Object::Object(std::string path) {
    std::ifstream file = FileManager::openFile(path);
    ObjFileParser praser(file);
    vertices = praser.getVertices();
    uv = praser.getUv();
    normals = praser.getNormals();
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    GLuint vbo[3];
    glGenBuffers(3, vbo);
    loadCoordsIntoBuffer(vbo);
    loadUvIntoBuffer(vbo);
    loadNormalsIntoBuffer(vbo);
}

void Object::loadCoordsIntoBuffer(const GLuint *vbo) const {
    glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
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

void Object::loadUvIntoBuffer(const GLuint *vbo) const {
    glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
    glBufferData(GL_ARRAY_BUFFER, uv.size() * sizeof(glm::vec2), uv.data(), GL_STATIC_DRAW);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(
            1,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
            2,                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized?
            0,                  // stride
            nullptr          // array buffer offset
    );
}

void Object::loadNormalsIntoBuffer(const GLuint *vbo) const {
    glBindBuffer(GL_ARRAY_BUFFER, vbo[2]);
    glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(glm::vec3), normals.data(), GL_STATIC_DRAW);
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(
            2,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
            3,                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized?
            0,                  // stride
            nullptr          // array buffer offset
    );
}

void Object::draw() {
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, vertices.size());
}