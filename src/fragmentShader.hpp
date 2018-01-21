//
//  fragmentShader.hpp
//  FinallyGL
//
//  Created by Mushegh Shahinyan on 1/18/18.
//  Copyright © 2018 Mushegh Shahinyan. All rights reserved.
//

#ifndef fragmentShader_hpp
#define fragmentShader_hpp

#include "shader.hpp"

class fragmentShader: public shader {
public:
  fragmentShader(const std::string &source);
  fragmentShader(std::string &&source);
  ~fragmentShader();
};

#endif /* fragmentShader_hpp */
