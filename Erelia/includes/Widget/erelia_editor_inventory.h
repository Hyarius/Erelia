#pragma once

#include "jgl.h"

class Editor_inventory : public jgl::Widget
{
public:
	enum class Inventory_item_type
	{
		Error = -1,
		Node = 0,
		Scenery = 1,
		Scenery_part = 2
	};

	struct Inventory_item
	{
		Inventory_item_type type;
		jgl::Uint index;

		Inventory_item(Inventory_item_type p_type = Inventory_item_type::Error, jgl::Uint p_index = 0u)
		{
			type = p_type;
			index = p_index;
		}
	};

private:

	static const jgl::Size_t _line_length = 8u;

	jgl::Widget_component::Box _box;

	void _render();
	void _on_geometry_change();
	jgl::Bool _update();
	jgl::Bool _fixed_update();

	struct Inventory_page
	{
		jgl::String name;
		jgl::Vector2Uint size;
		jgl::Map<jgl::Vector2Uint, Inventory_item> map;
		jgl::Vector2 unit;
		jgl::Image_output* output;
		jgl::Image* texture;

		Inventory_page(jgl::String p_name = "Undefined", jgl::Vector2Uint p_size = 0) :
			name(p_name), size(p_size), map(), unit(0), output(nullptr), texture(nullptr)
		{
			
		}
		void clear()
		{
			map.clear();
			size = 0;
		}
		void add_item(jgl::Vector2Uint p_pos, Inventory_item p_item)
		{
			map[p_pos] = p_item;

			if (p_pos.x >= size.x)
				size.x = p_pos.x + 1;
			if (p_pos.y >= size.y)
				size.y = p_pos.y + 1;
		}
		void calc_unit()
		{
			if (size != 0)
				unit = jgl::Vector2(1, 1) / size;
			else
				unit = 1;
		}
		void compute()
		{
			static jgl::Vector2Uint elem_size = 32u;
			static jgl::Vector2Int tmp_delta_node[4] =
			{
				jgl::Vector2Int(0, 0),
				jgl::Vector2Int(0, 1),
				jgl::Vector2Int(1, 0),
				jgl::Vector2Int(1, 1)
			};
			jgl::Vector2Uint image_size = 0;

			image_size = size * elem_size;

			output = new jgl::Image_output(image_size);
			output->associate();

			for (auto tmp : map)
			{
				jgl::Vector2Uint pos = tmp.first;
				Inventory_item item = tmp.second;

				if (item.type == Inventory_item_type::Node)
				{
					for (jgl::Size_t i = 0; i < 4; i++)
						World_object::Node::C_TEXTURE_SHEET->draw(
							World_object::g_node_array[item.index].sprite + tmp_delta_node[i],
							pos * elem_size + tmp_delta_node[i] * (elem_size / 2),
							elem_size / 2,
							100,
							1.0f
						);
				}
				else if (item.type == Inventory_item_type::Scenery)
				{
					World_object::Scenery::C_TEXTURE_SHEET->draw(World_object::g_scenery_array[item.index].icon, pos * elem_size, elem_size, 100, 1.0f);
				}
				else if (item.type == Inventory_item_type::Scenery_part)
				{
					World_object::Scenery_part::C_TEXTURE_SHEET->draw(World_object::g_scenery_part_array[item.index].sprite, pos * elem_size, elem_size, 100, 1.0f);
				}
			}

			output->desassociate();
			texture = output->save();
		}
	};

	jgl::Vector2Int _elem_size;
	jgl::Vector2 _nb_element_on_screen;
	jgl::Size_t _index;
	jgl::Vector2Int _page_anchor;
	jgl::Array<Inventory_page> _pages;
	Inventory_item _selected_item;

	void _compose_forest_page();
	void _compose_cave_page();
	void _compose_desert_page();
	void _compose_faerie_page();
	void _compose_urban_page();
	void _compose_ruins_page();
	void _compose_housing_page();

	void _compose_walls_page();
	void _compose_all_page();

	jgl::Button* _previous_page_button;
	jgl::Button* _next_page_button;
	jgl::Text_label* _page_label;
	jgl::Frame* _incrustation_frame;

	void _set_selected_page(jgl::Int p_page);

public:
	Editor_inventory(jgl::Widget* p_parent);
	const Inventory_item& selected_item() const { return (_selected_item); }
};