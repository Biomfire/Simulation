//
// Created by biomfire on 10/13/19.
//

#ifndef SIMULATION_FILEMANAGER_H
#define SIMULATION_FILEMANAGER_H


#include <fstream>

class FileManager {
public:
    static std::ifstream openFile(const std::string &path){
        std::ifstream file(path);
        if (!file.is_open()) {
            throw "Nem sikertül a textúrát megnyitni";
        }
        return file;
    }

private:
    FileManager();
};


#endif //SIMULATION_FILEMANAGER_H
