#include "erelia.h"

void Map_renderer::_on_geometry_change()
{
	Chunk::unbake_point();
}

void Map_renderer::_render()
{
	if (_map == nullptr)
		return;

	static const jgl::Size_t sub_part = (1000 / Chunk::C_NB_FRAME) + 1;

	jgl::Size_t nb_frame = (jgl::Application::active_application()->time() % 1000) / sub_part;

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
				tmp_chunk->render(_depth + 3, nb_frame);
			}
		}
	}

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