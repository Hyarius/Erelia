#include "erelia.h"

Engine::Engine() :
	_map(nullptr),
	_player(nullptr)
{
	_map = new Map("overworld");
	_player = new Player();

	if (_player != nullptr)
		_entities[_player->id()] = _player;
}

void Engine::place_node(jgl::Vector2Int p_pos, jgl::Short p_value)
{
	if (_map != nullptr)
		_map->place_node(p_pos, p_value);
}

void Engine::place_scenery(jgl::Vector2Int p_pos, jgl::Int p_level, jgl::Short p_value)
{
	if (_map != nullptr)
		_map->place_scenery(p_pos, p_level, p_value);
}

void Engine::rebake()
{
	if (_map != nullptr)
		_map->rebake();
}
