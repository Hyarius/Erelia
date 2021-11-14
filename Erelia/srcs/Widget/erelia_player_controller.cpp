#include "erelia.h"

void Player_controller::_on_geometry_change()
{

}

void Player_controller::_render()
{

}

bool Player_controller::_update()
{
	return (false);
}

bool Player_controller::_fixed_update()
{
	if (_player == nullptr)
		return false;

	jgl::Vector2Int delta_pos = 0;
	static jgl::Key direction_input[4] = { jgl::Key::Z, jgl::Key::S, jgl::Key::D, jgl::Key::Q };
	static jgl::Vector2 direction_value[4] = { jgl::Vector2(0, -1), jgl::Vector2(0, 1), jgl::Vector2(1, 0), jgl::Vector2(-1, 0) };

	for (jgl::Size_t i = 0; i < 4; i++)
	{
		if (_player->is_in_motion() == false &&
			jgl::Application::active_application()->keyboard().get_key(direction_input[i]) == jgl::Input_status::Down)
		{
			delta_pos += direction_value[i];
		}
	}
	if (delta_pos != 0)
	{
		_player->move(delta_pos);
	}

	return (false);
}

Player_controller::Player_controller(Engine* p_engine, jgl::Widget* p_parent) : jgl::Widget(p_parent)
{
	_engine = p_engine;
	_player = _engine->player();
}