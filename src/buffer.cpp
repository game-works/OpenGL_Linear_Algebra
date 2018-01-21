//
//  buffer.cpp
//  FinallyGL
//
//  Created by Mushegh Shahinyan on 1/17/18.
//  Copyright © 2018 Mushegh Shahinyan. All rights reserved.
//

#include "buffer.hpp"

std::map<GLenum, GLuint> buffer::boundTypeId = std::map<GLenum, GLuint>{};

buffer::buffer(GLenum type, GLsizeiptr size, const GLvoid *data, GLenum usage):
                type{type}, size{size}, data{data}, usage{usage} {
  glGenBuffers(1, &id);
  this->bind();
  glBufferData(type, size, data, usage);
}

void buffer::bind() const {
  glBindBuffer(type, id);
  boundTypeId[type] = id;
}

void buffer::unbind() const {
  glBindBuffer(type, 0);
  boundTypeId[type] = 0;
}

buffer::~buffer() {
  if(boundTypeId[type] == id) { this->unbind(); }
  glDeleteBuffers(type, &id);
}
