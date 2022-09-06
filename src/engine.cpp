#include <iostream>
#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "window.hpp"
#include "shader.hpp"

using namespace std;

void processInput(GLFWwindow *window);

float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
};

int main() {
    // Initialize a GLFW
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a window
    Window *window = new Window(800, 600, "Engine - Test");

    glfwMakeContextCurrent(window->instance());

    // Initialize a GLAD
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        cout << "Failed to load glad, exiting..." << endl;

        return -1;
    }

    Shader *shader = new Shader("shaders/vertex/simple.vert", "shaders/fragments/simple.frag");

    // Set viewport
    glViewport(0, 0, 800, 600);

    // TODO: Remove
    // 0. bind VBO buffers
    unsigned int VBO;
    glGenBuffers(1, &VBO);

    // 1. bind Vertex Array Object
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // 2. copy our vertices array in a buffer for OpenGL to use
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // 3. then set the vertex attributes pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
    glEnableVertexAttribArray(0);
    //

    while(!window->shouldClose()) {
        processInput(window->instance());

        glClearColor(0.45f, 0.83f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // 4. use our shader program when we want to render an object
        glUseProgram(shader->program);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        window->update();
        glfwPollEvents(); // Check if any events are triggered (like keyboard input or mouse movement events)
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shader->program);

    glfwTerminate();

    return 0;
}

void processInput(GLFWwindow *window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE)) {
        glfwSetWindowShouldClose(window, true);
    }
}