//
//  glUtils.h
//  FinallyGL
//
//  Created by Mushegh Shahinyan on 1/17/18.
//  Copyright © 2018 Mushegh Shahinyan. All rights reserved.
//

#ifndef glUtils_hpp
#define glUtils_hpp

#include <GL/glew.h> // include GLEW and new version of GL on Windows
#include <GLFW/glfw3.h> // GLFW helper library
#include <iostream>

#define ASSERT(x) if(!(x)) __asm__("int $3");
#define GLCall(x) GLClearError(); x; ASSERT(GLLogCall(#x, __FILE__, __LINE__))


static void GLClearError() {
  while(glGetError() != GL_NO_ERROR) {}
}

static bool GLLogCall(const char *function, const char *file, int line) {
  while(GLenum error = glGetError()) {
    std::cout << "[OpenGL Error] (" << error << "): " << function << " " << file <<  ":" << line << std::endl;
    return false;
  }
  return true;
}

class objectInGL {
protected:
  GLuint id;
};

#endif /* glUtils_hpp */
