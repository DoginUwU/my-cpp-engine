#include <iostream>
#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "window.hpp"
#include "shader.hpp"
#include "object.hpp"

using namespace std;

void processInput(GLFWwindow *window);

bool wireframe = false;

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

    Shader *basicShader = new Shader("shaders/vertex/simple.vert", "shaders/fragments/simple.frag");

   Object *triangle = new Object();
   triangle->setShader(basicShader->program);

    while(!window->shouldClose()) {
        processInput(window->instance());

        glClearColor(0.45f, 0.83f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

       triangle->update();

        window->update();
        glfwPollEvents(); // Check if any events are triggered (like keyboard input or mouse movement events)
    }

    triangle->destroy();

    glfwTerminate();

    return 0;
}

bool temp = false;
void processInput(GLFWwindow *window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE)) {
        glfwSetWindowShouldClose(window, true);
    }

    if(glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS && !temp) {
        wireframe = !wireframe;
        if(wireframe) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        } else {
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        }
        temp = true;
    }
    if(glfwGetKey(window, GLFW_KEY_P) == GLFW_RELEASE && temp) {
        temp = false;
    }
}