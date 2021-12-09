#ifndef __SQUARE_H__
#define __SQUARE_H__

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <utils.hpp>
#include <exercises/exercise.hpp>

class Position
{
public:
    float x, y, z;

    friend std::ostream &operator<<(std::ostream &out, const Position &pos)
    {
        out << "Point(" << pos.x << ", " << pos.y << ", " << pos.z << ')'; // actual output done here

        return out;
    }
};

class Square : public Exercise
{
private:
    Position pos;
    float dims = 0.05f;
    GLuint VBO, VAO, EBO;

    void update();
    void processInput();

public:
    Square();
    Square &run() override;
};

#endif // __SQUARE_H__