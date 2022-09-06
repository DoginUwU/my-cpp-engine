//
// Created by dogin-pc on 06/09/22.
//

#ifndef ENGINE_SHADER_HPP
#define ENGINE_SHADER_HPP

#include <glad/glad.h>
#include "log.hpp"

class Shader {
public:
    unsigned int program;
    Shader(const char *vertexPath, const char *fragmentPath);
private:
    Log *log = new Log("SHADER");
    unsigned int createShader(const char *path, GLenum type);
};

#endif //ENGINE_SHADER_HPP
