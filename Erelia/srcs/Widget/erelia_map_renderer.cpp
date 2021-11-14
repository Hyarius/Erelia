#include "erelia.h"

void Map_renderer::_on_geometry_change()
{
	Chunk::unbake_point();
}

void Map_renderer::_render()
{
	if (_map == nullptr)
		return;

	jgl::Vector2Int start = (Main_application::instance()->convert_screen_to_world(0) / Chunk::C_SIZE).floor() - 1;

	jgl::Vector2Int end = (Main_application::instance()->convert_screen_to_world(jgl::Application::active_application()->size()) / Chunk::C_SIZE).floor() + 1;

	for (jgl::Int x = start.x; x <= end.x; x++)
	{
		for (jgl::Int y = start.y; y <= end.y; y++)
		{
			jgl::Vector2Int tmp_pos = jgl::Vector2Int(x, y);
			Chunk* tmp_chunk = _map->request_chunk(tmp_pos);

			if (tmp_chunk != nullptr)
			{
				if (tmp_chunk->baked() == false)
				{
					tmp_chunk->bake(_map);
				}
				tmp_chunk->render(_depth + 3);
			}
		}
	}

	jgl::draw_text("FPS : " + jgl::itoa(jgl::Application::active_application()->fps()), 50, 20, _depth + 1000, 1.0f, jgl::Color::white(), jgl::Color::black());
}

bool Map_renderer::_update()
{
	return (false);
}

bool Map_renderer::_fixed_update()
{
	return (false);
}

Map_renderer::Map_renderer(Map* p_map, jgl::Widget* p_parent) : jgl::Widget(p_parent),
	_map(nullptr)
{
	_map = p_map;
}