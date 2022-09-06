//
// Created by dogin-pc on 06/09/22.
//

#include "object.hpp"

float vertices[] = {
        0.5f,  0.5f, 0.0f,  // top right
        0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
        -0.5f,  0.5f, 0.0f   // top left
};

unsigned int indices[] = {  // note that we start from 0!
        0, 1, 3,   // first triangle
        1, 2, 3    // second triangle
};

Object::Object() {
    glGenBuffers(1, &VBO);

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &EBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
    glEnableVertexAttribArray(0);
}

void Object::update() {
    glUseProgram(shaderProgram);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    glUseProgram(0);
    glBindVertexArray(0);
}

void Object::destroy() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}

void Object::setShader(int program) {
    shaderProgram = program;
}