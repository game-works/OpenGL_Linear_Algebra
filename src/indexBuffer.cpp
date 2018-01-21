//
//  indexBuffer.cpp
//  FinallyGL
//
//  Created by Mushegh Shahinyan on 1/17/18.
//  Copyright © 2018 Mushegh Shahinyan. All rights reserved.
//

#include "indexBuffer.hpp"

GLuint indexBuffer::typeInGL = GL_ELEMENT_ARRAY_BUFFER;

indexBuffer::indexBuffer(GLsizeiptr size, const GLvoid * data, GLenum usage):
                            buffer{typeInGL, size, data, usage} {}

GLuint indexBuffer::getBoundId() { return buffer::boundTypeId[typeInGL]; }

indexBuffer::~indexBuffer() {}

