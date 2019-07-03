//
// Created by alexander on 02/07/19.
//

#ifndef WAKEOFTIMEENGINE_CONTROLS_H
#define WAKEOFTIMEENGINE_CONTROLS_H


#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

void computeMatricesFromInputs(GLFWwindow* window);
glm::mat4 getViewMatrix();
glm::mat4 getProjectionMatrix();


#endif //WAKEOFTIMEENGINE_CONTROLS_H