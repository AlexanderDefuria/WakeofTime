//
// Created by alexander on 09/07/19.
//

#include "graphic2D.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

void graphic2D::loadBufferData( char *imgfilename ) {

    std::string line;

    std::string filename(imgfilename);
    filename = filename.substr(0, filename.find_last_of('.'));
    filename += ".txt";

    this->file.open(filename, std::ifstream::in);

    int index = 0;
    bool vertex_complete = false;
    int vertex_end = 0;

    while ( getline (file,line) ) {

        double number;
        std::istringstream iss(line);
        iss >> number;

        if ( iss.str().empty() ) {
            vertex_complete = true;
            vertex_end = index;
        } else {

            if (!vertex_complete)
                vertex_buffer_data[index] = number;
            else
                g_uv_buffer_data[index - vertex_end] = number;

            index++;

        }
    }


    //abort();

    file.close();
}
