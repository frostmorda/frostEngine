#version 460
layout (location = 0) in vec3 verticies;
uniform mat4 modelMatrix;
uniform vec3 color;
out vec3 myColor;
void main() {
    gl_Position = modelMatrix * vec4(verticies, 1.0);
    myColor = color;
}