#include <exercises/triangle.hpp>

Triangle::Triangle() : Exercise{"Triangle"}
{
}

void Triangle::run()
{
    // Setup viewpoint
    // TODO: make resizable
    glViewport(0, 0, 800, 600);

    // Create vertex data for traingle
    float verticies[] = {-0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f};

    // Generate VBO
    GLuint VBO;
    glGenBuffers(1, &VBO);

    // Generate VAO
    GLuint VAO;
    glGenVertexArrays(1, &VAO);

    // Bind VAO
    glBindVertexArray(VAO);

    // Bind VBO and fill with data
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), verticies, GL_STATIC_DRAW);

    // Vertex attribute pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    // Unbind VBO and VAO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(basicShaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(basicShaderProgram);

    glfwTerminate();
}