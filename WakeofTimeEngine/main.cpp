#include <GL/glew.h>
#include <GLFW/glfw3.h>


#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <chrono>  // for high_resolution_clock
#include "renderer.h"




int main( void )
{
    renderer* render = new renderer;
    std::cout << sizeof(render);
    render->renderloop();
    delete render;
}