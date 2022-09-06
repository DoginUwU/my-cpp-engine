//
// Created by dogin-pc on 05/09/22.
//

#include "window.hpp"
#include <iostream>

Window::Window(int width, int height, char *title) {
    window = glfwCreateWindow(800, 600, "Engine - Test", nullptr, nullptr);

    if(!window) {
        log->error("Failed to create a window...");
    }

    log->success("Created window");
}

GLFWwindow *Window::instance() {
    return window;
}

void Window::update() {
    glfwSwapBuffers(window); //  will swap the color buffer (a large 2D buffer that contains color values for each pixel in GLFW's window)
}

bool Window::shouldClose() {
    return glfwWindowShouldClose(window);
}
