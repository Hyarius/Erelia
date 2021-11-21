#pragma once

#include "jgl.h"

#include "data/erelia_engine.h"

#include "erelia_editor_inventory.h"

class Editor_interact_controller : public jgl::Widget
{
private:
	jgl::Vector2Int _slider_anchor;
	jgl::Vector2Int _frame_anchor;
	jgl::Vector2Int _raiser_anchor;
	jgl::Vector2Int _level_label_anchor;
	jgl::Vector2Int _reducer_anchor;

	jgl::Bool _in_motion;
	jgl::Vector2 _start_position;
	jgl::Vector2 _final_position;
	const jgl::Size_t _duration_time = 200u;
	jgl::Ulong _start_time;
	jgl::Ulong _final_time;

	std::function<void (jgl::Data_contener)> _function_open;
	std::function<void (jgl::Data_contener)> _function_close;

	jgl::Bool _placing_multiple_node;
	jgl::Vector2Int _start_placement_position;
	jgl::Vector2Int _end_placement_position;

	Engine* _engine;

	jgl::Button* _slider_button;
	Editor_inventory* _editor_inventory;

	jgl::Button* _reduce_level_button;
	jgl::Int _level;
	jgl::Text_label* _level_label;
	jgl::Button* _raise_level_button;

	void _render();
	void _on_geometry_change();
	jgl::Bool _update();
	jgl::Bool _fixed_update();

	void _set_level(jgl::Int p_level)
	{
		if (p_level == -1)
			_level = Chunk::C_NB_LAYER - 1;
		else if (p_level == Chunk::C_NB_LAYER)
			_level = 0;
		else
			_level = p_level;
		_level_label->label().set_text("Lvl : " + jgl::itoa(_level));
	}

	jgl::Bool _map_pointed();
	void _update_slider();
	void _use_item(jgl::Vector2Int p_pos);

public:
	Editor_interact_controller(Engine* p_engine, jgl::Widget* p_parent);

	void open_slider();
	void close_slider();
};