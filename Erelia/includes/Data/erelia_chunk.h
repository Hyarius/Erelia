#pragma once

#include "jgl.h"
#include "erelia_world_object.h"

class Chunk
{
public:
	static const jgl::Size_t C_SIZE = 16u;
	static const jgl::Size_t C_NB_LAYER = 5u;
private:
	jgl::Vector2Int _pos;
	jgl::Short _nodes[C_SIZE][C_SIZE];
	jgl::Short _sceneries[C_SIZE][C_SIZE][C_NB_LAYER];
	
	Chunk* _neightbour_chunks[3][3];
	jgl::Bool _baked;

	static jgl::Bool _points_baked;
	static jgl::Buffer* _element_buffer;
	static jgl::Buffer* _point_buffer;
	static jgl::Buffer* _uv_base_buffer;
	static jgl::Uniform* _position_uniform;
	static jgl::Uniform* _texture_uniform;
	static jgl::Vector2* _bake_uvs_array;
	static jgl::Shader* _chunk_shader;

	jgl::Buffer* _uvs_node_buffer;
	jgl::Buffer* _uvs_scenery_buffer[C_NB_LAYER];

	jgl::String _compose_name()
	{
		return ("chunk" + jgl::itoa(_pos.x) + "x" + jgl::itoa(_pos.y) + "y");
	}
	void _bake_points();
	void _bake_autotile(const class Map* p_map, jgl::Sprite_sheet* p_sprite_sheet, jgl::Vector2* p_uvs, jgl::Vector2Int p_sprite, jgl::Vector2Int p_pos, jgl::Int p_level, jgl::Size_t base_index);
	void _bake_tile(jgl::Sprite_sheet* p_sprite_sheet, jgl::Vector2* p_uvs, jgl::Vector2Int p_sprite, jgl::Size_t base_index);
	void _bake_nodes(const class Map* p_map);
	void _bake_sceneries(const class Map* p_map);

	void _render_nodes(jgl::Vector3& p_delta_pos, jgl::Float p_depth);
	void _render_sceneries(jgl::Vector3& p_delta_pos, jgl::Int p_level, jgl::Float p_depth);

	void _compose_neightbour_chunk(const Map* p_map);
public:
	Chunk(jgl::Vector2Int p_pos);

	jgl::Int node(jgl::Vector2Int p_pos);
	jgl::Int scenery(jgl::Vector2Int p_pos, jgl::Int p_level);

	void place_node(jgl::Vector2Int p_pos, jgl::Short p_value);
	void place_scenery(jgl::Vector2Int p_pos, jgl::Int p_level, jgl::Short p_value);

	void save(jgl::String path);
	void load(jgl::String path);

	jgl::Bool baked() { return (_baked && _points_baked); }

	static void unbake_point() { _points_baked = false; }
	void unbake();
	void bake(const class Map* p_map);
	void rebake(const class Map* p_map);
	void render(jgl::Float p_depth);
};