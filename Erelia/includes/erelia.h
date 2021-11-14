#pragma once

#include "jgl.h"

#include "data/erelia_engine.h"

#include "Gamemode/erelia_editor_gamemode.h"

class Main_application : public jgl::Widget
{
private:
	Editor_gamemode* _editor_gamemode;

	//Data contener
	Engine* _engine;

	void _on_geometry_change();
	void _render();

	bool _update();
	bool _fixed_update();

	static Main_application* _instance;
public:
	static jgl::Sprite_sheet* editor_frame_sprite_sheet;
	static jgl::Sprite_sheet* unselected_button_sprite_sheet;
	static jgl::Sprite_sheet* selected_button_sprite_sheet;
	static jgl::Sprite_sheet* open_slider_sprite_sheet;
	static jgl::Sprite_sheet* close_slider_sprite_sheet;

	Main_application(jgl::Widget* p_parent = nullptr);

	static Main_application* instance();
	static void set_instance(Main_application* app);

	jgl::Vector2Int convert_world_to_screen(jgl::Vector2 p_pos);
	jgl::Vector2 convert_screen_to_world(jgl::Vector2Int p_pos);
};

extern Main_application* g_client_application;