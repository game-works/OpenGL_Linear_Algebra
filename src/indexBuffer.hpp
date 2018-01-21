//
//  indexBuffer.hpp
//  FinallyGL
//
//  Created by Mushegh Shahinyan on 1/17/18.
//  Copyright © 2018 Mushegh Shahinyan. All rights reserved.
//

#ifndef indexBuffer_hpp
#define indexBuffer_hpp

#include "buffer.hpp"

class indexBuffer: public buffer {
  static GLenum typeInGL;
  GLuint id;
public:
  indexBuffer(GLsizeiptr size, const GLvoid * data, GLenum usage = GL_STATIC_DRAW);
  GLuint getBoundId();
  ~indexBuffer();
};

#endif /* indexBuffer_hpp */

