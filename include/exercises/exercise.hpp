#ifndef __EXERCISE_H__
#define __EXERCISE_H__

#include <string>
#include <iostream>
#include <exception>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <utils.hpp>

#define DEFAULT_WINDOW_WIDTH 800
#define DEFAULT_WINDOW_HEIGHT 600

class Exercise
{
private:
    const char *VERTEX_SHADER_PATH = "./shaders/basic.vert";
    const char *FRAGMENT_SHADER_PATH = "./shaders/basic.frag";

    const char *name;

    void initlializeGLFW();
    GLFWwindow *createWindow();
    void initializeGLAD();

protected:
    int w_width, w_height;

    GLFWwindow *window;
    GLuint basicShaderProgram;

    GLuint createBasicShaderProgram();

public:
    Exercise(const char *name, int w_width, int w_height);
    Exercise(const char *name);
    Exercise &initialize();
    Exercise &cleanup();
    virtual Exercise &run() = 0;
};

#endif // __EXERCISE_H__