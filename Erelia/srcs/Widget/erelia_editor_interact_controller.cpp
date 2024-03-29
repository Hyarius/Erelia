#include "erelia.h"

void Editor_interact_controller::open_slider()
{
	_slider_button->define_action(_function_close, _slider_button->param());
	_start_position = 0;
	_final_position = jgl::Vector2Int(jgl::Application::active_application()->size().x / 4, 0);
	_start_time = jgl::Application::active_application()->time();
	_final_time = jgl::Application::active_application()->time() + _duration_time;
	_slider_button->unselected_box().set_background_texture(Main_application::instance()->close_slider_sprite_sheet);
	_slider_button->selected_box().set_background_texture(Main_application::instance()->close_slider_sprite_sheet);
	_in_motion = true;
}

void Editor_interact_controller::close_slider()
{
	_slider_button->define_action(_function_open, _slider_button->param());
	_start_position = jgl::Vector2Int(jgl::Application::active_application()->size().x / 4, 0);
	_final_position = 0;
	_start_time = jgl::Application::active_application()->time();
	_final_time = jgl::Application::active_application()->time() + _duration_time;
	_slider_button->unselected_box().set_background_texture(Main_application::instance()->open_slider_sprite_sheet);
	_slider_button->selected_box().set_background_texture(Main_application::instance()->open_slider_sprite_sheet);
	_in_motion = true;
}

void Editor_interact_controller::_render()
{
	if (_placing_multiple_node == true)
	{
		jgl::Vector2Int tmp_placement = Main_application::instance()->convert_screen_to_world(jgl::Application::active_application()->mouse().pos());

		jgl::Vector2Int start = jgl::Vector2Int(
			(_start_placement_position.x < tmp_placement.x ? _start_placement_position.x : tmp_placement.x),
			(_start_placement_position.y < tmp_placement.y ? _start_placement_position.y : tmp_placement.y)
		);
		jgl::Vector2Int end = jgl::Vector2Int(
			(_start_placement_position.x > tmp_placement.x ? _start_placement_position.x : tmp_placement.x),
			(_start_placement_position.y > tmp_placement.y ? _start_placement_position.y : tmp_placement.y)
		) + 1;

		jgl::Vector2Int start_pos = Main_application::instance()->convert_world_to_screen(start);
		jgl::Vector2Int end_pos = Main_application::instance()->convert_world_to_screen(end);

		jgl::Vector2Int size = end_pos - start_pos + 1;

		jgl::draw_rectangle_color(jgl::Color(255, 255, 255, 100), start_pos, size, _depth - 1);
	}
}

void Editor_interact_controller::_on_geometry_change()
{
	_viewport->reset();

	_slider_anchor = jgl::Vector2Int(0, 60);
	_slider_button->set_geometry(_slider_anchor, 50);

	_frame_anchor = jgl::Vector2Int(-jgl::Application::active_application()->size().x / 4, 0);
	_editor_inventory->set_geometry(
		_frame_anchor,
		jgl::Vector2Int(jgl::Application::active_application()->size().x / 4, jgl::Application::active_application()->size().y)
	);

	_raiser_anchor = jgl::Vector2Int(105, 5);
	_level_label_anchor = jgl::Vector2Int(35, 5);
	_reducer_anchor = jgl::Vector2Int(5, 5);

	_reduce_level_button->set_geometry(_reducer_anchor, jgl::Vector2Int(25, 50));
	_reduce_level_button->label().set_text_size(_reduce_level_button->label().text_size() / 2);

	_level_label->set_geometry(_level_label_anchor, jgl::Vector2Int(_raiser_anchor.x - _level_label_anchor.x - 5, 50));

	_raise_level_button->set_geometry(_raiser_anchor, jgl::Vector2Int(25, 50));
	_raise_level_button->label().set_text_size(_raise_level_button->label().text_size() / 2);

	_slider_button->define_action(_function_open, _slider_button->param());
	_slider_button->unselected_box().set_background_texture(Main_application::instance()->open_slider_sprite_sheet);
	_slider_button->selected_box().set_background_texture(Main_application::instance()->open_slider_sprite_sheet);
}

void Editor_interact_controller::_use_item(jgl::Vector2Int p_pos)
{
	Editor_inventory::Inventory_item tmp_item = _editor_inventory->selected_item();

	if (tmp_item.type == Editor_inventory::Inventory_item_type::Node)
	{
		_engine->place_node(p_pos, tmp_item.index);
	}
	else if (tmp_item.type == Editor_inventory::Inventory_item_type::Scenery)
	{
		_engine->place_scenery(p_pos, _level, tmp_item.index);
	}
	else if (tmp_item.type == Editor_inventory::Inventory_item_type::Scenery_part)
	{
		_engine->place_scenery(p_pos, _level, tmp_item.index);
	}
}

void Editor_interact_controller::_update_slider()
{
	jgl::Ulong actual_duration = jgl::Application::active_application()->time() - _start_time;

	jgl::Vector2 position = jgl::lerp<jgl::Vector2>(_start_position, _final_position, actual_duration, _duration_time);
	_slider_button->set_geometry(_slider_anchor + position, _slider_button->area());

	_editor_inventory->set_geometry(_frame_anchor + position, _editor_inventory->area());

	_reduce_level_button->set_geometry(_reducer_anchor + position, _reduce_level_button->area());
	_reduce_level_button->label().set_text_size(_reduce_level_button->label().text_size() / 2);

	_level_label->set_geometry(_level_label_anchor + position, _level_label->area());

	_raise_level_button->set_geometry(_raiser_anchor + position, _raise_level_button->area());
	_raise_level_button->label().set_text_size(_reduce_level_button->label().text_size() / 2);

	if (actual_duration >= _duration_time)
		_in_motion = false;
}


jgl::Bool Editor_interact_controller::_map_pointed()
{
	if (_raise_level_button->is_pointed() == true ||
		_level_label->is_pointed() == true ||
		_reduce_level_button->is_pointed() == true ||
		_slider_button->is_pointed() == true ||
		_editor_inventory->is_pointed() == true)
		return (false);
	return (true);
}

jgl::Bool Editor_interact_controller::_update()
{

	if (_in_motion == true)
	{
		_update_slider();
	}

	if (_map_pointed() == true)
	{
		if (jgl::Application::active_application()->mouse().get_button(jgl::Mouse_button::Left) == jgl::Input_status::Pressed)
		{
			_start_placement_position = Main_application::instance()->convert_screen_to_world(jgl::Application::active_application()->mouse().pos());
			_placing_multiple_node = true;
		}
		if (jgl::Application::active_application()->mouse().get_button(jgl::Mouse_button::Left) == jgl::Input_status::Release)
		{
			_end_placement_position = Main_application::instance()->convert_screen_to_world(jgl::Application::active_application()->mouse().pos());
			
			jgl::Vector2Int start = jgl::Vector2Int(
				(_start_placement_position.x < _end_placement_position.x ? _start_placement_position.x : _end_placement_position.x),
				(_start_placement_position.y < _end_placement_position.y ? _start_placement_position.y : _end_placement_position.y)
				);
			jgl::Vector2Int end = jgl::Vector2Int(
				(_start_placement_position.x > _end_placement_position.x ? _start_placement_position.x : _end_placement_position.x),
				(_start_placement_position.y > _end_placement_position.y ? _start_placement_position.y : _end_placement_position.y)
			);

			for (jgl::Int x = start.x; x <= end.x; x++)
				for (jgl::Int y = start.y; y <= end.y; y++)
				{
					_use_item(jgl::Vector2Int(x, y));
				}

		}
		if (jgl::Application::active_application()->mouse().get_button(jgl::Mouse_button::Right) == jgl::Input_status::Down)
		{
			jgl::Vector2Int tmp_pos = Main_application::instance()->convert_screen_to_world(jgl::Application::active_application()->mouse().pos());

			_engine->place_scenery(tmp_pos, _level, -1);
		}
	}

	if (jgl::Application::active_application()->mouse().get_button(jgl::Mouse_button::Left) == jgl::Input_status::Up)
		_placing_multiple_node = false;

	if (jgl::Application::active_application()->keyboard().get_key(jgl::Key::F7) == jgl::Input_status::Release)
	{
		_engine->map()->save();
	}

	return (false);
}

jgl::Bool Editor_interact_controller::_fixed_update()
{
	return (false);
}

Editor_interact_controller::Editor_interact_controller(Engine* p_engine, jgl::Widget* p_parent) : jgl::Widget(p_parent)
{
	_in_motion = false;
	_engine = p_engine;

	_function_open = [&](jgl::Data_contener p_param) {if (_final_time <= jgl::Application::active_application()->time())open_slider(); };
	_function_close = [&](jgl::Data_contener p_param) {if (_final_time <= jgl::Application::active_application()->time())close_slider(); };

	_slider_button = new jgl::Button(_function_open, jgl::Data_contener(), this);
	_slider_button->label().set_text("");
	_slider_button->unselected_box().set_background_texture(Main_application::instance()->open_slider_sprite_sheet);
	_slider_button->selected_box().set_background_texture(Main_application::instance()->open_slider_sprite_sheet);
	_slider_button->activate();

	_editor_inventory = new Editor_inventory(this);
	_editor_inventory->activate();

	_reduce_level_button = new jgl::Button([&](jgl::Data_contener p_param) {if (_level > 0)_set_level(_level - 1); }, jgl::Data_contener(), this);
	_reduce_level_button->label().set_text("<");
	_reduce_level_button->label().set_horizontal_align(jgl::Horizontal_alignment::Centred);
	_reduce_level_button->label().set_vertical_align(jgl::Vertical_alignment::Centred);
	_reduce_level_button->activate();

	_level_label = new jgl::Text_label("Level : X", this);
	_level_label->box().set_front_color(_reduce_level_button->unselected_box().front_color());
	_level_label->box().set_back_color(_reduce_level_button->unselected_box().back_color());
	_level_label->label().set_horizontal_align(jgl::Horizontal_alignment::Centred);
	_level_label->label().set_vertical_align(jgl::Vertical_alignment::Centred);
	_level_label->activate();

	_raise_level_button = new jgl::Button([&](jgl::Data_contener p_param) {if (_level < Chunk::C_NB_LAYER - 1)_set_level(_level + 1); }, jgl::Data_contener(), this);
	_raise_level_button->label().set_text(">");
	_raise_level_button->label().set_horizontal_align(jgl::Horizontal_alignment::Centred);
	_raise_level_button->label().set_vertical_align(jgl::Vertical_alignment::Centred);
	_raise_level_button->activate();

	_set_level(0);
}
