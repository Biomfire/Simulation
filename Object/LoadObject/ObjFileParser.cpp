//
// Created by biomfire on 10/12/19.
//


#include "ObjFileParser.h"

ObjFileParser::ObjFileParser(std::string &path) {
    ParseObjFile(path);
}

void ObjFileParser::ParseObjFile(std::string &path) {
    std::ifstream file = openFile(path);
    parseVericies(file);
    organizeVerticies();
}

void ObjFileParser::parseVericies(std::ifstream &file) {
    std::string line;
    while (std::getline(file, line)) {
        std::string lineHeader;
        std::stringstream iss(line);
        iss >> lineHeader;
        if (lineHeader == "v")
            parseVertex(iss);
        else if (lineHeader == "vt")
            parseUv(iss);
        else if (lineHeader == "vn")
            parseNormal(iss);
        else if (lineHeader == "f")
            parseFaces(iss);
        else {
            iss.clear();
            iss.str(std::string());
        }
    }
}

void ObjFileParser::organizeVerticies() {
    for (unsigned long int currentVertexIndex : vertexIndices) {
        unsigned int vertexIndex = currentVertexIndex;
        glm::vec3 vertex = temp_vertices[vertexIndex - 1];
        vertices.push_back(vertex);
    }
}

std::ifstream ObjFileParser::openFile(const std::string &path) const {
    std::ifstream file(path, std::ifstream::in);
    if (!file.is_open()) {
        throw "Can't open file";
    }
    return file;
}

void ObjFileParser::parseFaces(std::stringstream &line) {
    std::string coords;
    for (int i = 0; i < 3; i++) {
        line >> coords;
        split(coords, '/');
        vertexIndices.push_back(stoi(coords));
    }
}

void ObjFileParser::parseNormal(std::stringstream &line) {
    glm::vec3 normal;
    line >> normal.x >> normal.y >> normal.z;
    temp_normals.push_back(normal);
}

void ObjFileParser::parseUv(std::stringstream &line) {
    glm::vec2 uv;
    line >> uv.x >> uv.y;
    temp_uvs.push_back(uv);
}

void ObjFileParser::parseVertex(std::stringstream &line) {
    glm::vec3 vertex;
    line >> vertex.x >> vertex.y >> vertex.z;
    temp_vertices.push_back(vertex);
}

const std::vector<glm::vec3> &ObjFileParser::getVertices() const {
    return vertices;
}

const std::vector<glm::vec2> &ObjFileParser::getUv() const {
    return uv;
}

const std::vector<glm::vec3> &ObjFileParser::getNormals() const {
    return normals;
}

std::vector<std::string> ObjFileParser::split(std::string &inputstring, char c) {
    //TODO relocate this function
    std::stringstream inputstream(inputstring);
    std::string split;
    std::vector<std::string> returnvector;
    while (getline(inputstream, split, c))
        returnvector.push_back(split);
    return returnvector;
}
