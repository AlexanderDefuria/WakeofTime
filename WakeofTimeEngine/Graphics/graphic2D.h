//
// Created by alexander on 08/07/19.
//

#ifndef WAKEOFTIMEENGINE_GRAPHIC2D_H
#define WAKEOFTIMEENGINE_GRAPHIC2D_H
#include <SOIL/SOIL.h>
#include <glad/glad.h>
#include <glm/vec3.hpp>
#include <iostream>
#include <fstream>

class graphic2D {
public:
    void load(const char *imgfilename){
        //std::cout << imgfilename << std::endl;
        image = SOIL_load_image(imgfilename, &width, &height, 0, SOIL_LOAD_RGBA);
        loadBufferData((char*)imgfilename);
        offset = glm::vec3(0,0,0);
    }


    unsigned char* image;
    int width{};
    int height{};

    glm::vec3 offset;
    GLfloat vertex_buffer_data[30];
    GLfloat g_uv_buffer_data[20];
    std::ifstream file;


private:
    void loadBufferData( char *imgfilename);


};


#endif //WAKEOFTIMEENGINE_GRAPHIC2D_H
