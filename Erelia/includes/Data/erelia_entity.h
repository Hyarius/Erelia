#pragma once

class Entity
{
public:
	enum class Direction : unsigned char
	{
		South = 0,
		East = 1,
		West = 2,
		North = 3
	};

protected:
	//Information data
	jgl::Long _id;
	jgl::Vector2 _position;
	jgl::Vector2 _sprite;
	Direction _direction;
	jgl::Ulong _move_speed;

	//Motion data
	jgl::Ulong _ticks_left;
	jgl::Vector2 _destination;
	jgl::Vector2 _movement;
	void _reset_motion_data();

public:
	Entity();

	bool is_in_motion();
	void update_position(jgl::Ulong p_delta_tick);

	void move(jgl::Vector2Int p_delta_pos);
	void place(jgl::Vector2Int p_delta_pos);

	void set_id(jgl::Long p_id) { _id = p_id; }
	void set_position(jgl::Vector2 p_position) { _position = p_position; }
	void set_sprite(jgl::Vector2 p_sprite) { _sprite = p_sprite; }
	void set_direction(Direction p_direction) { _direction = p_direction; }

	jgl::Long id() { return (_id); }
	jgl::Vector2 position() { return (_position); }
	jgl::Vector2 sprite() { return (_sprite); }
	Direction direction() { return (_direction); }
};