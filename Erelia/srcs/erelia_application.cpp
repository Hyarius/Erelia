#include "erelia.h"

Main_application* Main_application::_instance = nullptr;
jgl::Sprite_sheet* Main_application::unselected_button_sprite_sheet = nullptr;
jgl::Sprite_sheet* Main_application::selected_button_sprite_sheet = nullptr;
jgl::Sprite_sheet* Main_application::editor_frame_sprite_sheet = nullptr;
jgl::Sprite_sheet* Main_application::open_slider_sprite_sheet = nullptr;
jgl::Sprite_sheet* Main_application::close_slider_sprite_sheet = nullptr;

void Main_application::_on_geometry_change()
{
	_editor_gamemode->set_geometry(_anchor, _area);
	_engine->rebake();
}

void Main_application::_render()
{

}

bool Main_application::_update()
{
	return (false);
}

bool Main_application::_fixed_update()
{
	return (false);
}

Main_application* Main_application::instance()
{
	return (_instance);
}

void Main_application::set_instance(Main_application* p_app)
{
	_instance = p_app;
}

jgl::Vector2Int Main_application::convert_world_to_screen(jgl::Vector2 p_pos)
{
	jgl::Vector2 player_pos = _engine->player()->position();

	jgl::Vector2 result = p_pos;

	result -= 0.5f;
	result -= player_pos;
	result *= World_object::Node::C_SIZE;
	result += jgl::Application::active_application()->size() / 2;

	return (result);
}

jgl::Vector2 Main_application::convert_screen_to_world(jgl::Vector2Int p_pos)
{
	jgl::Vector2 player_pos = _engine->player()->position();
	
	jgl::Vector2 result = p_pos;

	result -= jgl::Application::active_application()->size() / 2;
	result /= World_object::Node::C_SIZE;
	result += player_pos;
	result += 0.5f;

	if (result.x < 0)
		result.x--;
	if (result.y < 0)
		result.y--;
	return (result);
}

Main_application::Main_application(jgl::Widget* p_parent) : jgl::Widget(p_parent),
	_engine(nullptr)
{
	World_object::Node::C_TEXTURE_SHEET = new jgl::Sprite_sheet("ressource/texture/tile_sheet.png", World_object::Node::C_TEXTURE_SIZE);
	World_object::Scenery::C_TEXTURE_SHEET = new jgl::Sprite_sheet("ressource/texture/scenery_sheet.png", World_object::Scenery::C_TEXTURE_SIZE);
	World_object::Scenery_part::C_TEXTURE_SHEET = new jgl::Sprite_sheet("ressource/texture/scenery_part_sheet.png", World_object::Scenery_part::C_TEXTURE_SIZE);
	
	if (editor_frame_sprite_sheet == nullptr)
		editor_frame_sprite_sheet = new jgl::Sprite_sheet("ressource/UI_texture/editor_frame.png", 3);
	if (unselected_button_sprite_sheet == nullptr)
		unselected_button_sprite_sheet = new jgl::Sprite_sheet("ressource/UI_texture/basic_frame.png", 3);
	if (selected_button_sprite_sheet == nullptr)
		selected_button_sprite_sheet = new jgl::Sprite_sheet("ressource/UI_texture/basic_frame_pressed.png", 3);
	if (open_slider_sprite_sheet == nullptr)
		open_slider_sprite_sheet = new jgl::Sprite_sheet("ressource/UI_texture/open_slider.png", 3);
	if (close_slider_sprite_sheet == nullptr)
		close_slider_sprite_sheet = new jgl::Sprite_sheet("ressource/UI_texture/close_slider.png", 3);

	_engine = new Engine();

	_editor_gamemode = new Editor_gamemode(_engine, this);
	_editor_gamemode->activate();

	set_instance(this);
}