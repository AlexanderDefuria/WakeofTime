//
// Created by alexander on 14/06/19.
//

#ifndef WAKEOFTIMEENGINE_RENDERMODULE_H
#define WAKEOFTIMEENGINE_RENDERMODULE_H


#include <GLFW/glfw3.h>

class renderModule {
public:
    ~renderModule();
    void renderloop();
    void setup();

    GLFWmonitor *primary;
    GLFWwindow *window;
    int width, height;


    static int frametime;

private:

    GLuint shaderID;
    GLuint MatrixID;

    GLuint VertexArrayID;
    GLuint textureID;

    GLuint Texture;
    GLuint TextureID;

    GLuint uvbuffer;
    GLuint vertexbuffer;

};



#endif //WAKEOFTIMEENGINE_RENDERMODULE_H
