#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <GL/glew.h>

#include <GLFW/glfw3.h>
#include <iostream>

#include <IL/devil_cpp_wrapper.hpp>


GLuint loadDDS(const char *imagepath){
    ilInit();
    iluInit();
    ilutRenderer(ILUT_OPENGL);

    ILuint texid;
    ILboolean success;



    ilGenImages(1, &texid);
    ilBindImage(texid);
    success = ilLoadImage(imagepath);

    if(success) success = ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);
    if(success) std::cout << "Image Loaded Successfully" << std::endl;


    GLuint image;
    glGenTextures(1, &image); /* Texture name generation */
    glBindTexture(GL_TEXTURE_2D, image); /* Binding of texture name */
    glPixelStorei(GL_UNPACK_ALIGNMENT,1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); /* We will use linear interpolation for magnification filter */
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); /* We will use linear interpolation for minifying filter */
    glTexImage2D(GL_TEXTURE_2D, 0, ilGetInteger(IL_IMAGE_BPP), ilGetInteger(IL_IMAGE_WIDTH),
                 ilGetInteger(IL_IMAGE_HEIGHT), 0, ilGetInteger(IL_IMAGE_FORMAT), GL_UNSIGNED_BYTE,
                 ilGetData()); /* Texture specification */


    GLuint textureID;

	return image;


}