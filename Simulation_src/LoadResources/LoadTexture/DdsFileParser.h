//
// Created by biomfire on 10/12/19.
//

#ifndef SIMULATION_DDSFILEPARSER_H
#define SIMULATION_DDSFILEPARSER_H


#include <GL/glew.h>
#include <string>
#include <fstream>
#include <algorithm>

#define FOURCC_DXT1 0x31545844 // Equivalent to "DXT1" in ASCII
#define FOURCC_DXT3 0x33545844 // Equivalent to "DXT3" in ASCII
#define FOURCC_DXT5 0x35545844 // Equivalent to "DXT5" in ASCII
class DdsFileParser {
    GLuint textureID;
//    GLuint loadDDS(std::string path){
//        std::ifstream file = openFile(path);
//        unsigned char header[124];
//        /* verify the type of file */
//        vertifyFile(file);
//        fread(&header, 124, 1, fp);
//
//        unsigned int height      = *(unsigned int*)&(header[8 ]);
//        unsigned int width         = *(unsigned int*)&(header[12]);
//        unsigned int linearSize     = *(unsigned int*)&(header[16]);
//        unsigned int mipMapCount = *(unsigned int*)&(header[24]);
//        unsigned int fourCC      = *(unsigned int*)&(header[80]);
//        unsigned char * buffer;
//        unsigned int bufsize;
//        /* how big is it going to be including all mipmaps? */
//        bufsize = mipMapCount > 1 ? linearSize * 2 : linearSize;
//        buffer = (unsigned char*)malloc(bufsize * sizeof(unsigned char));
//        fread(buffer, 1, bufsize, fp);
//        /* close the file pointer */
//        fclose(fp);
//        unsigned int components  = (fourCC == FOURCC_DXT1) ? 3 : 4;
//        unsigned int format;
//        switch(fourCC)
//        {
//            case FOURCC_DXT1:
//                format = GL_COMPRESSED_RGBA_S3TC_DXT1_EXT;
//                break;
//            case FOURCC_DXT3:
//                format = GL_COMPRESSED_RGBA_S3TC_DXT3_EXT;
//                break;
//            case FOURCC_DXT5:
//                format = GL_COMPRESSED_RGBA_S3TC_DXT5_EXT;
//                break;
//            default:
//                free(buffer);
//                return 0;
//        }
//        // Create one OpenGL texture
//        GLuint textureID;
//        glGenTextures(1, &textureID);
//
//        // "Bind" the newly created texture : all future texture functions will modify this texture
//        glBindTexture(GL_TEXTURE_2D, textureID);
//        unsigned int blockSize = (format == GL_COMPRESSED_RGBA_S3TC_DXT1_EXT) ? 8 : 16;
//        unsigned int offset = 0;
//
//        /* load the mipmaps */
//        for (unsigned int level = 0; level < mipMapCount && (width || height); ++level)
//        {
//            unsigned int size = ((width+3)/4)*((height+3)/4)*blockSize;
//            glCompressedTexImage2D(GL_TEXTURE_2D, level, format, width, height,
//                                   0, size, buffer + offset);
//
//            offset += size;
//            width  /= 2;
//            height /= 2;
//        }
//        free(buffer);
//
//        return textureID;
//    }
//
    void vertifyFile(const std::ifstream &file) const {
        std::string str;

        std::copy_n(std::istreambuf_iterator<char>(file.rdbuf()),
                    4, std::back_inserter(str));
        if(str == "DDS ") {
            throw "Rossz file tipus";
        }
    }
};


#endif //SIMULATION_DDSFILEPARSER_H
