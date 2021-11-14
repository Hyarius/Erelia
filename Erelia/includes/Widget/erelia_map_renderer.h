#pragma once

#include "jgl.h"
#include "erelia.h"

class Map_renderer : public jgl::Widget
{
private:
	Map* _map;

	void _on_geometry_change();
	void _render();

	bool _update();
	bool _fixed_update();

	jgl::Array<jgl::Vector2Int> _active_chunk;

public:
	Map_renderer(Map* p_map, jgl::Widget* p_parent = nullptr);
};
