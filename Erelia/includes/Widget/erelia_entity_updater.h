#pragma once

#include "jgl.h"
#include "data/erelia_engine.h"

class Entity_updater : public jgl::Widget
{
private:
	Engine* _engine;

	void _on_geometry_change();

	void _render();

	bool _update();
	bool _fixed_update();

public:
	Entity_updater(Engine* p_engine, jgl::Widget* p_parent);
};
