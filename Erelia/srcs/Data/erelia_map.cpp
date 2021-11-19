#include "erelia.h"

#include <direct.h>
#include <stdlib.h>
#include <stdio.h>

Map::Map(jgl::String p_folder_path)
{
	_folder_path = "ressource/map/" + p_folder_path;

	int check = _mkdir(_folder_path.c_str());
	check = _mkdir((_folder_path + "/chunk").c_str());
}


void Map::load()
{
	
}

void Map::save()
{
	for (auto tmp : _chunks)
	{
		jgl::Vector2Int pos = tmp.first;
		Chunk* chunk = tmp.second;

		chunk->save(_folder_path + "/chunk");
	}
}

void Map::place_node(jgl::Vector2Int p_pos, jgl::Short p_value)
{
	Chunk* tmp_chunk = chunk(Map::chunk_pos(p_pos));

	tmp_chunk->place_node(p_pos, p_value);
}

void Map::place_scenery(jgl::Vector2Int p_pos, jgl::Int p_level, jgl::Short p_value)
{
	Chunk* tmp_chunk = chunk(Map::chunk_pos(p_pos));

	tmp_chunk->place_scenery(p_pos, p_level, p_value);
}

Chunk* Map::generate_chunk(jgl::Vector2Int p_pos)
{
	Chunk* new_chunk = new Chunk(p_pos);
	new_chunk->load(_folder_path + "/chunk");
	return (new_chunk);
}

Chunk* Map::request_chunk(jgl::Vector2Int p_pos) {
	if (_chunks.count(p_pos) == 0)
		_chunks[p_pos] = generate_chunk(p_pos);
	return (_chunks.at(p_pos));
}

Chunk* Map::chunk(jgl::Vector2Int p_pos) const {
	if (_chunks.count(p_pos) == 0)
		return (nullptr);
	return (_chunks.at(p_pos));
}

void Map::rebake()
{
	for (auto tmp : _chunks)
	{
		tmp.second->unbake();
	}
}

jgl::Vector2Int Map::chunk_pos(jgl::Vector2Int p_pos)
{
	jgl::Vector2Int result = p_pos / Chunk::C_SIZE;
	
	if (p_pos.x % Chunk::C_SIZE != 0 && p_pos.x < 0)
		result.x--;
	if (p_pos.y % Chunk::C_SIZE != 0 && p_pos.y < 0)
		result.y--;

	return (result);
}

jgl::Vector2Int Map::chunk_pos(jgl::Vector3Int p_pos)
{
	return (chunk_pos(jgl::Vector2Int(p_pos.x, p_pos.y)));
}