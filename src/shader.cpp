//
// Created by dogin-pc on 06/09/22.
//

#include "shader.hpp"
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

Shader::Shader(const char *vertexPath, const char *fragmentPath) {
    unsigned int vertexShader = createShader(vertexPath, GL_VERTEX_SHADER);
    unsigned int fragmentShader = createShader(fragmentPath, GL_FRAGMENT_SHADER);

    program = glCreateProgram();

    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);

    glLinkProgram(program);

    int  success;
    char infoLog[512];
    glGetProgramiv(program, GL_LINK_STATUS, &success);

    if(!success) {
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        log->error("Program link failed: " + string(infoLog));
        return;
    }

    log->success("Program loaded");

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    log->success("Shaders deleted");
}

unsigned int Shader::createShader(const char *path, GLenum type) {
    string code;
    ifstream file;

    file.open(path);
    stringstream stream;

    stream << file.rdbuf();

    file.close();

    code = stream.str();

    const char* shaderCode = code.c_str();

    unsigned int shader;
    shader = glCreateShader(type);

    glShaderSource(shader, 1, &shaderCode, NULL);
    glCompileShader(shader);

    int  success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if(!success) {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        log->error("Compilation failed: " + string(infoLog));
        return -1;
    }

    log->success("Shader loaded: " + string(path));

    return shader;
}
