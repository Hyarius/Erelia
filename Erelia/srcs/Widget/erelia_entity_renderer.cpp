#include "erelia.h"

void Entity_renderer::_on_geometry_change()
{

}

void Entity_renderer::_render()
{
	if (_engine->player() != nullptr)	
		jgl::draw_rectangle_color(jgl::Color(255, 0, 0), Main_application::instance()->convert_world_to_screen(_engine->player()->position()), World_object::Node::C_SIZE, _depth + 3);
}

bool Entity_renderer::_update()
{
	return (false);
}

bool Entity_renderer::_fixed_update()
{
	return (false);
}

Entity_renderer::Entity_renderer(Engine* p_engine, jgl::Widget* p_parent) : jgl::Widget(p_parent)
{
	_engine = p_engine;
}