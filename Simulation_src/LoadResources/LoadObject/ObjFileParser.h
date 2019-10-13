//
// Created by biomfire on 10/12/19.
//

#ifndef SIMULATION_OBJFILEPARSER_H
#define SIMULATION_OBJFILEPARSER_H


#include <vector>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <string>
#include <GL/glew.h>
#include <fstream>
#include <sstream>
#include <istream>
class ObjFileParser {
    std::vector<unsigned int> vertexIndices, uvIndices, normalIndices;
    std::vector<glm::vec3> temp_vertices;
    std::vector<glm::vec3> temp_normals;
    std::vector<glm::vec2> temp_uvs;
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec2> uvs;
    std::vector<glm::vec3> normals;

    void parseVertex(std::stringstream &line);

    void parseUv(std::stringstream &line);

    void parseNormal(std::stringstream &line);

    void parseFaces(std::stringstream &file);

    std::vector<std::string> split(std::string &inputstring, char c);

    void organizeVertices();

    void parseVertices(std::istream &file);

public:
    explicit ObjFileParser(std::istream &file);

    void ParseObjFile(std::istream &file);

    const std::vector<glm::vec3> &getVertices() const;

    const std::vector<glm::vec2> &getUv() const;

    const std::vector<glm::vec3> &getNormals() const;

};


#endif //SIMULATION_OBJFILEPARSER_H
