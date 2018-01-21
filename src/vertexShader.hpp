//
//  vertexShader.hpp
//  FinallyGL
//
//  Created by Mushegh Shahinyan on 1/18/18.
//  Copyright © 2018 Mushegh Shahinyan. All rights reserved.
//

#ifndef vertexShader_hpp
#define vertexShader_hpp

#include "shader.hpp"

class vertexShader: public shader {
public:
  vertexShader(const std::string &source);
  vertexShader(std::string &&source);
  ~vertexShader();
};

#endif /* vertexShader_hpp */
