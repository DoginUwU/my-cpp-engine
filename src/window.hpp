//
// Created by dogin-pc on 05/09/22.
//

#ifndef ENGINE_WINDOW_HPP
#define ENGINE_WINDOW_HPP

#include "glad/glad.h"
#include "log.hpp"
#include <GLFW/glfw3.h>

class Window {
public:
    Window(int width, int height, char *title);
    GLFWwindow* instance();

    void update();
    bool shouldClose();
private:
    Log *log = new Log("WINDOW");
    GLFWwindow *window;
};


#endif //ENGINE_WINDOW_HPP
