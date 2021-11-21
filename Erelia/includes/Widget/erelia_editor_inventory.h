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

		Inventory_page(jgl::String p_name = "Undefined", jgl::Vector2Uint p_size = 0);
		void clear();
		void add_item(jgl::Vector2Uint p_pos, Inventory_item p_item);
		void calc_unit();
		void compute();
	};

	jgl::Vector2 _elem_size;
	jgl::Vector2 _nb_element_on_screen;
	jgl::Size_t _index;
	jgl::Vector2Int _selected_item_pos;
	jgl::Size_t _page_index_selected;
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