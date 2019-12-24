#include <iostream>
#include <vector>
#include <glad/glad.h>
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
#include <glm/gtx/string_cast.hpp>

#include "Graphics/objloader.hpp"
#include "Graphics/texture.hpp"


void renderModule::setup() {

    primary = glfwGetPrimaryMonitor();

    // Initialize the library
    if (!glfwInit()) {
        std::cout << "Failed to initialize GLFW!\n";
        return;
    }



    // Create a windowed mode window and its OpenGL context
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

    window = glfwCreateWindow(1280, 720, "base", primary, nullptr);

    if (!window) {
        glfwTerminate();

        std::cout << "Failed to create window using GLFW!\n";

        return;
    }


    // Output information about the window
    glfwGetWindowSize(window, &width, &height);
    std::cout << "Window: \t Width: ";
    std::cout << width;
    std::cout << "px\tHeight: ";
    std::cout << height;
    std::cout << "px\n";


    // Make the window's context current
    glfwMakeContextCurrent(window);


    // Initialize GLAD
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize OpenGL context" << std::endl;
        return;
    }


    // Setup Input
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);            // Ensure we can capture the escape key being pressed below
    //glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);    // Hide the mouse and enable unlimited mouvement
    glfwPollEvents();
    //glfwSetCursorPos(window, renderModule::width/2, renderModule::width/2); // Set the mouse at the center of the screen

    // Set Swap Interval, 0 means no interval, 1 means in sync with monitor (VSync), 2 means double buffered
    glfwSwapInterval(0);

    // Turquoise background
    glClearColor(0.064f, 0.224f, 0.208f, 0.0f);


    // Enable depth
    glEnable(GL_LIGHT0);
    // Accept fragment if it closer to the camera than the former one
    glDepthFunc(GL_LESS);

    //Setup transparency for our PNG format
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_COLOR, GL_ONE);

    // Cull  Triangles which normal is not facing the camera
    glEnable(GL_CULL_FACE);


    shaderID = LoadShaders("../shader/vertex.glsl", "../shader/fragment.glsl");
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glUseProgram(shaderID);

    // Get a handle for our "MVP" uniform
    MatrixID = glGetUniformLocation(shaderID, "VP");



    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

    // "Bind" the newly created texture : all future texture functions will modify this texture
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);



    Texture = loadDDS("../resources/uvmap.DDS");


    TextureID = glGetUniformLocation(shaderID, "myTextureSampler");
    Texture = textureID;
    // Get a handle for our "myTextureSampler" uniform



    // Read our .obj file

    bool res = loadOBJ("../resources/cube.obj", vertices, uvs, normals);


    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);

    glGenBuffers(1, &uvbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
    glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), &uvs[0], GL_STATIC_DRAW);




    // Bind our texture in Texture Unit 0
    glActiveTexture(GL_TEXTURE0);
    // Set our "myTextureSampler" sampler to use Texture Unit 0
    glUniform1i(TextureID, 0);



}



int LastUsedParticle = 0;
// Finds a Particle in ParticlesContainer which isn't used yet.
// (i.e. life < 0);
int renderModule::FindUnusedTile(){

    for(int i=LastUsedParticle; i<MaxTiles; i++){
        if (!this->TilesContainer[i].used){
            LastUsedParticle = i;
            return i;
        }
    }

    for(int i=0; i<LastUsedParticle; i++){
        if (!this->TilesContainer[i].used){
            LastUsedParticle = i;
            return i;
        }
    }


    return 0; // All particles are taken, override the first one
}

void renderModule::SortParticles(){

    std::sort(&this->TilesContainer[0], &this->TilesContainer[MaxTiles]);

}


void renderModule::renderloop(){
    int totaltime = 0;
    int frames = 0;




    do{
        // TIMING START
        auto start = std::chrono::high_resolution_clock::now();

        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);




        computeMatricesFromInputs(window);
        glm::mat4 ProjectionMatrix = getProjectionMatrix();
        glm::mat4 ViewMatrix = getViewMatrix();
        glm::mat4 VP = ProjectionMatrix * ViewMatrix;





        // Send our transformation to the currently bound shader,
        // in the "MVP" uniform
        glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &VP[0][0]);



        // 1rst attribute buffer : vertices
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        glVertexAttribPointer(
                0,                         // attribute. No particular reason for 0, but must match the layout in the shader.
                3,                         // size : x + y + z
                GL_FLOAT,                  // type
                GL_FALSE,                  // normalized?
                0,                         // stride
                (void*) nullptr            // array buffer offset
        );

        // 2nd attribute buffer : UVs
        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
        glVertexAttribPointer(
                1,                         // attribute. No particular reason for 1, but must match the layout in the shader.
                2,                         // size : U+V => 2
                GL_FLOAT,                  // type
                GL_FALSE,                  // normalized?
                0,                         // stride
                (void*) nullptr            // array buffer offset
        );





        // These functions are specific to glDrawArrays*Instanced*.
        // The first parameter is the attribute buffer we're talking about.
        // The second parameter is the "rate at which generic vertex attributes advance when rendering multiple instances"
        // http://www.opengl.org/sdk/docs/man/xhtml/glVertexAttribDivisor.xml
        //glVertexAttribDivisor(0, 0); // particles vertices : always reuse the same 4 vertices -> 0
        //glVertexAttribDivisor(1, 1); // positions : one per quad (its center)                 -> 1

        // Draw the particules !
        // This draws many times a small triangle_strip (which looks like a quad).
        // This is equivalent to :
        // for(i in ParticlesCount) : glDrawArrays(GL_TRIANGLE_STRIP, 0, 4),
        // but faster.
        glDrawArrays(GL_TRIANGLES, 0, vertices.size());

        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
        glDisableVertexAttribArray(2);




        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
        frames++;
        totaltime += frametime;

        // TIMING END
        auto stop = std::chrono::high_resolution_clock::now();
        frametime = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
        //std::cout << "Time taken by function: "
        //          << frametime << " microseconds" << ParticlesCount<< std::endl;

    } // Check if the ESC key was pressed or the window was closed
    while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
           glfwWindowShouldClose(window) == 0 );

    std::cout << "\n\nAverage Time: " << totaltime/frames << " microseconds" << std::endl;




}

renderModule::~renderModule() {
    // Cleanup VBO and shader
    glDeleteBuffers(1, &vertexbuffer);
    glDeleteBuffers(1, &uvbuffer);
    glDeleteProgram(shaderID);
    glDeleteTextures(1, &Texture);
    glDeleteVertexArrays(1, &VertexArrayID);

    glfwTerminate();
    exit(EXIT_SUCCESS);
}

