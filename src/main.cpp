#include "glUtils.hpp"
#include "allBuffers.hpp"
#include "allShaders.hpp"
#include <stdio.h>
#include <cmath>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

//#include "SDL2/SDL.h"

#include "SDL2/SDL_image.h"

std::string getShaderSource(const std::string filepath) {
  std::ifstream stream(filepath);
  std::string line;
  std::stringstream ss;
  while(getline(stream, line)) {
    ss << line << '\n';
  }
  return ss.str();
}

struct point {
  GLfloat x;
  GLfloat y;
};


float offset = 0.0;
float scale = 1.0;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
  if (key == GLFW_KEY_LEFT && (action == GLFW_REPEAT || action == GLFW_PRESS)) offset += 0.1;
  else if (key == GLFW_KEY_RIGHT && (action == GLFW_REPEAT || action == GLFW_PRESS)) offset -= 0.1;
  else if (key == GLFW_KEY_DOWN && (action == GLFW_REPEAT || action == GLFW_PRESS)) scale /= 1.5;
  else if (key == GLFW_KEY_UP && (action == GLFW_REPEAT || action == GLFW_PRESS)) scale *= 1.5;
  else if (key == GLFW_KEY_R  && action == GLFW_PRESS) { offset = 0.0; scale = 1.0; }
}


int main() {
  // start GL context and O/S window using the GLFW helper library
  if (!glfwInit()) {
    fprintf(stderr, "ERROR: could not start GLFW3\n");
    return 1;
  }
  
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  
  GLFWwindow* window = glfwCreateWindow(800, 800, "Hello Triangle", NULL, NULL);
  if (!window) {
    fprintf(stderr, "ERROR: could not open window with GLFW3\n");
    glfwTerminate();
    return 1;
  }
  glfwMakeContextCurrent(window);
  glfwSwapInterval(1);
  
  // start GLEW extension handler
  glewExperimental = GL_TRUE;
  glewInit();
  
  point graph[2000];
  GLfloat real[4000] = {
    0.0, 0.0,
    0.8, 0.8,
    0.9, 0.7,
    0.1, -0.1
    
    
  };
  
  GLint indices[4000] = {
    0, 1, 2,
    1, 2, 3
  };
  
  GLuint vao = 0;
  GLCall(glGenVertexArrays(1, &vao));
  GLCall(glBindVertexArray(vao));
  
  vertexBuffer vbo(8 * sizeof(GLfloat), real, GL_STATIC_DRAW);
  
  glEnable(GL_LINE_SMOOTH);
  
  GLCall(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2*sizeof(GL_FLOAT), 0));
  
  indexBuffer ibo(6 * sizeof(GLuint), indices);
  
  
  
  std::unique_ptr<vertexShader> vs(new vertexShader(getShaderSource("res/shaders/Basic.vs")));
  std::unique_ptr<fragmentShader> fs(new fragmentShader(getShaderSource("res/shaders/Basic.fs")));
  shaderProgram basic{vs.get(), fs.get()};
  basic.activate();
  
  int location1 = glGetUniformLocation(basic.getId(), "offset_x");
  int location2 = glGetUniformLocation(basic.getId(), "scale_x");
  
  
  while(!glfwWindowShouldClose(window)) {
    // wipe the drawing surface clear
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    
    GLCall(glEnableVertexAttribArray(0));
    
    glUniform1f(location1, offset);
    glUniform1f(location2, scale);
    
    
    GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0));
    
    // update other events like input handling
    glfwPollEvents();
    
    glfwSetKeyCallback(window, key_callback);
    
    // put the stuff we've been drawing onto the display
    glfwSwapBuffers(window);
  }
  
  // close GL context and any other GLFW resources
  glfwTerminate();
  return 0;
}























