#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <utils.hpp>
#include <exercises/exercise.hpp>

class Triangle : public Exercise
{
public:
    Triangle();
    void run() override;
};

#endif // __TRIANGLE_H__