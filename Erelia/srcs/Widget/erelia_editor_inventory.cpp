#include "erelia.h"

typedef Editor_inventory::Inventory_item_type Item_type;

void Editor_inventory::_render()
{
	_box.render();

	if (_pages.size() > _index && _pages[_index].size != 0)
	{
		_pages[_index].texture->draw(_anchor + _incrustation_frame->anchor(), _incrustation_frame->area(), _pages[_index].unit * _page_anchor, _nb_element_on_screen * _pages[_index].unit - 0.0001f, _depth + 10, 1.0f);
	}
}

void Editor_inventory::_on_geometry_change()
{
	_box.set_geometry(_anchor, _area, _depth);

	jgl::Int button_size = _area.x / 6;
	if (button_size > 45)
		button_size = 45;
	_previous_page_button->set_geometry(10, button_size);
	_next_page_button->set_geometry(jgl::Vector2Int(_area.x - 10 - button_size, 10), button_size);
	_page_label->set_geometry(jgl::Vector2Int(10 + button_size + 5, 10), jgl::Vector2Int(_area.x - (10 + button_size + 5) * 2, button_size));

	_incrustation_frame->set_geometry(_previous_page_button->anchor() + jgl::Vector2Int(0, button_size + 5), _area - jgl::Vector2Int(20, 20 + button_size + 5));

	_elem_size = _incrustation_frame->area().x / _line_length;
	_nb_element_on_screen = _incrustation_frame->area() / _elem_size;
	for (jgl::Size_t i = 0; i < _pages.size(); i++)
	{
		_pages[i].calc_unit();
	}
}

jgl::Bool Editor_inventory::_update()
{
	if (jgl::Application::active_application()->mouse().wheel() != 0)
	{
		if (jgl::Application::active_application()->mouse().wheel() > 0 && _page_anchor.y > 0)
			_page_anchor.y--;
		else if (jgl::Application::active_application()->mouse().wheel() < 0 && _nb_element_on_screen.y < (_pages[_index].size.y - _page_anchor.y))
			_page_anchor.y++;
	}
	if (jgl::Application::active_application()->mouse().get_button(jgl::Mouse_button::Left) == jgl::Input_status::Release && _incrustation_frame->is_pointed() == true)
	{
		jgl::Vector2Int tmp_pos = (jgl::Application::active_application()->mouse().pos() - _incrustation_frame->anchor()) / _elem_size + _page_anchor;
		if (_pages[_index].map.count(tmp_pos) != 0)
		{
			_selected_item = _pages[_index].map[tmp_pos];
		}
	}
	return (false);
}

jgl::Bool Editor_inventory::_fixed_update()
{
	return (false);
}


void Editor_inventory::_compose_forest_page()
{
	Inventory_page new_page = Inventory_page("Foret");

	new_page.add_item(jgl::Vector2Int(0, 0), Editor_inventory::Inventory_item(Item_type::Node, 0));
	new_page.add_item(jgl::Vector2Int(7, 3), Editor_inventory::Inventory_item(Item_type::Node, 1));
	_pages.push_back(new_page);
}
void Editor_inventory::_compose_cave_page()
{
	Inventory_page new_page = Inventory_page("Grotte");

	_pages.push_back(new_page);
}
void Editor_inventory::_compose_desert_page()
{
	Inventory_page new_page = Inventory_page("Desert");

	_pages.push_back(new_page);
}

void Editor_inventory::_compose_faerie_page()
{
	Inventory_page new_page = Inventory_page("Foret magique");

	_pages.push_back(new_page);
}

void Editor_inventory::_compose_urban_page()
{
	Inventory_page new_page = Inventory_page("Urbain");

	_pages.push_back(new_page);
}
void Editor_inventory::_compose_ruins_page()
{
	Inventory_page new_page = Inventory_page("Ruines");

	_pages.push_back(new_page);
}
void Editor_inventory::_compose_housing_page()
{
	Inventory_page new_page = Inventory_page("Housing");

	_pages.push_back(new_page);
}

void Editor_inventory::_compose_walls_page()
{
	Inventory_page new_page = Inventory_page("Mur");

	_pages.push_back(new_page);
}

void Editor_inventory::_compose_all_page()
{
	Inventory_page new_page = Inventory_page("Tout");

	jgl::Int line = -1;

	for (jgl::Size_t i = 0; i < World_object::g_node_array.size(); i++)
	{
		if (i % _line_length == 0)
			line++;
		new_page.add_item(jgl::Vector2Int(i % _line_length, line), Editor_inventory::Inventory_item(Item_type::Node, i));
	}
	line++;

	jgl::Int nb_printed = 0;
	for (jgl::Size_t delta = 0; delta < 4; delta++)
	{
		for (jgl::Size_t i = 0; i < 4; i++)
		{
			line++;
			for (jgl::Size_t j = 0; j < _line_length; j++)
			{
				new_page.add_item(jgl::Vector2Int(j % _line_length, line), Editor_inventory::Inventory_item(Item_type::Scenery_part, (i * World_object::Scenery_part::C_TEXTURE_SIZE.x + delta * _line_length) + j));
				nb_printed++;
			}
		}
	}
	for (jgl::Size_t delta = 0; delta < 4; delta++)
	{
		for (jgl::Size_t i = 0; i < 4; i++)
		{
			line++;
			for (jgl::Size_t j = 0; j < _line_length; j++)
			{
				new_page.add_item(jgl::Vector2Int(j % _line_length, line), Editor_inventory::Inventory_item(Item_type::Scenery_part, ((i + 4) * World_object::Scenery_part::C_TEXTURE_SIZE.x + delta * _line_length) + j));
				nb_printed++;
			}
		}
	}
	line++;

	for (jgl::Size_t coll = 0; coll < 4; coll++)
	{
		for (jgl::Size_t l = 18; l < 41; l++)
		{
			for (jgl::Size_t i = 0; i < 8; i++)
			{
				new_page.add_item(jgl::Vector2Int(i, line), Editor_inventory::Inventory_item(Item_type::Scenery_part, World_object::Scenery_part::C_TEXTURE_SIZE.x * l + coll * _line_length + i));
			}
			line++;
		}
	}

	_pages.push_back(new_page);
}

void Editor_inventory::_set_selected_page(jgl::Int p_page)
{
	if (_pages.size() == 0)
		return;

	if (p_page < 0)
		_index = _pages.size() - 1;
	else if (p_page >= _pages.size())
		_index = 0;
	else
		_index = p_page;

	_page_anchor = 0;
	_page_label->label().set_text(_pages[_index].name);
}

Editor_inventory::Editor_inventory(jgl::Widget* p_parent) : jgl::Widget(p_parent)
{
	_box = jgl::Widget_component::Box(this);
	_box.set_background_texture(Main_application::instance()->editor_frame_sprite_sheet);
	_box.set_angle_size(32);

	_previous_page_button = new jgl::Button([&](jgl::Data_contener p_param) {_set_selected_page(_index - 1); }, jgl::Data_contener(), this);
	_previous_page_button->label().set_text("<");
	_previous_page_button->activate();

	_next_page_button = new jgl::Button([&](jgl::Data_contener p_param) {_set_selected_page(_index + 1); }, jgl::Data_contener(), this);
	_next_page_button->label().set_text(">");
	_next_page_button->activate();

	_page_label = new jgl::Text_label("Undefined", this);
	_page_label->box().set_front_color(_previous_page_button->unselected_box().front_color());
	_page_label->box().set_back_color(_previous_page_button->unselected_box().back_color());
	_page_label->label().set_horizontal_align(jgl::Horizontal_alignment::Centred);
	_page_label->label().set_vertical_align(jgl::Vertical_alignment::Centred);
	_page_label->activate();

	_incrustation_frame = new jgl::Frame(jgl::Color(0, 0, 0, 0), jgl::Color(0, 0, 0, 0), this);
	_incrustation_frame->activate();

	_compose_forest_page();
	_compose_cave_page();
	_compose_urban_page();
	_compose_ruins_page();
	_compose_desert_page();
	_compose_faerie_page();
	_compose_housing_page();
	_compose_walls_page();
	_compose_all_page();
	
	_set_selected_page(0);

	for (jgl::Size_t i = 0; i < _pages.size(); i++)
	{
		_pages[i].compute();
	}
}