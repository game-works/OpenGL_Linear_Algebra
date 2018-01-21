//
//  shader.hpp
//  FinallyGL
//
//  Created by Mushegh Shahinyan on 1/18/18.
//  Copyright © 2018 Mushegh Shahinyan. All rights reserved.
//

#ifndef shader_hpp
#define shader_hpp

#include "glUtils.hpp"

class shader: public objectInGL {
protected:
  GLenum type;
private:
  GLuint id;
public:
  shader(GLenum type, const std::string &source);
  
  void printLog() const;
  
  GLuint getId() const { return this->id; }
  
  virtual ~shader();
};

#endif /* shader_hpp */
