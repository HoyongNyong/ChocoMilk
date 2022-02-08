#shader
#version 460 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 vTexCoord;

out vec2 texCoord;

uniform mat4 model;
uniform mat4 camMatrix;

void main(){
	gl_Position = camMatrix*model*vec4( position.x, position.y, 0.0, 1.0 ) ;
	texCoord = vTexCoord;
};
