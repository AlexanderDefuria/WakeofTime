#include <GL/glew.h>
#include <GLFW/glfw3.h>


#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <chrono>  // for high_resolution_clock
#include "test.h"
#include "renderer.h"
#include "ObjectPool.h"


void testnew() {
    auto start = std::chrono::high_resolution_clock::now();
    for (int x = 0; x < 10000; x++) {
        renderer* y = new renderer;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> fp_ms = end - start;
    std::cout << "new took " << fp_ms.count() << " ms " << std::endl;
}



int main( void )
{

    renderer* render[10] = new renderer;
    testnew();

}