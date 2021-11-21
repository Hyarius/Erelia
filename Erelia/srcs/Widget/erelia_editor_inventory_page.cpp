#include "erelia.h"

Editor_inventory::Inventory_page::Inventory_page(jgl::String p_name, jgl::Vector2Uint p_size) :
	name(p_name), size(p_size), map(), unit(0), output(nullptr), texture(nullptr)
{

}
void Editor_inventory::Inventory_page::clear()
{
	map.clear();
	size = 0;
}
void Editor_inventory::Inventory_page::add_item(jgl::Vector2Uint p_pos, Inventory_item p_item)
{
	map[p_pos] = p_item;

	if (p_pos.x >= size.x)
		size.x = p_pos.x + 1;
	if (p_pos.y >= size.y)
		size.y = p_pos.y + 1;
}
void Editor_inventory::Inventory_page::calc_unit()
{
	if (size != 0)
		unit = jgl::Vector2(1, 1) / size;
	else
		unit = 1;
}
void Editor_inventory::Inventory_page::compute()
{
	static jgl::Vector2Uint elem_size = 32u;
	static jgl::Vector2Int tmp_delta_node[4] =
	{
		jgl::Vector2Int(0, 0),
		jgl::Vector2Int(0, 1),
		jgl::Vector2Int(1, 0),
		jgl::Vector2Int(1, 1)
	};
	jgl::Vector2Uint image_size = 0;

	image_size = size * elem_size;

	if (image_size.x != 0 && image_size.y != 0)
	{
		output = new jgl::Image_output(image_size);

		output->associate();

		for (auto tmp : map)
		{
			jgl::Vector2Uint pos = tmp.first;
			Inventory_item item = tmp.second;

			if (item.type == Inventory_item_type::Node)
			{
				for (jgl::Size_t i = 0; i < 4; i++)
					World_object::Node::C_TEXTURE_SHEET->draw(
						World_object::g_node_array[item.index].sprite + tmp_delta_node[i],
						pos * elem_size + tmp_delta_node[i] * (elem_size / 2),
						elem_size / 2,
						100,
						1.0f
					);
			}
			else if (item.type == Inventory_item_type::Scenery)
			{
				World_object::Scenery::C_TEXTURE_SHEET->draw(World_object::g_scenery_array[item.index].icon, pos * elem_size, elem_size, 100, 1.0f);
			}
			else if (item.type == Inventory_item_type::Scenery_part)
			{
				World_object::Scenery_part::C_TEXTURE_SHEET->draw(World_object::g_scenery_part_array[item.index].sprite, pos * elem_size, elem_size, 100, 1.0f);
			}
		}

		output->desassociate();
		texture = output->save();
	}
	
}