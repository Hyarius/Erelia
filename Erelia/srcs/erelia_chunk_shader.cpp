#include "jgl.h"

jgl::String chunk_texture_shader_vert = {
	"#version 330 core\n"
	"layout(location = 0) in vec2 model_space;"
	"layout(location = 1) in vec2 vertexUV;"
	"uniform vec3 delta_pos;"
	"out vec2 UV;"
	"void main()"
	"{"
		"gl_Position = vec4(vec3(model_space, 0.0f) + delta_pos, 1.0f);"
		"UV = vertexUV;"
	"}"
};

jgl::String chunk_texture_shader_frag = {
	"#version 330 core\n"
	"in vec2 UV;"
	"out vec4 color;"
	"uniform sampler2D textureID;"
	"void main()"
	"{"
		"if (UV == vec2(-1, -1))"
			"discard;"
		"color = texture(textureID, UV).rgba;"
	"}"
};