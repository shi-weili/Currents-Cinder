#version 150

uniform mat4 ciModelViewProjection;

in vec4 ciPosition;
in vec4 ciTexCoord0;

out vec4 vTexCoord0;

void main(void)
{
	vTexCoord0 = ciTexCoord0;
	gl_Position = ciModelViewProjection * ciPosition;
}