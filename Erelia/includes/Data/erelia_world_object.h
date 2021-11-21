#pragma once

#include "jgl.h"

namespace World_object
{
	struct Node
	{
		static jgl::Size_t C_SIZE;
		static jgl::Sprite_sheet* C_TEXTURE_SHEET;
		static const jgl::Vector2Uint C_TEXTURE_SIZE;

		jgl::String name;
		jgl::Size_t animation_size;
		jgl::Vector2Int sprite;
		jgl::Bool autotiled;
		jgl::Bool walkable;

		Node(jgl::String p_name = "Undefined", jgl::Size_t p_animation_size = 0, jgl::Vector2Int p_sprite = -1, jgl::Bool p_autotiled = false, jgl::Bool p_walkable = true)
		{
			name = p_name;
			animation_size = p_animation_size;
			sprite = p_sprite;
			autotiled = p_autotiled;
			walkable = p_walkable;
		}
		friend std::ostream& operator<<(std::ostream& os, const Node& other)
		{
			os << other.name << "[Anim : " << other.animation_size << "][Sprite : " << other.sprite << "]";
			return os;
		}
	};

	struct Scenery
	{
		static jgl::Sprite_sheet* C_TEXTURE_SHEET;
		static const jgl::Vector2Uint C_TEXTURE_SIZE;

		jgl::String name;
		jgl::Vector2Int icon;
		jgl::Uint base;
		jgl::Vector2Int size;
		jgl::Map<jgl::Vector2Int, jgl::Int> levels;

		Scenery(jgl::String p_name = "Undefined", jgl::Vector2Int p_icon = 0, jgl::Uint p_base = 0u, jgl::Vector2Int p_size = 1, jgl::Int **p_levels = nullptr)
		{
			name = p_name;
			icon = p_icon;
			base = p_base;
			size = p_size;
			if (p_levels == nullptr)
			{
				for (jgl::Size_t i = 0; i < size.x; i++)
					for (jgl::Size_t i = 0; i < size.y; i++)
					{

					}
			}
		}
		friend std::ostream& operator<<(std::ostream& os, const Scenery& other)
		{
			os << "[Item : " << other.name << "]";
			return os;
		}
	};

	struct Scenery_part
	{
		static jgl::Sprite_sheet* C_TEXTURE_SHEET;
		static const jgl::Vector2Uint C_TEXTURE_SIZE;
		jgl::Vector2Int sprite;
		jgl::Bool autotiled;
		jgl::Size_t animation_size;
		jgl::Bool obstacle;

		Scenery_part(jgl::Vector2Int p_sprite = 0, jgl::Bool p_autotiled = false, jgl::Bool p_obstacle = true, jgl::Size_t p_animation_size = 1)
		{
			autotiled = p_autotiled;
			sprite = p_sprite;
			obstacle = p_obstacle;
			animation_size = p_animation_size;
		}
		friend std::ostream& operator<<(std::ostream& os, const Scenery_part& other)
		{
			os << "Scenery part : " << other.sprite << "[" << other.animation_size << "]";
			return os;
		}
	};

	extern jgl::Array<Node> g_node_array;
	extern jgl::Array<Scenery> g_scenery_array;
	extern jgl::Array<Scenery_part> g_scenery_part_array;
};