//
//  vertexShader.cpp
//  FinallyGL
//
//  Created by Mushegh Shahinyan on 1/18/18.
//  Copyright © 2018 Mushegh Shahinyan. All rights reserved.
//

#include "vertexShader.hpp"



vertexShader::vertexShader(const std::string &source): shader{GL_VERTEX_SHADER, source} {}
vertexShader::vertexShader(std::string &&source): shader{GL_VERTEX_SHADER, std::move(source)} {}

vertexShader::~vertexShader() {}

