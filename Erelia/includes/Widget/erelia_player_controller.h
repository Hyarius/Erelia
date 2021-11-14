#pragma once

#include "jgl.h"

#include "data/erelia_player.h"

class Player_controller : public jgl::Widget
{
private:
	Engine* _engine;
	Player* _player;

	void _on_geometry_change();
	void _render();

	bool _update();
	bool _fixed_update();

public:
	Player_controller(Engine* p_engine, jgl::Widget* p_parent = nullptr);
};
