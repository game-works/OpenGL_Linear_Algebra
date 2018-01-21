//
//  shaderProgram.hpp
//  FinallyGL
//
//  Created by Mushegh Shahinyan on 1/18/18.
//  Copyright © 2018 Mushegh Shahinyan. All rights reserved.
//

#ifndef shaderProgram_hpp
#define shaderProgram_hpp

#include "shader.hpp"
#include <iostream>
#include <set>
#include <initializer_list>
/*
void shaderPrintLog(GLuint object) {
  GLint logLength = 0;
  if (glIsShader(object)) {
    glGetShaderiv(object, GL_INFO_LOG_LENGTH, &logLength);
  } else if (glIsProgram(object)) {
    glGetProgramiv(object, GL_INFO_LOG_LENGTH, &logLength);
  } else {
    std::cerr << "printlog: Not a shader or a program" << std::endl;
    return;
  }
  
  char* log = (char*)malloc(logLength);
  
  if (glIsShader(object))
    glGetShaderInfoLog(object, logLength, NULL, log);
  else if (glIsProgram(object))
    glGetProgramInfoLog(object, logLength, NULL, log);
  
  std::cerr << log;
  free(log);
}
*/
class shaderProgram: public objectInGL {
  std::set <shader*> shaders;
public:
  shaderProgram();
  shaderProgram(std::initializer_list<shader*> init);
  
  void addShader(shader *shdr);
  
  void removeShader(shader *shdr);
  
  void linkAndValidate();
  
  void activate();
  
  void printLog() const;
  
  GLuint getId() const { return id; }
  
  ~shaderProgram();
};

#endif /* shaderProgram_hpp */
