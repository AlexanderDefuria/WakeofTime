#include "renderModule.h"
#include <iostream>
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>
#include <SOIL/SOIL.h>
#include <chrono>
#include "Graphics/controls.h"
#include "Graphics/shader.h"


void renderModule::renderloop(){

    GLFWmonitor *primary = glfwGetPrimaryMonitor();
    GLFWwindow *window;

    // Initialize the library
    if (!glfwInit()) {
        std::cout << "Failed to initialize GLFW!\n";
        return;
    }

    // Create a windowed mode window and its OpenGL context
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
    window = glfwCreateWindow(1280, 720, "base", primary, NULL);
    if (!window) {
        glfwTerminate();

        std::cout << "Failed to create window using GLFW!\n";
        return;
    }

    int width, height;
    glfwGetWindowSize(window, &width, &height);
    std::cout << "Window: \t Width: ";
    std::cout << width;
    std::cout << "px\tHeight: ";
    std::cout << height;
    std::cout << "px\n";

    // Make the window's context current
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize OpenGL context" << std::endl;
        return;
    }

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    // Turquoise background
    glClearColor(0.064f, 0.224f, 0.208f, 0.0f);

    // Enable depth test
    glEnable(GL_LIGHT0);
    // Accept fragment if it closer to the camera than the former one
    glDepthFunc(GL_LESS);

    GLuint shaderID = LoadShaders( "../shader/vertex.glsl", "../shader/fragment.glsl" );
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glUseProgram(shaderID);

    // Get a handle for our "MVP" uniform
    GLuint MatrixID = glGetUniformLocation(shaderID, "MVP");


    int awidth, aheight;
    unsigned char* image =
            SOIL_load_image("../resources/images/bridge.bmp", &awidth, &aheight, 0, SOIL_LOAD_RGB);

    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);


    GLuint textureID;
    glGenTextures(1, &textureID);
    // "Bind" the newly created texture : all future texture functions will modify this texture
    glBindTexture(GL_TEXTURE_2D, textureID);


    // Give the image to OpenGL
    glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, awidth, aheight, 0, GL_BGR, GL_UNSIGNED_BYTE, image);

    // ... nice trilinear filtering ...
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    // ... which requires mipmaps. Generate them automatically.
    glGenerateMipmap(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_2D);


    GLuint Texture = textureID;
    // Get a handle for our "myTextureSampler" uniform
    GLuint TextureID  = glGetUniformLocation(shaderID, "myTextureSampler");

    // Our vertices. Tree consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    static GLfloat g_vertex_buffer_data[] = {
             1.0f, 1.0f, .0f, // Upper Right
             1.0f, -1.0f, 0.f, //
             -1.0f, -1.0f, .0f, // Bottom Left
            -1.0f, 1.0f, .0f,   // Upper Left
    };

    // Two UV coordinatesfor each vertex. They were created with Blender.
    static GLfloat g_uv_buffer_data[] = {
            1.0f, .0f,
            1.0f, 1.0f,
            .0f, 1.0f,
            .0f, .0f,
    };

    GLuint vertexbuffer;
    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STREAM_DRAW);


    GLuint uvbuffer;
    glGenBuffers(1, &uvbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_uv_buffer_data), g_uv_buffer_data, GL_STATIC_DRAW);


    glfwSwapInterval(1);

    do{
        auto start = std::chrono::high_resolution_clock::now();

        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Use our shader
        glUseProgram(shaderID);

        computeMatricesFromInputs(window);
        glm::mat4 ProjectionMatrix = getProjectionMatrix();
        glm::mat4 ViewMatrix = getViewMatrix();
        glm::mat4 ModelMatrix = glm::mat4(1.0);
        glm::mat4 MVP = ProjectionMatrix * ViewMatrix * ModelMatrix;


        // Send our transformation to the currently bound shader,
        // in the "MVP" uniform
        glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

        // Bind our texture in Texture Unit 0
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, Texture);
        // Set our "myTextureSampler" sampler to use Texture Unit 0
        glUniform1i(TextureID, 0);


        // 1rst attribute buffer : vertices
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        glVertexAttribPointer(
                0,                  // attribute. No particular reason for 0, but must match the layout in the shader.
                3,                  // size
                GL_FLOAT,           // type
                GL_FALSE,           // normalized?
                0,                  // stride
                (void*)0            // array buffer offset
        );
        // 2nd attribute buffer : UVs
        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
        glVertexAttribPointer(
                1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
                2,                                // size : U+V => 2
                GL_FLOAT,                         // type
                GL_FALSE,                         // normalized?
                0,                                // stride
                (void*)0                          // array buffer offset
        );


        // Draw the square !
        glDrawArraysInstanced(GL_QUADS, 0, 4,1); // 12*3 indices starting at 0 -> 12 triangles

        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);


        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
       // std::cout << "Time taken by function: "
         //         << duration.count() << " microseconds" << std::endl;


        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();

        glNamedBufferSubData(vertexbuffer, 0, sizeof(g_vertex_buffer_data), g_vertex_buffer_data);

    } // Check if the ESC key was pressed or the window was closed
    while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
           glfwWindowShouldClose(window) == 0 );


    // Cleanup VBO and shader
    glDeleteBuffers(1, &vertexbuffer);
    glDeleteBuffers(1, &uvbuffer);
    glDeleteProgram(shaderID);
    glDeleteTextures(1, &Texture);
    glDeleteVertexArrays(1, &VertexArrayID);

    glfwTerminate();

    exit(EXIT_SUCCESS);

}

