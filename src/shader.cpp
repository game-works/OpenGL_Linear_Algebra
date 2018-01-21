//
//  shader.cpp
//  FinallyGL
//
//  Created by Mushegh Shahinyan on 1/18/18.
//  Copyright © 2018 Mushegh Shahinyan. All rights reserved.
//

#include "shader.hpp"


shader::shader(GLenum type, const std::string &source): type{type} {
  this->id = glCreateShader(type);
  const char *src = source.c_str();
  glShaderSource(this->id, 1, &src, nullptr);
  glCompileShader(this->id);
}

void shader::printLog() const {
  GLint logLength = 0;
  glGetShaderiv(id, GL_INFO_LOG_LENGTH, &logLength);
  char* log = (char*)malloc(logLength);
  glGetShaderInfoLog(id, logLength, NULL, log);
  std::cerr << log;
  free(log);
}

shader::~shader() {
  glDeleteShader(this->id);
}

