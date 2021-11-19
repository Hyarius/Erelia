#include "erelia.h"

extern jgl::String chunk_texture_shader_vert;
extern jgl::String chunk_texture_shader_frag;

int main(int argc, char **argv)
{
	jgl::Application app = jgl::Application("Erelia", jgl::Vector2Int(1200, 860), jgl::Color(50, 50, 50));
	app.set_default_font("ressource/font/karma suture.ttf");
	app.add_shader("Chunk_shader", chunk_texture_shader_vert, chunk_texture_shader_frag);

	Main_application win_app = Main_application(nullptr);
	win_app.set_geometry(0, app.size());
	win_app.activate();

	return (app.run());
}