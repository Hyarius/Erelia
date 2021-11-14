#include "erelia.h"

Entity::Entity()
{
	_id = -1;
	_position = 0;
	_sprite = -1;
	_direction = Direction::South;
	_move_speed = 100u;
	_reset_motion_data();
}

void Entity::_reset_motion_data()
{
	_ticks_left = 0;
	_destination = _position;
	_movement = 0;
}

bool Entity::is_in_motion()
{
	return (_ticks_left != 0);
}

void Entity::update_position(jgl::Ulong p_delta_tick)
{
	if (_ticks_left > p_delta_tick)
	{
		_position += _movement * p_delta_tick;
		_ticks_left -= p_delta_tick;
	}
	else
	{
		_position = _destination;
		_reset_motion_data();
	}
}

void Entity::move(jgl::Vector2Int p_delta_pos)
{
	_destination = _position + p_delta_pos;
	_movement = jgl::Vector2(p_delta_pos) / _move_speed;
	_ticks_left = _move_speed;
}

void Entity::place(jgl::Vector2Int p_position)
{
	_position = p_position;
	_reset_motion_data();
}