#version 400

layout(location = 0) in vec2 coord2d;
out vec4 f_color;
uniform float offset_x;
uniform float scale_x;

void main(void) {
  gl_Position = vec4((coord2d.x + offset_x) * scale_x, coord2d.y, 0.0f, 1.0f);
  f_color = vec4(coord2d.xy / 2.0f + 0.5f, 1.0f, 1.0f);
}
