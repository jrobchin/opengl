#include <exercises/square.hpp>

Square::Square() : Exercise{"Square"}, pos{0.0f, 0.0f, 0.0f} {}

void Square::processInput()
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    const float speed = 0.0001f;
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
        pos.y += speed;
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
        pos.y -= speed;
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
        pos.x += speed;
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
        pos.x -= speed;
}

void Square::update()
{
    // Define vertices
    // This is a horrible way to translate
    float vertices[] = {
        -dims + pos.x, dims + pos.y, 0.0f + pos.z,  // top left
        -dims + pos.x, -dims + pos.y, 0.0f + pos.z, // bottom left
        dims + pos.x, dims + pos.y, 0.0f + pos.z,   // top right
        dims + pos.x, -dims + pos.y, 0.0f + pos.z   // bottom right
    };

    // Define indices for the squares
    uint indices[] = {
        0, 2, 1,
        2, 3, 1};

    // Bind VAO
    glBindVertexArray(VAO);

    // Bind VBO and fill with data
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Bind EBO
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // Point vertex data to location 0
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    // Unbind buffers
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // Unbind VAO
    glBindVertexArray(0);
}

Square &Square::run()
{
    glViewport(0, 0, w_width, w_height);

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    while (!glfwWindowShouldClose(window))
    {
        processInput();

        update();
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(basicShaderProgram);
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);

    return *this;
}