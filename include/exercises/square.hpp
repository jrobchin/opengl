#ifndef __SQUARE_H__
#define __SQUARE_H__

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <utils.hpp>
#include <exercise.hpp>

class Square : public Exercise
{
public:
    Square();
    void run() override;
}

#endif // __SQUARE_H__