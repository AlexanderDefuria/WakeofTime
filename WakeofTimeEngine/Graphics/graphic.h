//
// Created by alexander on 08/07/19.
//
#ifndef WAKEOFTIMEENGINE_GRAPHIC_H
#define WAKEOFTIMEENGINE_GRAPHIC_H

#include <SOIL/SOIL.h>
#include <glad/glad.h>
#include <glm/vec3.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <glm/vec4.hpp>

using namespace std;

class graphic {
public:
    void load(const char *imgfilename){
        //std::cout << imgfilename << std::endl;
        image = SOIL_load_image(imgfilename, &width, &height, 0, SOIL_LOAD_RGBA);
        loadBufferData((char*)imgfilename);
        pos = glm::vec3(0,0,0);
        used = true;
    }

    void position(int x, int y, int z){
        pos = glm::vec3(x,y,z);
    }
    glm::vec3 position(){
        return pos;
    }

    void clear(){
        used = false;
    }

    void onClick();

    bool load_obj(const char* filename);



    unsigned char* image;
    int width{};
    int height{};
    bool visibility = true;
    bool used = false;

    float cameradistance; // *Squared* distance to the camera. if dead : -1.0f

    bool operator<(const graphic& that) const {
        // Sort in reverse order : far particles drawn first.
        return this->cameradistance > that.cameradistance;
    }


    glm::vec3 pos;
    GLfloat vertex_buffer_data[30];
    GLfloat g_uv_buffer_data[30];
    std::ifstream afile;


private:
    void loadBufferData( char *imgfilename);


};


#endif //WAKEOFTIMEENGINE_GRAPHIC_H
