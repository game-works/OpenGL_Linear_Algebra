#version 400

in vec4 f_color;

layout(location = 0) out vec4 color;


void main(void) {
  color = f_color;
}

