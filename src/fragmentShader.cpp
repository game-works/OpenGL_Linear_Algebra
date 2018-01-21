//
//  fragmentShader.cpp
//  FinallyGL
//
//  Created by Mushegh Shahinyan on 1/18/18.
//  Copyright © 2018 Mushegh Shahinyan. All rights reserved.
//

#include "fragmentShader.hpp"

fragmentShader::fragmentShader(const std::string &source): shader{GL_FRAGMENT_SHADER, source} {}
fragmentShader::fragmentShader(std::string &&source): shader{GL_FRAGMENT_SHADER, std::move(source)} {}

fragmentShader::~fragmentShader() {}
