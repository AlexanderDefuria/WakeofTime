//
// Created by alexander on 02/07/19.
//

#include "controls.h"
// Include GLFW
#include <GLFW/glfw3.h>

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

using namespace glm;


glm::mat4 ViewMatrix;
glm::mat4 ProjectionMatrix;

glm::mat4 getViewMatrix(){
    return ViewMatrix;
}
glm::mat4 getProjectionMatrix(){
    return ProjectionMatrix;
}


// Initial horizontal angle : toward -Z
float horizontalAngle = 3.14f;
// Initial vertical angle : none
float verticalAngle = 0.0f;
// Initial Field of View
float initialFoV = 40.0f;

float speed = 0.025f; // 3 units / second
float mouseSpeed = 0.005f;



glm::vec3 focus = glm::vec3( 0.0f, 0.0f, 0.0f );
glm::vec3 cameraOffset = glm::vec3( 0.0f, -3.5f, 2.0f );


void computeMatricesFromInputs(GLFWwindow* window){

    int width, height;
    glfwGetWindowSize(window, &width, &height);

    // Compute time difference between current and last frame

    glm::vec3 right = glm::vec3( 1.0f, 0.0f, 0.0f );
    glm::vec3 up    = glm::vec3( 0.0f, 1.0f, 0.0f );

    // Move forward
    if (glfwGetKey( window, GLFW_KEY_W ) == GLFW_PRESS){
        focus -= up * speed;
    }
    // Move backward
    if (glfwGetKey( window, GLFW_KEY_S ) == GLFW_PRESS){
        focus += up * speed;
    }
    // Strafe right
    if (glfwGetKey( window, GLFW_KEY_A ) == GLFW_PRESS){
        focus += right * speed;
    }
    // Strafe left
    if (glfwGetKey( window, GLFW_KEY_D ) == GLFW_PRESS){
        focus -= right * speed;
    }

    float FoV = initialFoV;// - 5 * glfwGetMouseWheel(); // Now GLFW 3 requires setting up a callback for this. It's a bit too complicated for this beginner's tutorial, so it's disabled instead.

    // Projection matrix : 45� Field of View, 16:9 ratio, display range : 0.1 unit <-> 100 units

    ProjectionMatrix = glm::perspective(glm::radians(FoV),  (float) width / (float)height, 1.0f, 100.0f);
    // Camera matrix
    ViewMatrix       = glm::lookAt(
            focus + cameraOffset, // Camera is at (x,y,z), in World Space
            focus, // and looks at the origin
            glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)           // Head is up (set to 0,-1,0 to look upside-down)
    );

}