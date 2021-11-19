#include "erelia.h"

jgl::Bool Chunk::_points_baked = false;
jgl::Buffer* Chunk::_element_buffer = nullptr;
jgl::Buffer* Chunk::_point_buffer = nullptr;
jgl::Uniform* Chunk::_position_uniform = nullptr;
jgl::Uniform* Chunk::_texture_uniform = nullptr;
jgl::Buffer* Chunk::_uv_base_buffer = nullptr;
jgl::Vector2* Chunk::_bake_uvs_array = nullptr;
jgl::Shader* Chunk::_chunk_shader = nullptr;

Chunk::Chunk(jgl::Vector2Int p_pos)
{
	_baked = false;
	_pos = p_pos;

	for (jgl::Size_t i = 0; i < C_SIZE; i++)
		for (jgl::Size_t j = 0; j < C_SIZE; j++)
		{
			_nodes[i][j] = -1;
			for (jgl::Size_t h = 0; h < C_NB_LAYER; h++)
				_sceneries[i][j][h] = -1;
		}

	_uvs_node_buffer = nullptr;

	for (jgl::Size_t i = 0; i < C_NB_LAYER; i++)
		_uvs_scenery_buffer[i] = nullptr;

	for (jgl::Size_t i = 0; i < 3; i++)
	{
		for (jgl::Size_t j = 0; j < 3; j++)
		{
			_neightbour_chunks[i][j] = nullptr;
		}
	}
}

void Chunk::place_node(jgl::Vector2Int p_pos, jgl::Short p_value)
{
	p_pos.x %= Chunk::C_SIZE;
	p_pos.y %= Chunk::C_SIZE;

	if (_nodes[p_pos.x][p_pos.y] != p_value)
	{
		_nodes[p_pos.x][p_pos.y] = p_value;
		_baked = false;
	}
}

void Chunk::place_scenery(jgl::Vector2Int p_pos, jgl::Int p_level, jgl::Short p_value)
{
	p_pos.x %= Chunk::C_SIZE;
	p_pos.y %= Chunk::C_SIZE;
	p_level %= Chunk::C_NB_LAYER;

	if (_sceneries[p_pos.x][p_pos.y][p_level] != p_value)
	{
		_sceneries[p_pos.x][p_pos.y][p_level] = p_value;
		_baked = false;
	}
}

void Chunk::save(jgl::String p_path)
{
	jgl::File my_file = jgl::open_file(p_path + "/" + _compose_name(), jgl::File_mode::out);
	for (jgl::Size_t i = 0; i < C_SIZE; i++)
	{
		for (jgl::Size_t j = 0; j < C_SIZE; j++)
		{
			jgl::Short value = _nodes[i][j];
			void* add = &(value);
			my_file.write(static_cast<const char*>(add), sizeof(value));
		}
	}
	for (jgl::Size_t i = 0; i < C_SIZE; i++)
	{
		for (jgl::Size_t j = 0; j < C_SIZE; j++)
		{
			for (jgl::Size_t h = 0; h < C_NB_LAYER; h++)
			{
				jgl::Short value = _sceneries[i][j][h];
				void* add = &(value);
				my_file.write(static_cast<const char*>(add), sizeof(value));
			}
		}
	}
	my_file.close();
}

void Chunk::load(jgl::String p_path)
{
	jgl::String final_path = p_path + "/" + _compose_name();

	if (jgl::check_file_exist(final_path) == true)
	{
		jgl::File my_file = jgl::open_file(final_path, jgl::File_mode::in);

		void* tmp = _nodes;

		my_file.read(static_cast<char*>(tmp), sizeof(jgl::Short) * C_SIZE * C_SIZE);

		tmp = _sceneries;

		my_file.read(static_cast<char*>(tmp), sizeof(jgl::Short) * C_SIZE * C_SIZE * C_NB_LAYER);

		my_file.close();
	}
	
}

jgl::Vector2 delta_node_pos[4] = {
	jgl::Vector2(0.0f, 0.0f),
	jgl::Vector2(0.0f, 0.5f),
	jgl::Vector2(0.5f, 0.0f),
	jgl::Vector2(0.5f, 0.5f)
};
jgl::Vector2 delta_sprite_uv[4] = {
	jgl::Vector2(0.0f, 0.0f),
	jgl::Vector2(0.0f, 1.0f),
	jgl::Vector2(1.0f, 0.0f),
	jgl::Vector2(1.0f, 1.0f)
};

jgl::Int Chunk::node(jgl::Vector2Int p_pos)
{
	if (p_pos.x < 0 || p_pos.x >= C_SIZE ||
		p_pos.y < 0 || p_pos.y >= C_SIZE)
		return (-1);
	return (_nodes[p_pos.x][p_pos.y]);
}

jgl::Int Chunk::scenery(jgl::Vector2Int p_pos, jgl::Int p_level)
{
	if (p_pos.x < 0 || p_pos.x >= C_SIZE ||
		p_pos.y < 0 || p_pos.y >= C_SIZE ||
		p_level < 0 || p_level >= C_NB_LAYER)
		return (-1);
	return (_sceneries[p_pos.x][p_pos.y][p_level]);
}

static jgl::Uint element_index[6] = { 0, 3, 1, 2, 3, 0 };

void Chunk::_bake_points()
{
	jgl::Array<jgl::Vector2> points;
	jgl::Array<jgl::Uint> elements;

	if (_point_buffer == nullptr)
		_point_buffer = _chunk_shader->buffer("model_space")->copy();
	if (_element_buffer == nullptr)
		_element_buffer = _chunk_shader->indexes_buffer()->copy();

	for (jgl::Float i = 0; i < C_SIZE; i++)
	{
		for (jgl::Float j = 0; j < C_SIZE; j++)
		{
			for (jgl::Float delta_i = 0; delta_i < 1; delta_i += 0.5f)
			{
				for (jgl::Float delta_j = 0; delta_j < 1; delta_j += 0.5f)
				{
					jgl::Uint base_index = points.size();

					for (jgl::Size_t side = 0; side < 4; side++)
					{
						jgl::Vector2 pos = jgl::Vector2(i + delta_i, j + delta_j) + delta_node_pos[side];
						points.push_back(jgl::convert_screen_to_opengl(pos * World_object::Node::C_SIZE) + jgl::Vector2(1, -1));
					}

					for (jgl::Size_t h = 0; h < 6; h++)
					{
						elements.push_back(element_index[h] + base_index);
					}
				}
			}

		}
	}

	_point_buffer->send(points.all(), points.size());
	_element_buffer->send(elements.all(), elements.size());

	_points_baked = true;
}

void Chunk::_compose_neightbour_chunk(const Map* p_map)
{
	for (jgl::Int i = -1; i <= 1; i++)
	{
		for (jgl::Int j = -1; j <= 1; j++)
		{
			_neightbour_chunks[i + 1][j + 1] = p_map->chunk(_pos + jgl::Vector2Int(i, j));
		}
	}
}

void Chunk::_bake_autotile(const Map* p_map, jgl::Sprite_sheet* p_sprite_sheet, jgl::Vector2* p_uvs, jgl::Vector2Int p_sprite, jgl::Vector2Int p_pos, jgl::Int p_level, jgl::Size_t base_index)
{
	static jgl::Vector2Int baking_neightbour_node[4][3] = {
		{
			jgl::Vector2Int(-1, 0),
			jgl::Vector2Int(-1, -1),
			jgl::Vector2Int(0, -1),
		},
		{
			jgl::Vector2Int(0, 1),
			jgl::Vector2Int(-1, 1),
			jgl::Vector2Int(-1, 0),
		},
		{
			jgl::Vector2Int(0, -1),
			jgl::Vector2Int(1, -1),
			jgl::Vector2Int(1, 0),
		},
		{
			jgl::Vector2Int(1, 0),
			jgl::Vector2Int(1, 1),
			jgl::Vector2Int(0, 1),
		},
	};
	static jgl::Vector2Int baking_delta_node_sprite[4][2][2][2] = {
		/*
			if next node == actual -> 0 
			else -> 1
		*/
		{// Passe 1
			{// A = 1
				{// B = 1
					jgl::Vector2Int(1, 3), // ABC
					jgl::Vector2Int(1, 2)  // AB
				},
				{// B = 0
					jgl::Vector2Int(2, 0), // A C
					jgl::Vector2Int(1, 2)  // A
				}
			},
			{// A = 0
				{// B = 1
					jgl::Vector2Int(0, 3), //  BC
					jgl::Vector2Int(0, 0)  //  B
				},
				{// B = 0
					jgl::Vector2Int(0, 3), //   C
					jgl::Vector2Int(0, 0)  // 
				}
			}
		},
		{// Passe 2
			{// A = 1
				{// B = 1
					jgl::Vector2Int(1, 4), // ABC
					jgl::Vector2Int(0, 4)  // AB
				},
				{// B = 0
					jgl::Vector2Int(2, 1), // A C
					jgl::Vector2Int(0, 4)  // A
				}
			},
			{// A = 0
				{// B = 1
					jgl::Vector2Int(1, 5), //  BC
					jgl::Vector2Int(0, 1)  //  B
				},
				{// B = 0
					jgl::Vector2Int(1, 5), //   C
					jgl::Vector2Int(0, 1)  // 
				}
			}
		},
		{// Passe 3
			{// A = 1
				{// B = 1
					jgl::Vector2Int(2, 3), // ABC
					jgl::Vector2Int(3, 3)  // AB
				},
				{// B = 0
					jgl::Vector2Int(3, 0), // A C
					jgl::Vector2Int(3, 3)  // A
				}
			},
			{// A = 0
				{// B = 1
					jgl::Vector2Int(2, 2), //  BC
					jgl::Vector2Int(1, 0)  //  B
				},
				{// B = 0
					jgl::Vector2Int(2, 2), //   C
					jgl::Vector2Int(1, 0)  // 
				}
			}
		},
		{// Passe 4
			{// A = 1
				{// B = 1
					jgl::Vector2Int(2, 4), // ABC
					jgl::Vector2Int(2, 5)  // AB
				},
				{// B = 0
					jgl::Vector2Int(3, 1), // A C
					jgl::Vector2Int(2, 5)  // A
				}
			},
			{// A = 0
				{// B = 1
					jgl::Vector2Int(3, 4), //  BC
					jgl::Vector2Int(1, 1)  //  B
				},
				{// B = 0
					jgl::Vector2Int(3, 4), //   C
					jgl::Vector2Int(1, 1)  // 
				}
			}
		},
	};

	jgl::Int first_value = (p_level == -1 ? node(p_pos) : scenery(p_pos.x, p_level));

	for (jgl::Size_t sub_part = 0; sub_part < 4; sub_part++)
	{
		jgl::Bool values[3] = {false, false, false};
		for (jgl::Size_t j = 0; j < 3; j++)
		{
			jgl::Vector2Int next_pos = p_pos + baking_neightbour_node[sub_part][j];
			jgl::Int chunk_x = (next_pos.x == -1 ? 0 : (next_pos.x != C_SIZE ? 1 : 2));
			jgl::Int chunk_y = (next_pos.y == -1 ? 0 : (next_pos.y != C_SIZE ? 1 : 2));

			next_pos.x = next_pos.x % C_SIZE;
			next_pos.y = next_pos.y % C_SIZE;

			jgl::Int next_value;
			
			if (_neightbour_chunks[chunk_x][chunk_y] == nullptr)
			{
				next_value = -1;
			}
			else
			{
				next_value = (p_level == -1 ?
					_neightbour_chunks[chunk_x][chunk_y]->node(next_pos) :
					_neightbour_chunks[chunk_x][chunk_y]->scenery(next_pos, p_level)
					);
			}
			values[j] = (next_value == first_value ? false : true);
		}
		jgl::Vector2 base_sprite = p_sprite_sheet->sprite(p_sprite + baking_delta_node_sprite[sub_part][values[0]][values[1]][values[2]]);
		
		for (jgl::Size_t i = 0; i < 4; i++)
		{
			jgl::Size_t index = base_index + sub_part * 4 + i;
			p_uvs[index] = base_sprite + delta_sprite_uv[i] * p_sprite_sheet->unit();
		}
	}
}

void Chunk::_bake_tile(jgl::Sprite_sheet* p_sprite_sheet, jgl::Vector2* p_uvs, jgl::Vector2Int p_sprite, jgl::Size_t base_index)
{
	jgl::Vector2 entry_sprite = p_sprite_sheet->sprite(p_sprite);
	for (jgl::Size_t sub_part = 0; sub_part < 4; sub_part++)
	{
		jgl::Vector2 base_sprite = entry_sprite + delta_node_pos[sub_part] * p_sprite_sheet->unit();
		for (jgl::Size_t i = 0; i < 4; i++)
		{
			jgl::Size_t index = base_index + sub_part * 4 + i;
			p_uvs[index] = base_sprite + delta_node_pos[i] * p_sprite_sheet->unit();
		}
	}
}

void Chunk::_bake_nodes(const Map* p_map)
{

	if (_chunk_shader == nullptr)
		_chunk_shader = jgl::Application::active_application()->shader("Chunk_shader");
	if (_uv_base_buffer == nullptr)
		_uv_base_buffer = _chunk_shader->buffer("vertexUV");
	if (_uvs_node_buffer == nullptr)
		_uvs_node_buffer = _uv_base_buffer->copy();

	if (_bake_uvs_array == nullptr)
		_bake_uvs_array = new jgl::Vector2[C_SIZE * C_SIZE * 16];

	for (jgl::Size_t i = 0; i < C_SIZE; i++)
	{
		for (jgl::Size_t j = 0; j < C_SIZE; j++)
		{
			if (_nodes[i][j] == -1)
			{
				for (jgl::Size_t p = 0; p < 16; p++)
				{
					jgl::Size_t index = p + j * 16 + i * C_SIZE * 16;
					_bake_uvs_array[index] = -1;
				}
			}
			else
			{
				jgl::Size_t index = j * 16 + i * C_SIZE * 16;
				World_object::Node& tmp_node = World_object::g_node_array[_nodes[i][j]];

				if (tmp_node.autotiled == true)
					_bake_autotile(p_map, World_object::Node::C_TEXTURE_SHEET, _bake_uvs_array, tmp_node.sprite, jgl::Vector2Int(i, j), -1, index);
				else
					_bake_tile(World_object::Node::C_TEXTURE_SHEET, _bake_uvs_array, tmp_node.sprite, index);
			}

		}
	}

	_uvs_node_buffer->send(_bake_uvs_array, C_SIZE * C_SIZE * 16);
}

void Chunk::_bake_sceneries(const Map* p_map)
{
	if (_chunk_shader == nullptr)
		_chunk_shader = jgl::Application::active_application()->shader("Chunk_shader");
	if (_uv_base_buffer == nullptr)
		_uv_base_buffer = _chunk_shader->buffer("vertexUV");

	for (jgl::Size_t h = 0; h < C_NB_LAYER; h++)
	{

		if (_uvs_scenery_buffer[h] == nullptr)
			_uvs_scenery_buffer[h] = _uv_base_buffer->copy();

		if (_bake_uvs_array == nullptr)
			_bake_uvs_array = new jgl::Vector2[C_SIZE * C_SIZE * 16];

		for (jgl::Size_t i = 0; i < C_SIZE; i++)
		{
			for (jgl::Size_t j = 0; j < C_SIZE; j++)
			{
				if (_sceneries[i][j][h] == -1)
				{
					for (jgl::Size_t p = 0; p < 16; p++)
					{
						jgl::Size_t index = p + j * 16 + i * C_SIZE * 16;
						_bake_uvs_array[index] = -1;
					}
				}
				else
				{
					jgl::Size_t index = j * 16 + i * C_SIZE * 16;
					World_object::Scenery_part& tmp_scenery_part = World_object::g_scenery_part_array[_sceneries[i][j][h]];

					if (tmp_scenery_part.autotiled == true)
						_bake_autotile(p_map, World_object::Scenery_part::C_TEXTURE_SHEET, _bake_uvs_array, tmp_scenery_part.sprite, jgl::Vector2Int(i, j), h, index);
					else
						_bake_tile(World_object::Scenery_part::C_TEXTURE_SHEET, _bake_uvs_array, tmp_scenery_part.sprite, index);
				}

			}
		}
		_uvs_scenery_buffer[h]->send(_bake_uvs_array, C_SIZE * C_SIZE * 16);
	}
}

void Chunk::unbake()
{
	_baked = false;
	for (jgl::Size_t i = 0; i < 3; i++)
	{
		for (jgl::Size_t j = 0; j < 3; j++)
		{
			_neightbour_chunks[i][j] = nullptr;
		}
	}
}

void Chunk::bake(const Map* p_map)
{
	rebake(p_map);

	for (jgl::Size_t i = 0; i < 3; i++)
		for (jgl::Size_t j = 0; j < 3; j++)
		{
			if (_neightbour_chunks[i][j] != nullptr && _neightbour_chunks[i][j] != this)
			{
				_neightbour_chunks[i][j]->rebake(p_map);
			}
		}
}

void Chunk::rebake(const Map* p_map)
{
	if (_chunk_shader == nullptr)
		_chunk_shader = jgl::Application::active_application()->shader("Chunk_shader");

	if (_point_buffer == nullptr || _element_buffer == nullptr || _points_baked == false)
	{
		_bake_points();
	}

	_compose_neightbour_chunk(p_map);

	_bake_nodes(p_map);

	_bake_sceneries(p_map);

	_baked = true;
}

void Chunk::_render_nodes(jgl::Vector3& p_delta_pos, jgl::Float p_depth)
{
	if (_chunk_shader == nullptr)
		_chunk_shader = jgl::Application::active_application()->shader("Chunk_shader");
	//Texture activation
	World_object::Node::C_TEXTURE_SHEET->activate();

	_point_buffer->activate();
	_element_buffer->activate();
	_uvs_node_buffer->activate();

	p_delta_pos.z = static_cast<jgl::Float>(p_depth) / 10000.0f;
	if (_position_uniform == nullptr)
		_position_uniform = _chunk_shader->uniform("delta_pos");
	if (_texture_uniform == nullptr)
		_texture_uniform = _chunk_shader->uniform("textureID");
	_position_uniform->send(p_delta_pos);
	_texture_uniform->send(0);

	_chunk_shader->cast(jgl::Shader::Mode::Triangle, _element_buffer->size() / sizeof(jgl::Uint));

	//Texture desactivation
	World_object::Node::C_TEXTURE_SHEET->desactivate();
}

void Chunk::_render_sceneries(jgl::Vector3& p_delta_pos, jgl::Int p_level, jgl::Float p_depth)
{
	if (_chunk_shader == nullptr)
		_chunk_shader = jgl::Application::active_application()->shader("Chunk_shader");
	//Texture activation
	World_object::Scenery_part::C_TEXTURE_SHEET->activate();

	_point_buffer->activate();
	_element_buffer->activate();
	_uvs_scenery_buffer[p_level]->activate();

	p_delta_pos.z = static_cast<jgl::Float>(p_level + p_depth) / 10000.0f;
	if (_position_uniform == nullptr)
		_position_uniform = _chunk_shader->uniform("delta_pos");
	if (_texture_uniform == nullptr)
		_texture_uniform = _chunk_shader->uniform("textureID");
	_position_uniform->send(p_delta_pos);
	_texture_uniform->send(0);

	_chunk_shader->cast(jgl::Shader::Mode::Triangle, _element_buffer->size() / sizeof(jgl::Uint));

	//Texture desactivation
	World_object::Scenery_part::C_TEXTURE_SHEET->desactivate();

}

void Chunk::render(jgl::Float p_depth)
{
	if (_baked == false || _points_baked == false)
		return;

	jgl::Vector2Int tmp_world_pos = Main_application::instance()->convert_world_to_screen(_pos * C_SIZE);

	jgl::Vector2 delta_pos_2D = jgl::convert_screen_to_opengl(tmp_world_pos);

	jgl::Vector3 delta_pos = jgl::Vector3(delta_pos_2D.x, delta_pos_2D.y, 0);

	if (_chunk_shader == nullptr)
		_chunk_shader = jgl::Application::active_application()->shader("Chunk_shader");

	_chunk_shader->activate();

	//Render nodes
	_render_nodes(delta_pos, p_depth - 1);

	//Render sceneries under player foot
	for (jgl::Int i = 0; i < 3; i++)
	{
		_render_sceneries(delta_pos, i, p_depth);
	}

	//Render sceneries over player foot
	for (jgl::Int i = 3; i < C_NB_LAYER; i++)
	{
		_render_sceneries(delta_pos, i, p_depth + 1);
	}
}