#include "erelia.h"

Entity_updater::Entity_updater(Engine* p_engine, jgl::Widget* p_parent) : jgl::Widget(p_parent)
{
	_engine = p_engine;
}

void Entity_updater::_on_geometry_change()
{

}

void Entity_updater::_render()
{

}

bool Entity_updater::_update()
{
	static jgl::Ulong last_tick = 0;
	jgl::Ulong actual_tick = jgl::Application::active_application()->time();

	if (last_tick == 0)
		last_tick = jgl::Application::active_application()->time();

	jgl::Ulong delta_tick = actual_tick - last_tick;

	for (auto tmp : _engine->entities())
	{
		if (tmp.second->is_in_motion() == true)
			tmp.second->update_position(delta_tick);
	}

	last_tick = actual_tick;
	return (false);
}

bool Entity_updater::_fixed_update()
{
	return (false);
}