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

class Object {
    GLuint vao;
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec2> uv;
    std::vector<glm::vec3> normals;

public:
    explicit Object(std::string path);

    void draw();

};


#endif //SIMULATION_OBJECT_H
