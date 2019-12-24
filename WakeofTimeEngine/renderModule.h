//
// Created by alexander on 14/06/19.
//

#ifndef WAKEOFTIMEENGINE_RENDERMODULE_H
#define WAKEOFTIMEENGINE_RENDERMODULE_H


#include "Graphics/graphic2D.h"
#include <GLFW/glfw3.h>
#include <map>
#include <vector>
#include <iostream>
#include <vector>
#include "glad.h"
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>
#include <SOIL/SOIL.h>
#include <chrono>
#include "Graphics/controls.h"
#include "Graphics/shader.h"
#include "Graphics/graphic2D.h"
#include <map>
#include <algorithm>
#include "renderModule.h"

#include "Graphics/objloader.hpp"




class renderModule {

    public:
        ~renderModule();

        void renderloop();

        void setup();

        GLFWmonitor *primary;
        GLFWwindow *window;
        int width, height;

        static int frametime;


        //
        static const GLuint MaxTiles = 1000;
        graphic2D TilesContainer[MaxTiles];



    private:
    // Setup map for different images TODO delete later
        std::map<std::string, const char *> files;

        GLuint shaderID;
        GLuint MatrixID;

        GLuint VertexArrayID;
        GLuint textureID;

        GLuint Texture;
        GLuint TextureID;

        GLuint uvbuffer;
        GLuint vertexbuffer;
        GLuint positionbuffer;

        std::vector<glm::vec3> vertices;
        std::vector<glm::vec2> uvs;
        std::vector<glm::vec3> normals; // Won't be used at the moment.

        int FindUnusedTile();
        void SortParticles();
};




#endif //WAKEOFTIMEENGINE_RENDERMODULE_H
