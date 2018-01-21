//
//  vertexBuffer.cpp
//  FinallyGL
//
//  Created by Mushegh Shahinyan on 1/17/18.
//  Copyright © 2018 Mushegh Shahinyan. All rights reserved.
//

#include "vertexBuffer.hpp"

GLuint vertexBuffer::typeInGL = GL_ARRAY_BUFFER;

vertexBuffer::vertexBuffer(GLsizeiptr size, const GLvoid * data, GLenum usage):
                            buffer{typeInGL, size, data, usage} {}

GLuint vertexBuffer:: getBoundId() { return buffer::boundTypeId[typeInGL]; }

vertexBuffer::~vertexBuffer() {}
