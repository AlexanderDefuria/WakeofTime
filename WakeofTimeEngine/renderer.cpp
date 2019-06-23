#include "renderer.h"
#include <iostream>
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


struct Point2D
{
    double m_x;
    double m_y;

    Point2D(int x, int y) : m_x(x), m_y(y)
    {

    }
};

void render()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);



    std::vector<Point2D> subject;
    subject.emplace_back(Point2D(-70, 0));
    subject.emplace_back(Point2D(-70, -70));
    subject.emplace_back(Point2D(0, -70));
    subject.emplace_back(Point2D(0, 0));

    std::vector<Point2D> clip;
    clip.emplace_back(Point2D(50, 0));
    clip.emplace_back(Point2D(50, 50));
    clip.emplace_back(Point2D(0, 50));
    clip.emplace_back(Point2D(0,0));


    std::vector<std::vector<Point2D> > vPolygon;
    vPolygon.push_back(subject);
    vPolygon.push_back(clip);


    int sizei = (int)vPolygon.size();
    for (int i = 0; i < sizei; ++i)
    {
        glLineWidth(2.0);
        glBegin(GL_POLYGON);

        auto polygon = vPolygon[i];
        int sizej = (int)polygon.size();
        for (int j = 0; j < sizej; ++j)
        {
            auto coordX = polygon[j].m_x;
            auto coordY = polygon[j].m_y;

            printf("%f\t%f\n", coordX, coordY);

            glColor3f(0x04, 0x02, 0x01);

            glVertex2f((float)(coordX) / 100, (float)(coordY) / 100);
        }

        glEnd();
    }
}


void renderer::renderloop(){

    GLFWwindow *window;

    // Initialize the library
    if (!glfwInit()) {
        std::cout << "Failed to initialize GLFW!\n";
        return;
    }

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(1920, 1080, "base", glfwGetPrimaryMonitor(), NULL);
    if (!window) {
        glfwTerminate();

        std::cout << "Failed to create window using GLFW!\n";
        return;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize OpenGL context" << std::endl;
        return;
    }

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window)) {
        // if Esc is pressed, close the window
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, GLFW_TRUE);
        }

        // render
        render();

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();

    exit(EXIT_SUCCESS);

}

