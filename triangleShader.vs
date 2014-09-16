#version 400

in vec3 VertexPosition;
in vec3 VertexColor;

out vec3 Color;

void main()
{
	Color = vec3(1.0, 0.0, 0.0);
	gl_Position = vec4(VertexPosition, 1.0);
}
