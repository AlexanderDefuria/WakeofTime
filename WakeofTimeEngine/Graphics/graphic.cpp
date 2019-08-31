//
// Created by alexander on 09/07/19.
//

#include "graphic.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <glm/ext/quaternion_geometric.hpp>
#include <glm/vec2.hpp>
#include <cstring>

void graphic::loadBufferData(char *imgfilename ) {

    std::string line;

    std::string filename(imgfilename);
    filename = filename.substr(0, filename.find_last_of('.'));
    filename += ".txt";

    this->afile.open(filename, std::ifstream::in);

    int index = 0;
    bool vertex_complete = false;
    int vertex_end = 0;

    while ( getline (afile,line) ) {

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



    afile.close();
}

void graphic::onClick() {
    // TODO Figure out clicking objects
}

bool graphic::load_obj(const char *filename) {
    printf("Loading OBJ file %s\n", filename);

    std::vector<unsigned int> vertexIndices, uvIndices, normalIndices;
    std::vector<glm::vec3> temp_vertices;
    std::vector<glm::vec2> temp_uvs;
    std::vector<glm::vec3> temp_normals;


    FILE * file = fopen(filename, "r");
    if( file == nullptr ){
        printf("Impossible to open the file ! Are you in the right path ? See Tutorial 1 for details\n");
        getchar();
        return false;
    }

    while( 1 ){

        char lineHeader[128];
        // read the first word of the line
        int res = fscanf(file, "%s", lineHeader);
        if (res == EOF)
            break; // EOF = End Of File. Quit the loop.

        // else : parse lineHeader

        if ( strcmp( lineHeader, "v" ) == 0 ){
            glm::vec3 vertex;
            fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z );
            temp_vertices.push_back(vertex);
        }else if ( strcmp( lineHeader, "vt" ) == 0 ){
            glm::vec2 uv;
            fscanf(file, "%f %f\n", &uv.x, &uv.y );
            uv.y = -uv.y; // Invert V coordinate since we will only use DDS texture, which are inverted. Remove if you want to use TGA or BMP loaders.
            temp_uvs.push_back(uv);
        }else if ( strcmp( lineHeader, "vn" ) == 0 ){
            glm::vec3 normal;
            fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z );
            temp_normals.push_back(normal);
        }else if ( strcmp( lineHeader, "f" ) == 0 ){
            std::string vertex1, vertex2, vertex3;
            unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
            int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2] );

            if (matches != 9){
                printf("File can't be read by our simple parser :-( Try exporting with other options\n");
                fclose(file);
                return false;
            }
            vertexIndices.push_back(vertexIndex[0]);
            vertexIndices.push_back(vertexIndex[1]);
            vertexIndices.push_back(vertexIndex[2]);
            uvIndices    .push_back(uvIndex[0]);
            uvIndices    .push_back(uvIndex[1]);
            uvIndices    .push_back(uvIndex[2]);
            normalIndices.push_back(normalIndex[0]);
            normalIndices.push_back(normalIndex[1]);
            normalIndices.push_back(normalIndex[2]);
        }else{
            // Probably a comment, eat up the rest of the line
            char stupidBuffer[1000];
            fgets(stupidBuffer, 1000, file);
        }

    }

    // For each vertex of each triangle
    for( unsigned int i=0; i<vertexIndices.size(); i++ ){

        // Get the indices of its attributes
        unsigned int vertexIndex = vertexIndices[i];
        unsigned int uvIndex = uvIndices[i];
        unsigned int normalIndex = normalIndices[i];

        // Get the attributes thanks to the index
        glm::vec3 vertex = temp_vertices[ vertexIndex-1 ];
        glm::vec2 uv = temp_uvs[ uvIndex-1 ];
        glm::vec3 normal = temp_normals[ normalIndex-1 ];

        // Put the attributes in buffers
        //out_vertices.push_back(vertex);
        //out_uvs     .push_back(uv);
        //out_normals .push_back(normal);

        vertex_buffer_data[i] = vertex.x;
        vertex_buffer_data[i+1] = vertex.y;
        vertex_buffer_data[i+2] = vertex.z;

        std::cout << vertex.x << " x" << std::endl;
        std::cout << vertex.y << " y" << std::endl;
        std::cout << vertex.z << " z" << std::endl;




    }
    fclose(file);
    return true;
}
