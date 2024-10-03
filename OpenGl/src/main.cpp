#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) glfwSetWindowShouldClose(window, true);
}


int main()
{
    if (!glfwInit())
    {
        return -1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window;
    window = glfwCreateWindow(800, 600, "TRIANGLE", NULL, NULL);
    if (window == NULL)
    {
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Information to GPU
    float vertices[] = {
       -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  
        0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,  
        0.0f,  0.5f, 0.0f,  1.0f, 0.0f, 0.0f   
    };

    unsigned int vbo;
    unsigned int vao;
    glGenVertexArrays(1, &vao);

    glBindVertexArray(vao);

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //2 We tell OPENGL how it should interpret the information
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0); // Posicions
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float))); // Colors
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);

    // 3- Create shaders and compile
    const char* vertexShaderSource = "#version 330 core\n"
                                 "layout (location = 0) in vec3 position;\n"
                                 "layout (location = 1) in vec3 color;\n"
                                 "out vec3 vertexColor;\n"
                                 "void main()\n"
                                 "{\n"
                                 "    gl_Position = vec4(position, 1.0);\n"
                                 "    vertexColor = color;\n"
                                 "}\n";

    const char* fragmentShaderSource = "#version 330 core\n"
                                   "in vec3 vertexColor;\n"
                                   "out vec4 FragColor;\n"
                                   "void main()\n"
                                   "{\n"
                                   "    FragColor = vec4(vertexColor, 1.0);\n"
                                   "}\n";

    unsigned int vertexShader;
    unsigned int fragmentShader;

    vertexShader = glCreateShader(GL_VERTEX_SHADER);      
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);

    glCompileShader(vertexShader);
    glCompileShader(fragmentShader);

    GLint success;
    GLchar infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);                                                                                          


    if(!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::VERTEX::SHADER::COMPILATION_FAILED\n";
        std::cout << infoLog;
    }
    
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);          
    if(!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::FRAGMENT::SHADER::COMPILATION_FAILED\n";
        std::cout << infoLog;
    }

    // 4- Create a ShaderProgram
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);

    glLinkProgram(shaderProgram);


    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "Error Linking \n";
        std::cout << infoLog;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);



    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


    glUseProgram(shaderProgram);
    while(!glfwWindowShouldClose(window))
    {
        processInput(window);
        glfwSwapBuffers(window);

        glClearColor(0.106f, 0.118f, 0.169f, 1.0f);  // Color de fondo oscuro
        glClear(GL_COLOR_BUFFER_BIT);
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES,0, 3);
        glBindVertexArray(0);

        glfwPollEvents();    
    }

    glDeleteBuffers(1, &vbo);
    glDeleteProgram(shaderProgram);
    glDeleteVertexArrays(1, &vao);
    glfwTerminate();
    return 0;
}

