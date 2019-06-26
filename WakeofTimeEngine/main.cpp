#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <chrono>  // for high_resolution_clock
#include "renderer.h"

int main( void )
{
    renderer* render = new renderer;
    render->renderloop();
    delete render;
}