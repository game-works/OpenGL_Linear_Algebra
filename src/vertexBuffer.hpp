//
//  vertexBuffer.hpp
//  FinallyGL
//
//  Created by Mushegh Shahinyan on 1/17/18.
//  Copyright © 2018 Mushegh Shahinyan. All rights reserved.
//

#ifndef vertexBuffer_hpp
#define vertexBuffer_hpp

#include "buffer.hpp"

class vertexBuffer: public buffer {
  static GLenum typeInGL;
  GLuint id;
public:
  vertexBuffer(GLsizeiptr size, const GLvoid * data, GLenum usage = GL_STATIC_DRAW);
  GLuint getBoundId();
  ~vertexBuffer();
};

#endif /* vertexBuffer_hpp */
