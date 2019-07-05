#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <chrono>  // for high_resolution_clock
#include "renderModule.h"

int main( void )
{
    renderModule* render = new renderModule;
    render->renderloop();
    delete render;
}