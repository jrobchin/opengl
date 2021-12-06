#include <exercises/exercise.hpp>

Exercise::Exercise(const char *name, int w_width, int w_height)
    : name{name}, w_width{w_width}, w_height{w_height}
{
}

Exercise::Exercise(const char *name) : Exercise{name, DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT} {}

void Exercise::initlializeGLFW()
{
    // Initialize
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

GLFWwindow *Exercise::createWindow()
{
    // Create window
    GLFWwindow *window = glfwCreateWindow(800, 600, name, NULL, NULL);
    if (window == NULL)
    {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window");
    }

    return window;
}

GLuint Exercise::createBasicShaderProgram()
{
    // Load shaders
    std::string fileContents = readFile(VERTEX_SHADER_PATH);
    const char *vertexShaderSourceCStr = fileContents.c_str();
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSourceCStr, NULL);
    glCompileShader(vertexShader);
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
                  << infoLog << std::endl;
        std::cout << vertexShaderSourceCStr << std::endl;
    }

    fileContents = readFile(FRAGMENT_SHADER_PATH);
    const char *fragmentShaderSourceCStr = fileContents.c_str();
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSourceCStr, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"
                  << infoLog << std::endl;
        std::cout << fragmentShaderSourceCStr << std::endl;
    }

    // Create shader program
    GLuint shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n"
                  << infoLog << std::endl;
    }

    // Delete loaded shaders
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}

void Exercise::initializeGLAD()
{
    // Load functions
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        throw std::runtime_error("Failed to initialize GLAD");
}

Exercise &Exercise::initialize()
{
    std::cout << "Initializing " << name << std::endl;

    initlializeGLFW();
    window = createWindow();
    glfwMakeContextCurrent(window);
    initializeGLAD();
    basicShaderProgram = createBasicShaderProgram();

    return *this;
}

Exercise &Exercise::cleanup()
{
    glDeleteProgram(basicShaderProgram);
    glfwTerminate();

    return *this;
}
