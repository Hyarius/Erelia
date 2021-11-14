#include "erelia.h"

void Editor_gamemode::_render()
{

}

void Editor_gamemode::_on_geometry_change()
{
	_map_renderer->set_geometry(0, jgl::Application::active_application()->size());
	_entity_renderer->set_geometry(0, jgl::Application::active_application()->size());
	_player_controller->set_geometry(0, jgl::Application::active_application()->size());
	_entity_updater->set_geometry(0, jgl::Application::active_application()->size());
	_editor_interact_controller->set_geometry(0, jgl::Application::active_application()->size());
}

Editor_gamemode::Editor_gamemode(Engine* p_engine, jgl::Widget* p_parent) : Gamemode(p_parent)
{
	_engine = p_engine;

	_map_renderer = new Map_renderer(_engine->map(), this);
	_map_renderer->set_depth(10);
	_map_renderer->activate();

	_entity_renderer = new Entity_renderer(_engine, this);
	_entity_renderer->set_depth(20);
	_entity_renderer->activate();

	_player_controller = new Player_controller(_engine, this);
	_player_controller->set_depth(0);
	_player_controller->activate();

	_entity_updater = new Entity_updater(_engine, this);
	_entity_updater->set_depth(0);
	_entity_updater->activate();

	_editor_interact_controller = new Editor_interact_controller(_engine, this);
	_editor_interact_controller->set_depth(30);
	_editor_interact_controller->activate();
}