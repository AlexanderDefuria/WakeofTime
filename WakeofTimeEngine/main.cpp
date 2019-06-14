#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "ObjectPool.h"
#include <chrono>  // for high_resolution_clock

class Test {
public:
    Test():m_a(0),m_b('0'){
        std::cout<<"Construct default Test"<<*this<<"\n";
    }
    Test(int a, char b): m_a(a), m_b(b) {
        std::cout<<"Construct Test"<<*this<<"\n";
    }
    Test(const Test& orig): m_a(orig.m_a),m_b(orig.m_b) {
        std::cout<<"Construct cpy Test"<<*this<<"\n";
    }
    ~Test() {
        std::cout<<"Delete Test"<<*this<<"\n";
    }
    friend std::ostream& operator<<(std::ostream& ostream, const Test& test) {
        ostream<<"["<<test.m_a<<",'"<<test.m_b<<"']";
        return ostream;
    }

    static void error_callback(int error, const char* description)
    {
        fputs(description, stderr);
    }
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
            glfwSetWindowShouldClose(window, GL_TRUE);
    }

private:
    int m_a;
    char m_b;
};

struct Initialiser {
    void operator() (Test* element) {
        std::cout<<"Initialising Test"<<*element<<"\n";
    }
};

struct Releaser {
    void operator() (Test* element) {
        std::cout<<"Releasing Test"<<*element<<"\n";
    }
};

int main(int argc, char** argv) {
    using TestPool = StackObjectPool<Test,5, Initialiser, Releaser>;
    TestPool pool;
    TestPool::pointer pt1, pt2, pt3;

    std::cout<<pool;

    auto start = std::chrono::high_resolution_clock::now();
    pt1= pool.acquire();
    pt1.reset();
    auto finish = std::chrono::high_resolution_clock::now();


    std::chrono::duration<double> elapsed = finish - start;


    std::cout<<pool;

    pt2 = pool.acquire();
    std::cout<<"Aquired pt:"<<*pt2<<"\n";
    pt2.reset();

    std::cout<<pool;

    pt3 = pool.acquire();
    std::cout<<"Aquired pt:"<<*pt3<<"\n";
    //pt3.reset();

    std::cout<<pool;
    return 0;
}