#pragma once

#include "jgl.h"
#include "data/erelia_map.h"
#include "data/erelia_player.h"
#include "data/erelia_entity.h"

struct Engine_data
{
	jgl::Short _block_editor_id;

	Engine_data()
	{
		::memset(this, 0, sizeof(Engine_data));
	}
};

class Engine
{
private:
	Engine_data _data;

	Map* _map;
	Player* _player;

	jgl::Map<jgl::Long, Entity*> _entities;

public:
	Engine();

	void place_node(jgl::Vector2Int p_pos, jgl::Short p_value);
	void place_scenery(jgl::Vector2Int p_pos, jgl::Int p_level, jgl::Short p_value);

	void rebake();

	Engine_data& data() { return _data; }
	Map* map() { return (_map); }
	Player* player() { return (_player); }
	jgl::Map<jgl::Long, Entity*>& entities() { return (_entities); }
};
