//
//  shaderProgram.cpp
//  FinallyGL
//
//  Created by Mushegh Shahinyan on 1/18/18.
//  Copyright © 2018 Mushegh Shahinyan. All rights reserved.
//

#include "shaderProgram.hpp"

shaderProgram::shaderProgram() { this->id = glCreateProgram(); }

shaderProgram::shaderProgram(std::initializer_list<shader*> init) {
  this->id = glCreateProgram();
  for (auto &shdr: init) this->addShader(shdr);
  this->linkAndValidate();
}

void shaderProgram::addShader(shader *shdr) {
  glAttachShader(this->id, shdr->getId());
  shaders.insert(shdr);
}

void shaderProgram::removeShader(shader *shdr) {
  glDetachShader(shdr->getId(), this->id);
  shaders.erase(shdr);
}

void shaderProgram::linkAndValidate() {
  glLinkProgram(this->id);
  glValidateProgram(this->id);
}

void shaderProgram::printLog() const {
  GLint logLength = 0;
  glGetProgramiv(id, GL_INFO_LOG_LENGTH, &logLength);
  char* log = (char*)malloc(logLength);
  glGetProgramInfoLog(id, logLength, NULL, log);
  std::cerr << log;
  free(log);
}

void shaderProgram::activate() { glUseProgram(this->id); }

shaderProgram::~shaderProgram() { glDeleteProgram(this->id); }
