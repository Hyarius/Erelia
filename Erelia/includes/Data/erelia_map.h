#pragma once

#include "jgl.h"
#include "data/erelia_chunk.h"

class Map
{
private:
	jgl::Map<jgl::Vector2Int, Chunk*> _chunks;

public:
	Map();

	void place_node(jgl::Vector2Int p_pos, jgl::Short p_value);
	void place_scenery(jgl::Vector2Int p_pos, jgl::Int p_level, jgl::Short p_value);

	Chunk* generate_chunk(jgl::Vector2Int p_pos);

	Chunk* request_chunk(jgl::Vector2Int p_pos);

	Chunk* chunk(jgl::Vector2Int p_pos) const ;

	void rebake();

	static jgl::Vector2Int chunk_pos(jgl::Vector2Int p_pos);

	static jgl::Vector2Int chunk_pos(jgl::Vector3Int p_pos);
};
