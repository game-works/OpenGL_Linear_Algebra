//
//  buffer.hpp
//  FinallyGL
//
//  Created by Mushegh Shahinyan on 1/17/18.
//  Copyright © 2018 Mushegh Shahinyan. All rights reserved.
//

#ifndef buffer_hpp
#define buffer_hpp

#include "glUtils.hpp"
#include <map>

class buffer: public objectInGL {
public:
  static std::map<GLenum, GLuint> boundTypeId;
private:
  GLenum const type;
  GLsizeiptr size;
  const GLvoid *data;
  GLenum usage;
public:
  buffer(GLenum type, GLsizeiptr size, const GLvoid *data, GLenum usages);
  void bind() const;
  void unbind() const;
  virtual ~buffer();
};

#endif /* buffer_hpp */
