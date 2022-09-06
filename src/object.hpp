//
// Created by dogin-pc on 06/09/22.
//

#ifndef ENGINE_OBJECT_HPP
#define ENGINE_OBJECT_HPP

#include "glad/glad.h"
#include <GLFW/glfw3.h>

class Object {
public:
    Object();
    void setShader(int program);
    void update();
    void destroy();
private:
    int shaderProgram = 0;
    unsigned int VBO;
    unsigned int VAO;
    unsigned int EBO;
};

#endif //ENGINE_OBJECT_HPP
