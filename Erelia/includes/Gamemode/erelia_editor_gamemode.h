#pragma once

#include "erelia_gamemode.h"

#include "widget/erelia_entity_renderer.h"
#include "widget/erelia_entity_updater.h"
#include "widget/erelia_map_renderer.h"
#include "widget/erelia_player_controller.h"

#include "widget/erelia_editor_interact_controller.h"

class Editor_gamemode : public Gamemode
{
private:
	Engine* _engine;

	Entity_renderer* _entity_renderer;
	Map_renderer* _map_renderer;
	Player_controller* _player_controller;
	Entity_updater* _entity_updater;
	Editor_interact_controller* _editor_interact_controller;

	void _render();
	void _on_geometry_change();

public:
	Editor_gamemode(Engine* p_engine, jgl::Widget* p_parent);
};