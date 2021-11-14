#include "erelia.h"

const jgl::Vector2Uint World_object::Node::C_TEXTURE_SIZE = jgl::Vector2Uint(32, 24);
const jgl::Vector2Uint World_object::Scenery::C_TEXTURE_SIZE = jgl::Vector2Uint(32, 44);
const jgl::Vector2Uint World_object::Scenery_part::C_TEXTURE_SIZE = jgl::Vector2Uint(32, 44);

jgl::Size_t World_object::Node::C_SIZE = 32u;
jgl::Sprite_sheet* World_object::Node::C_TEXTURE_SHEET = nullptr;
jgl::Sprite_sheet* World_object::Scenery::C_TEXTURE_SHEET = nullptr;
jgl::Sprite_sheet* World_object::Scenery_part::C_TEXTURE_SHEET = nullptr;

jgl::Array<World_object::Node> World_object::g_node_array = {
	World_object::Node("Plain", 1, jgl::Vector2Int(0, 0), true, true),// 0
	World_object::Node("Forest", 1, jgl::Vector2Int(4, 0), true, true),// 1
	World_object::Node("Sand", 1, jgl::Vector2Int(8, 0), true, true),// 2
	World_object::Node("Dirt", 1, jgl::Vector2Int(12, 0), true, true),// 3
	World_object::Node("Cave floor", 1, jgl::Vector2Int(16, 0), true, true),// 4
	World_object::Node("Stone", 1, jgl::Vector2Int(20, 0), true, true),// 5
	World_object::Node("Dark stone", 1, jgl::Vector2Int(24, 0), true, true),// 6
	World_object::Node("Enchanted forest", 1, jgl::Vector2Int(28, 0), true, true),// 7
	World_object::Node("Dark cave floor", 1, jgl::Vector2Int(0, 6), true, true),// 8
	World_object::Node("Wooden floor", 1, jgl::Vector2Int(4, 6), true, true),// 9
	World_object::Node("Tiled floor", 1, jgl::Vector2Int(8, 6), true, true),// 10
	World_object::Node("Blue floor", 1, jgl::Vector2Int(12, 6), true, true),// 11
	World_object::Node("Wall interior", 1, jgl::Vector2Int(16, 6), true, false),// 12
	World_object::Node("Lava", 3, jgl::Vector2Int(20, 6), true, false),// 13
	World_object::Node("Water", 4, jgl::Vector2Int(0, 12), true, false),// 14
	World_object::Node("Deep water", 4, jgl::Vector2Int(16, 12), true, false),// 15
	World_object::Node("Dungeon floor - Purple", 1, jgl::Vector2Int(0, 18), true, true),// 16
	World_object::Node("Dungeon floor - Red", 1, jgl::Vector2Int(4, 18), true, true),// 17
	World_object::Node("Dungeon floor - Blue", 1, jgl::Vector2Int(8, 18), true, true),// 18
	World_object::Node("Dungeon floor - Green", 1, jgl::Vector2Int(12, 18), true, true),// 19
	World_object::Node("Dungeon floor - White", 1, jgl::Vector2Int(16, 18), true, true),// 20
	World_object::Node("Dungeon floor - Dark", 1, jgl::Vector2Int(20, 18), true, true),// 21
	World_object::Node("Dungeon floor - Brown", 1, jgl::Vector2Int(24, 18), true, true),// 22
	World_object::Node("Dungeon floor - Pink", 1, jgl::Vector2Int(28, 18), true, true),// 23
};

jgl::Array<World_object::Scenery> World_object::g_scenery_array = {
	World_object::Scenery("Green tree 1x1",				jgl::Vector2Int(0, 0), 576, jgl::Vector2Int(1, 1)),
	World_object::Scenery("Brown tree 1x1",				jgl::Vector2Int(1, 0), 577, jgl::Vector2Int(1, 1)),
	World_object::Scenery("Pink tree 1x1",				jgl::Vector2Int(2, 0), 578, jgl::Vector2Int(1, 1)),
	World_object::Scenery("Dark green tree 1x1",		jgl::Vector2Int(3, 0), 579, jgl::Vector2Int(1, 1)),
	World_object::Scenery("Light green tree 1x1",		jgl::Vector2Int(4, 0), 580, jgl::Vector2Int(1, 1)),
	World_object::Scenery("Blue tree 1x1",				jgl::Vector2Int(5, 0), 581, jgl::Vector2Int(1, 1)),
	World_object::Scenery("Purple tree 1x1",			jgl::Vector2Int(6, 0), 582, jgl::Vector2Int(1, 1)),
	World_object::Scenery("White tree 1x1",				jgl::Vector2Int(7, 0), 583, jgl::Vector2Int(1, 1)),

	World_object::Scenery("Green tree 1x2",				jgl::Vector2Int(0, 1), 640, jgl::Vector2Int(1, 2)),
	World_object::Scenery("Brown tree 1x2",				jgl::Vector2Int(1, 1), 641, jgl::Vector2Int(1, 2)),
	World_object::Scenery("Pink tree 1x2",				jgl::Vector2Int(2, 1), 642, jgl::Vector2Int(1, 2)),
	World_object::Scenery("Dark green tree 1x2",		jgl::Vector2Int(3, 1), 643, jgl::Vector2Int(1, 2)),
	World_object::Scenery("Light green tree 1x2",		jgl::Vector2Int(4, 1), 644, jgl::Vector2Int(1, 2)),
	World_object::Scenery("Blue tree 1x2",				jgl::Vector2Int(5, 1), 645, jgl::Vector2Int(1, 2)),
	World_object::Scenery("Purple tree 1x2",			jgl::Vector2Int(6, 1), 646, jgl::Vector2Int(1, 2)),
	World_object::Scenery("White tree 1x2",				jgl::Vector2Int(7, 1), 647, jgl::Vector2Int(1, 2)),

	World_object::Scenery("Green tree 2x2",				jgl::Vector2Int(0, 2), 704, jgl::Vector2Int(2, 2)),
	World_object::Scenery("Brown tree 2x2",				jgl::Vector2Int(1, 2), 706, jgl::Vector2Int(2, 2)),
	World_object::Scenery("Pink tree 2x2",				jgl::Vector2Int(2, 2), 708, jgl::Vector2Int(2, 2)),
	World_object::Scenery("Dark green tree 2x2",		jgl::Vector2Int(3, 2), 710, jgl::Vector2Int(2, 2)),
	World_object::Scenery("Light green tree 2x2",		jgl::Vector2Int(4, 2), 768, jgl::Vector2Int(2, 2)),
	World_object::Scenery("Blue tree 2x2",				jgl::Vector2Int(5, 2), 770, jgl::Vector2Int(2, 2)),
	World_object::Scenery("Purple tree 2x2",			jgl::Vector2Int(6, 2), 772, jgl::Vector2Int(2, 2)),
	World_object::Scenery("White tree 2x2",				jgl::Vector2Int(7, 2), 774, jgl::Vector2Int(2, 2)),

	World_object::Scenery("High green bush",			jgl::Vector2Int(0, 3), 592, jgl::Vector2Int(1, 1)),
	World_object::Scenery("High brown bush",			jgl::Vector2Int(1, 3), 593, jgl::Vector2Int(1, 1)),
	World_object::Scenery("High pink bush",				jgl::Vector2Int(2, 3), 594, jgl::Vector2Int(1, 1)),
	World_object::Scenery("High dark green bush",		jgl::Vector2Int(3, 3), 595, jgl::Vector2Int(1, 1)),
	World_object::Scenery("High light green bush",		jgl::Vector2Int(4, 3), 596, jgl::Vector2Int(1, 1)),
	World_object::Scenery("High blue bush",				jgl::Vector2Int(5, 3), 597, jgl::Vector2Int(1, 1)),
	World_object::Scenery("High purple bush",			jgl::Vector2Int(6, 3), 598, jgl::Vector2Int(1, 1)),
	World_object::Scenery("High white bush",			jgl::Vector2Int(7, 3), 599, jgl::Vector2Int(1, 1)),

	World_object::Scenery("Green herb 1x1 - 3",			jgl::Vector2Int(0, 4), 800, jgl::Vector2Int(1, 1)),
	World_object::Scenery("Brown herb 1x1 - 3",			jgl::Vector2Int(1, 4), 801, jgl::Vector2Int(1, 1)),
	World_object::Scenery("Pink herb 1x1 - 3",			jgl::Vector2Int(2, 4), 802, jgl::Vector2Int(1, 1)),
	World_object::Scenery("Dark green herb 1x1 - 3",	jgl::Vector2Int(3, 4), 803, jgl::Vector2Int(1, 1)),
	World_object::Scenery("Light green herb 1x1 - 3",	jgl::Vector2Int(4, 4), 804, jgl::Vector2Int(1, 1)),
	World_object::Scenery("Blue herb 1x1 - 3",			jgl::Vector2Int(5, 4), 805, jgl::Vector2Int(1, 1)),
	World_object::Scenery("Purple herb 1x1 - 3",		jgl::Vector2Int(6, 4), 806, jgl::Vector2Int(1, 1)),
	World_object::Scenery("White herb 1x1 - 3",			jgl::Vector2Int(7, 4), 807, jgl::Vector2Int(1, 1)),

	World_object::Scenery("Green herb 1x1 - 2",			jgl::Vector2Int(0, 5), 832, jgl::Vector2Int(1, 1)),
	World_object::Scenery("Brown herb 1x1 - 2",			jgl::Vector2Int(1, 5), 832 + 1, jgl::Vector2Int(1, 1)),
	World_object::Scenery("Pink herb 1x1 - 2",			jgl::Vector2Int(2, 5), 832 + 2, jgl::Vector2Int(1, 1)),
	World_object::Scenery("Dark green herb 1x1 - 2",	jgl::Vector2Int(3, 5), 832 + 3, jgl::Vector2Int(1, 1)),
	World_object::Scenery("Light green herb 1x1 - 2",	jgl::Vector2Int(4, 5), 832 + 4, jgl::Vector2Int(1, 1)),
	World_object::Scenery("Blue herb 1x1 - 2",			jgl::Vector2Int(5, 5), 832 + 5, jgl::Vector2Int(1, 1)),
	World_object::Scenery("Purple herb 1x1 - 2",		jgl::Vector2Int(6, 5), 832 + 6, jgl::Vector2Int(1, 1)),
	World_object::Scenery("White herb 1x1 - 2",			jgl::Vector2Int(7, 5), 832 + 7, jgl::Vector2Int(1, 1)),

	World_object::Scenery("Green herb 1x1 - 1",			jgl::Vector2Int(0, 6), 864, jgl::Vector2Int(1, 1)),
	World_object::Scenery("Brown herb 1x1 - 1",			jgl::Vector2Int(1, 6), 864 + 1, jgl::Vector2Int(1, 1)),
	World_object::Scenery("Pink herb 1x1 - 1",			jgl::Vector2Int(2, 6), 864 + 2, jgl::Vector2Int(1, 1)),
	World_object::Scenery("Dark green herb 1x1 - 1",	jgl::Vector2Int(3, 6), 864 + 3, jgl::Vector2Int(1, 1)),
	World_object::Scenery("Light green herb 1x1 - 1",	jgl::Vector2Int(4, 6), 864 + 4, jgl::Vector2Int(1, 1)),
	World_object::Scenery("Blue herb 1x1 - 1",			jgl::Vector2Int(5, 6), 864 + 5, jgl::Vector2Int(1, 1)),
	World_object::Scenery("Purple herb 1x1 - 1",		jgl::Vector2Int(6, 6), 864 + 6, jgl::Vector2Int(1, 1)),
	World_object::Scenery("White herb 1x1 - 1",			jgl::Vector2Int(7, 6), 864 + 7, jgl::Vector2Int(1, 1)),

	World_object::Scenery("Grey rock 1x1",				jgl::Vector2Int(8, 3), 896, jgl::Vector2Int(1, 1)),
	World_object::Scenery("Brown rock 1x1",				jgl::Vector2Int(9, 3), 896 + 1, jgl::Vector2Int(1, 1)),
	World_object::Scenery("Blue rock 1x1",				jgl::Vector2Int(10, 3), 896 + 2, jgl::Vector2Int(1, 1)),
	World_object::Scenery("Black rock 1x1",				jgl::Vector2Int(11, 3), 896 + 3, jgl::Vector2Int(1, 1)),

	World_object::Scenery("Grey mossy rock 1x1",		jgl::Vector2Int(12, 3), 896 + 4, jgl::Vector2Int(1, 1)),
	World_object::Scenery("Brown mossy rock 1x1",		jgl::Vector2Int(13, 3), 896 + 5, jgl::Vector2Int(1, 1)),
	World_object::Scenery("Blue mossy rock 1x1",		jgl::Vector2Int(14, 3), 896 + 6, jgl::Vector2Int(1, 1)),
	World_object::Scenery("Black mossy rock 1x1",		jgl::Vector2Int(15, 3), 896 + 7, jgl::Vector2Int(1, 1)),

	World_object::Scenery("Grey rock 1x2",				jgl::Vector2Int(8, 4), 928, jgl::Vector2Int(1, 2)),
	World_object::Scenery("Brown rock 1x2",				jgl::Vector2Int(9, 4), 928 + 1, jgl::Vector2Int(1, 2)),
	World_object::Scenery("Blue rock 1x2",				jgl::Vector2Int(10, 4), 928 + 2, jgl::Vector2Int(1, 2)),
	World_object::Scenery("Black rock 1x2",				jgl::Vector2Int(11, 4), 928 + 3, jgl::Vector2Int(1, 2)),

	World_object::Scenery("Grey rock 2x2",				jgl::Vector2Int(12, 4), 928 + 4, jgl::Vector2Int(2, 2)),
	World_object::Scenery("Brown rock 2x2",				jgl::Vector2Int(13, 4), 928 + 6, jgl::Vector2Int(2, 2)),

	World_object::Scenery("Fence - 1",					jgl::Vector2Int(0, 10), 1088, jgl::Vector2Int(1, 1)),
	World_object::Scenery("Fence - 2",					jgl::Vector2Int(1, 10), 1088 + 1, jgl::Vector2Int(1, 1)),
	World_object::Scenery("Fence - 3",					jgl::Vector2Int(2, 10), 1088 + 2, jgl::Vector2Int(1, 1)),

	World_object::Scenery("Trunk 1x1 - 1",				jgl::Vector2Int(3, 10), 1088 + 3, jgl::Vector2Int(1, 1)),
	World_object::Scenery("Trunk 1x1 - 2",				jgl::Vector2Int(4, 10), 1088 + 4, jgl::Vector2Int(1, 1)),
	World_object::Scenery("Trunk 1x1 - 3",				jgl::Vector2Int(5, 10), 1088 + 5, jgl::Vector2Int(1, 1)),
	World_object::Scenery("Trunk 2x1 - 1",				jgl::Vector2Int(6, 10), 1088 + 6, jgl::Vector2Int(2, 1)),

	World_object::Scenery("Trunk 2x2 - 1",				jgl::Vector2Int(7, 10), 1030, jgl::Vector2Int(2, 2)),

	World_object::Scenery("Green crystal 1x1 - 2",		jgl::Vector2Int(8, 0), 584, jgl::Vector2Int(1, 1)),
	World_object::Scenery("Brown crystal 1x1 - 2",		jgl::Vector2Int(9, 0), 584 + 1, jgl::Vector2Int(1, 1)),
	World_object::Scenery("Pink crystal 1x1 - 2",		jgl::Vector2Int(10, 0), 584 + 2, jgl::Vector2Int(1, 1)),
	World_object::Scenery("Dark green crystal 1x1 - 2",	jgl::Vector2Int(11, 0), 584 + 3, jgl::Vector2Int(1, 1)),
	World_object::Scenery("Light green crystal 1x1 - 2",jgl::Vector2Int(12, 0), 584 + 4, jgl::Vector2Int(1, 1)),
	World_object::Scenery("Blue crystal 1x1 - 2",		jgl::Vector2Int(13, 0), 584 + 5, jgl::Vector2Int(1, 1)),
	World_object::Scenery("Purple crystal 1x1 - 2",		jgl::Vector2Int(14, 0), 584 + 6, jgl::Vector2Int(1, 1)),
	World_object::Scenery("White crystal 1x1 - 2",		jgl::Vector2Int(15, 0), 584 + 7, jgl::Vector2Int(1, 1)),

	World_object::Scenery("Green crystal 1x2 - 2",		jgl::Vector2Int(8, 1), 648, jgl::Vector2Int(1, 2)),
	World_object::Scenery("Brown crystal 1x2 - 2",		jgl::Vector2Int(9, 1), 648 + 1, jgl::Vector2Int(1, 2)),
	World_object::Scenery("Pink crystal 1x2 - 2",		jgl::Vector2Int(10, 1), 648 + 2, jgl::Vector2Int(1, 2)),
	World_object::Scenery("Dark green crystal 1x2 - 2",	jgl::Vector2Int(11, 1), 648 + 3, jgl::Vector2Int(1, 2)),
	World_object::Scenery("Light green crystal 1x2 - 2",jgl::Vector2Int(12, 1), 648 + 4, jgl::Vector2Int(1, 2)),
	World_object::Scenery("Blue crystal 1x2 - 2",		jgl::Vector2Int(13, 1), 648 + 5, jgl::Vector2Int(1, 2)),
	World_object::Scenery("Purple crystal 1x2 - 2",		jgl::Vector2Int(14, 1), 648 + 6, jgl::Vector2Int(1, 2)),
	World_object::Scenery("White crystal 1x2 - 2",		jgl::Vector2Int(15, 1), 648 + 7, jgl::Vector2Int(1, 2)),

	World_object::Scenery("Green crystal 2x2",			jgl::Vector2Int(8, 2), 712, jgl::Vector2Int(2, 2)),
	World_object::Scenery("Brown crystal 2x2",			jgl::Vector2Int(9, 2), 714, jgl::Vector2Int(2, 2)),
	World_object::Scenery("Pink crystal 2x2",			jgl::Vector2Int(10, 2), 716, jgl::Vector2Int(2, 2)),
	World_object::Scenery("Dark green crystal 2x2",		jgl::Vector2Int(11, 2), 718, jgl::Vector2Int(2, 2)),
	World_object::Scenery("Light green crystal 2x2",	jgl::Vector2Int(12, 2), 776, jgl::Vector2Int(2, 2)),
	World_object::Scenery("Blue crystal 2x2",			jgl::Vector2Int(13, 2), 778, jgl::Vector2Int(2, 2)),
	World_object::Scenery("Purple crystal 2x2",			jgl::Vector2Int(14, 2), 780, jgl::Vector2Int(2, 2)),
	World_object::Scenery("White crystal 2x2",			jgl::Vector2Int(15, 2), 782, jgl::Vector2Int(2, 2)),

	World_object::Scenery("Bones 1x1 - 1",				jgl::Vector2Int(8, 5), 808, jgl::Vector2Int(1, 1)),
	World_object::Scenery("Bones 1x1 - 2",				jgl::Vector2Int(9, 5), 809, jgl::Vector2Int(1, 1)),
	World_object::Scenery("Bones 1x1 - 3",				jgl::Vector2Int(10, 5), 810, jgl::Vector2Int(1, 1)),
	World_object::Scenery("Bones 1x1 - 4",				jgl::Vector2Int(11, 5), 811, jgl::Vector2Int(1, 1)),

	World_object::Scenery("Statue 1x2 - 1",				jgl::Vector2Int(8, 6), 872, jgl::Vector2Int(1, 2)),
	World_object::Scenery("Statue 1x2 - 2",				jgl::Vector2Int(9, 6), 873, jgl::Vector2Int(1, 2)),
	World_object::Scenery("Statue 1x2 - 3",				jgl::Vector2Int(10, 6), 874, jgl::Vector2Int(1, 2)),
	World_object::Scenery("Statue 1x2 - 4",				jgl::Vector2Int(11, 6), 875, jgl::Vector2Int(1, 2)),

	World_object::Scenery("Cactus 1x1 - 2",				jgl::Vector2Int(12, 5), 812, jgl::Vector2Int(1, 1)),
	World_object::Scenery("Cactus 1x1 - 2",				jgl::Vector2Int(13, 5), 813, jgl::Vector2Int(1, 1)),
	World_object::Scenery("Cactus 1x1 - 3",				jgl::Vector2Int(14, 5), 814, jgl::Vector2Int(1, 1)),
	World_object::Scenery("Cactus 1x1 - 4",				jgl::Vector2Int(15, 5), 815, jgl::Vector2Int(1, 1)),

	World_object::Scenery("Cactus 1x2 - 1",				jgl::Vector2Int(12, 6), 876, jgl::Vector2Int(1, 2)),
	World_object::Scenery("Cactus 1x2 - 2",				jgl::Vector2Int(13, 6), 877, jgl::Vector2Int(1, 2)),
	World_object::Scenery("Cactus 1x2 - 3",				jgl::Vector2Int(14, 6), 878, jgl::Vector2Int(1, 2)),
	World_object::Scenery("Cactus 1x2 - 4",				jgl::Vector2Int(15, 6), 879, jgl::Vector2Int(1, 2)),

	World_object::Scenery("Torch on stick 1x2 - Red",	jgl::Vector2Int(0, 16), 1168, jgl::Vector2Int(1, 2)),
	World_object::Scenery("Torch on stick 1x2 - Green", jgl::Vector2Int(1, 16), 1172, jgl::Vector2Int(1, 2)),

	World_object::Scenery("Torch 1x1 - Red",			jgl::Vector2Int(2, 16), 1200, jgl::Vector2Int(1, 1)),
	World_object::Scenery("Torch 1x1 - Green",			jgl::Vector2Int(3, 16), 1232, jgl::Vector2Int(1, 1)),

	World_object::Scenery("Campfire 1x1 - Red",			jgl::Vector2Int(4, 16), 1204, jgl::Vector2Int(1, 1)),
	World_object::Scenery("Campfire 1x1 - Green",		jgl::Vector2Int(5, 16), 1236, jgl::Vector2Int(1, 1)),

};

jgl::Array<World_object::Scenery_part> World_object::g_scenery_part_array = {
	World_object::Scenery_part(jgl::Vector2Int( 0,  0),  false, true), // 	---- 0
	World_object::Scenery_part(jgl::Vector2Int( 1,  0),  false, true), // 1
	World_object::Scenery_part(jgl::Vector2Int( 2,  0),  false, true), // 2
	World_object::Scenery_part(jgl::Vector2Int( 3,  0),  false, true), // 3
	World_object::Scenery_part(jgl::Vector2Int( 4,  0),  false, true), // 4
	World_object::Scenery_part(jgl::Vector2Int( 5,  0),  false, true), // 5
	World_object::Scenery_part(jgl::Vector2Int( 6,  0),  false, true), // 6
	World_object::Scenery_part(jgl::Vector2Int( 7,  0),  false, true), // 7
	World_object::Scenery_part(jgl::Vector2Int( 8,  0),  false, true), // 8
	World_object::Scenery_part(jgl::Vector2Int( 9,  0),  false, true), // 9
	World_object::Scenery_part(jgl::Vector2Int(10,  0),  false, true), // -- 10
	World_object::Scenery_part(jgl::Vector2Int(11,  0),  false, true), // 11
	World_object::Scenery_part(jgl::Vector2Int(12,  0),  false, true), // 12
	World_object::Scenery_part(jgl::Vector2Int(13,  0),  false, true), // 13
	World_object::Scenery_part(jgl::Vector2Int(14,  0),  false, true), // 14
	World_object::Scenery_part(jgl::Vector2Int(15,  0),  false, true), // 15
	World_object::Scenery_part(jgl::Vector2Int(16,  0),  false, true), // 16
	World_object::Scenery_part(jgl::Vector2Int(17,  0),  false, true), // 17
	World_object::Scenery_part(jgl::Vector2Int(18,  0),  false, true), // 18
	World_object::Scenery_part(jgl::Vector2Int(19,  0),  false, true), // 19
	World_object::Scenery_part(jgl::Vector2Int(20,  0),  false, true), // -- 20
	World_object::Scenery_part(jgl::Vector2Int(21,  0),  false, true), // 21
	World_object::Scenery_part(jgl::Vector2Int(22,  0),  false, true), // 22
	World_object::Scenery_part(jgl::Vector2Int(23,  0),  false, true), // 23
	World_object::Scenery_part(jgl::Vector2Int(24,  0),  false, true), // 24
	World_object::Scenery_part(jgl::Vector2Int(25,  0),  false, true), // 25
	World_object::Scenery_part(jgl::Vector2Int(26,  0),  false, true), // 26
	World_object::Scenery_part(jgl::Vector2Int(27,  0),  false, true), // 27
	World_object::Scenery_part(jgl::Vector2Int(28,  0),  false, true), // 28
	World_object::Scenery_part(jgl::Vector2Int(29,  0),  false, true), // 29
	World_object::Scenery_part(jgl::Vector2Int(30,  0),  false, true), // -- 30
	World_object::Scenery_part(jgl::Vector2Int(31,  0),  false, true), // 31
	World_object::Scenery_part(jgl::Vector2Int( 0,  1),  false, true), // 32
	World_object::Scenery_part(jgl::Vector2Int( 1,  1),  false, true), // 33
	World_object::Scenery_part(jgl::Vector2Int( 2,  1),  false, true), // 34
	World_object::Scenery_part(jgl::Vector2Int( 3,  1),  false, true), // 35
	World_object::Scenery_part(jgl::Vector2Int( 4,  1),  false, true), // 36
	World_object::Scenery_part(jgl::Vector2Int( 5,  1),  false, true), // 37
	World_object::Scenery_part(jgl::Vector2Int( 6,  1),  false, true), // 38
	World_object::Scenery_part(jgl::Vector2Int( 7,  1),  false, true), // 39
	World_object::Scenery_part(jgl::Vector2Int( 8,  1),  false, true), // -- 40
	World_object::Scenery_part(jgl::Vector2Int( 9,  1),  false, true), // 41
	World_object::Scenery_part(jgl::Vector2Int(10,  1),  false, true), // 42
	World_object::Scenery_part(jgl::Vector2Int(11,  1),  false, true), // 43
	World_object::Scenery_part(jgl::Vector2Int(12,  1),  false, true), // 44
	World_object::Scenery_part(jgl::Vector2Int(13,  1),  false, true), // 45
	World_object::Scenery_part(jgl::Vector2Int(14,  1),  false, true), // 46
	World_object::Scenery_part(jgl::Vector2Int(15,  1),  false, true), // 47
	World_object::Scenery_part(jgl::Vector2Int(16,  1),  false, true), // 48
	World_object::Scenery_part(jgl::Vector2Int(17,  1),  false, true), // 49
	World_object::Scenery_part(jgl::Vector2Int(18,  1),  false, true), // -- 50
	World_object::Scenery_part(jgl::Vector2Int(19,  1),  false, true), // 51
	World_object::Scenery_part(jgl::Vector2Int(20,  1),  false, true), // 52
	World_object::Scenery_part(jgl::Vector2Int(21,  1),  false, true), // 53
	World_object::Scenery_part(jgl::Vector2Int(22,  1),  false, true), // 54
	World_object::Scenery_part(jgl::Vector2Int(23,  1),  false, true), // 55
	World_object::Scenery_part(jgl::Vector2Int(24,  1),  false, true), // 56
	World_object::Scenery_part(jgl::Vector2Int(25,  1),  false, true), // 57
	World_object::Scenery_part(jgl::Vector2Int(26,  1),  false, true), // 58
	World_object::Scenery_part(jgl::Vector2Int(27,  1),  false, true), // 59
	World_object::Scenery_part(jgl::Vector2Int(28,  1),  false, true), // -- 60
	World_object::Scenery_part(jgl::Vector2Int(29,  1),  false, true), // 61
	World_object::Scenery_part(jgl::Vector2Int(30,  1),  false, true), // 62
	World_object::Scenery_part(jgl::Vector2Int(31,  1),  false, true), // 63
	World_object::Scenery_part(jgl::Vector2Int( 0,  2),  false, true), // 64
	World_object::Scenery_part(jgl::Vector2Int( 1,  2),  false, true), // 65
	World_object::Scenery_part(jgl::Vector2Int( 2,  2),  false, true), // 66
	World_object::Scenery_part(jgl::Vector2Int( 3,  2),  false, true), // 67
	World_object::Scenery_part(jgl::Vector2Int( 4,  2),  false, true), // 68
	World_object::Scenery_part(jgl::Vector2Int( 5,  2),  false, true), // 69
	World_object::Scenery_part(jgl::Vector2Int( 6,  2),  false, true), // -- 70
	World_object::Scenery_part(jgl::Vector2Int( 7,  2),  false, true), // 71
	World_object::Scenery_part(jgl::Vector2Int( 8,  2),  false, true), // 72
	World_object::Scenery_part(jgl::Vector2Int( 9,  2),  false, true), // 73
	World_object::Scenery_part(jgl::Vector2Int(10,  2),  false, true), // 74
	World_object::Scenery_part(jgl::Vector2Int(11,  2),  false, true), // 75
	World_object::Scenery_part(jgl::Vector2Int(12,  2),  false, true), // 76
	World_object::Scenery_part(jgl::Vector2Int(13,  2),  false, true), // 77
	World_object::Scenery_part(jgl::Vector2Int(14,  2),  false, true), // 78
	World_object::Scenery_part(jgl::Vector2Int(15,  2),  false, true), // 79
	World_object::Scenery_part(jgl::Vector2Int(16,  2),  false, true), // -- 80
	World_object::Scenery_part(jgl::Vector2Int(17,  2),  false, true), // 81
	World_object::Scenery_part(jgl::Vector2Int(18,  2),  false, true), // 82
	World_object::Scenery_part(jgl::Vector2Int(19,  2),  false, true), // 83
	World_object::Scenery_part(jgl::Vector2Int(20,  2),  false, true), // 84
	World_object::Scenery_part(jgl::Vector2Int(21,  2),  false, true), // 85
	World_object::Scenery_part(jgl::Vector2Int(22,  2),  false, true), // 86
	World_object::Scenery_part(jgl::Vector2Int(23,  2),  false, true), // 87
	World_object::Scenery_part(jgl::Vector2Int(24,  2),  false, true), // 88
	World_object::Scenery_part(jgl::Vector2Int(25,  2),  false, true), // 89
	World_object::Scenery_part(jgl::Vector2Int(26,  2),  false, true), // -- 90
	World_object::Scenery_part(jgl::Vector2Int(27,  2),  false, true), // 91
	World_object::Scenery_part(jgl::Vector2Int(28,  2),  false, true), // 92
	World_object::Scenery_part(jgl::Vector2Int(29,  2),  false, true), // 93
	World_object::Scenery_part(jgl::Vector2Int(30,  2),  false, true), // 94
	World_object::Scenery_part(jgl::Vector2Int(31,  2),  false, true), // 95
	World_object::Scenery_part(jgl::Vector2Int( 0,  3),  false, true), // 96
	World_object::Scenery_part(jgl::Vector2Int( 1,  3),  false, true), // 97
	World_object::Scenery_part(jgl::Vector2Int( 2,  3),  false, true), // 98
	World_object::Scenery_part(jgl::Vector2Int( 3,  3),  false, true), // 99
	World_object::Scenery_part(jgl::Vector2Int( 4,  3), false, true), // 	---- 100
	World_object::Scenery_part(jgl::Vector2Int( 5,  3), false, true), // 101
	World_object::Scenery_part(jgl::Vector2Int( 6,  3), false, true), // 102
	World_object::Scenery_part(jgl::Vector2Int( 7,  3), false, true), // 103
	World_object::Scenery_part(jgl::Vector2Int( 8,  3), false, true), // 104
	World_object::Scenery_part(jgl::Vector2Int( 9,  3), false, true), // 105
	World_object::Scenery_part(jgl::Vector2Int(10,  3), false, true), // 106
	World_object::Scenery_part(jgl::Vector2Int(11,  3), false, true), // 107
	World_object::Scenery_part(jgl::Vector2Int(12,  3), false, true), // 108
	World_object::Scenery_part(jgl::Vector2Int(13,  3), false, true), // 109
	World_object::Scenery_part(jgl::Vector2Int(14,  3), false, true), // -- 110
	World_object::Scenery_part(jgl::Vector2Int(15,  3), false, true), // 111
	World_object::Scenery_part(jgl::Vector2Int(16,  3), false, true), // 112
	World_object::Scenery_part(jgl::Vector2Int(17,  3), false, true), // 113
	World_object::Scenery_part(jgl::Vector2Int(18,  3), false, true), // 114
	World_object::Scenery_part(jgl::Vector2Int(19,  3), false, true), // 115
	World_object::Scenery_part(jgl::Vector2Int(20,  3), false, true), // 116
	World_object::Scenery_part(jgl::Vector2Int(21,  3), false, true), // 117
	World_object::Scenery_part(jgl::Vector2Int(22,  3), false, true), // 118
	World_object::Scenery_part(jgl::Vector2Int(23,  3), false, true), // 119
	World_object::Scenery_part(jgl::Vector2Int(24,  3), false, true), // -- 120
	World_object::Scenery_part(jgl::Vector2Int(25,  3), false, true), // 121
	World_object::Scenery_part(jgl::Vector2Int(26,  3), false, true), // 122
	World_object::Scenery_part(jgl::Vector2Int(27,  3), false, true), // 123
	World_object::Scenery_part(jgl::Vector2Int(28,  3), false, true), // 124
	World_object::Scenery_part(jgl::Vector2Int(29,  3), false, true), // 125
	World_object::Scenery_part(jgl::Vector2Int(30,  3), false, true), // 126
	World_object::Scenery_part(jgl::Vector2Int(31,  3), false, true), // 127
	World_object::Scenery_part(jgl::Vector2Int( 0,  4), false, true), // 128
	World_object::Scenery_part(jgl::Vector2Int( 1,  4), false, true), // 129
	World_object::Scenery_part(jgl::Vector2Int( 2,  4), false, true), // -- 130
	World_object::Scenery_part(jgl::Vector2Int( 3,  4), false, true), // 131
	World_object::Scenery_part(jgl::Vector2Int( 4,  4), false, true), // 132
	World_object::Scenery_part(jgl::Vector2Int( 5,  4), false, true), // 133
	World_object::Scenery_part(jgl::Vector2Int( 6,  4), false, true), // 134
	World_object::Scenery_part(jgl::Vector2Int( 7,  4), false, true), // 135
	World_object::Scenery_part(jgl::Vector2Int( 8,  4), false, true), // 136
	World_object::Scenery_part(jgl::Vector2Int( 9,  4), false, true), // 137
	World_object::Scenery_part(jgl::Vector2Int(10,  4), false, true), // 138
	World_object::Scenery_part(jgl::Vector2Int(11,  4), false, true), // 139
	World_object::Scenery_part(jgl::Vector2Int(12,  4), false, true), // -- 140
	World_object::Scenery_part(jgl::Vector2Int(13,  4), false, true), // 141
	World_object::Scenery_part(jgl::Vector2Int(14,  4), false, true), // 142
	World_object::Scenery_part(jgl::Vector2Int(15,  4), false, true), // 143
	World_object::Scenery_part(jgl::Vector2Int(16,  4), false, true), // 144
	World_object::Scenery_part(jgl::Vector2Int(17,  4), false, true), // 145
	World_object::Scenery_part(jgl::Vector2Int(18,  4), false, true), // 146
	World_object::Scenery_part(jgl::Vector2Int(19,  4), false, true), // 147
	World_object::Scenery_part(jgl::Vector2Int(20,  4), false, true), // 148
	World_object::Scenery_part(jgl::Vector2Int(21,  4), false, true), // 149
	World_object::Scenery_part(jgl::Vector2Int(22,  4), false, true), // -- 150
	World_object::Scenery_part(jgl::Vector2Int(23,  4), false, true), // 151
	World_object::Scenery_part(jgl::Vector2Int(24,  4), false, true), // 152
	World_object::Scenery_part(jgl::Vector2Int(25,  4), false, true), // 153
	World_object::Scenery_part(jgl::Vector2Int(26,  4), false, true), // 154
	World_object::Scenery_part(jgl::Vector2Int(27,  4), false, true), // 155
	World_object::Scenery_part(jgl::Vector2Int(28,  4), false, true), // 156
	World_object::Scenery_part(jgl::Vector2Int(29,  4), false, true), // 157
	World_object::Scenery_part(jgl::Vector2Int(30,  4), false, true), // 158
	World_object::Scenery_part(jgl::Vector2Int(31,  4), false, true), // 159
	World_object::Scenery_part(jgl::Vector2Int( 0,  5), false, true), // -- 160
	World_object::Scenery_part(jgl::Vector2Int( 1,  5), false, true), // 161
	World_object::Scenery_part(jgl::Vector2Int( 2,  5), false, true), // 162
	World_object::Scenery_part(jgl::Vector2Int( 3,  5), false, true), // 163
	World_object::Scenery_part(jgl::Vector2Int( 4,  5), false, true), // 164
	World_object::Scenery_part(jgl::Vector2Int( 5,  5), false, true), // 165
	World_object::Scenery_part(jgl::Vector2Int( 6,  5), false, true), // 166
	World_object::Scenery_part(jgl::Vector2Int( 7,  5), false, true), // 167
	World_object::Scenery_part(jgl::Vector2Int( 8,  5), false, true), // 168
	World_object::Scenery_part(jgl::Vector2Int( 9,  5), false, true), // 169
	World_object::Scenery_part(jgl::Vector2Int(10,  5), false, true), // -- 170
	World_object::Scenery_part(jgl::Vector2Int(11,  5), false, true), // 171
	World_object::Scenery_part(jgl::Vector2Int(12,  5), false, true), // 172
	World_object::Scenery_part(jgl::Vector2Int(13,  5), false, true), // 173
	World_object::Scenery_part(jgl::Vector2Int(14,  5), false, true), // 174
	World_object::Scenery_part(jgl::Vector2Int(15,  5), false, true), // 175
	World_object::Scenery_part(jgl::Vector2Int(16,  5), false, true), // 176
	World_object::Scenery_part(jgl::Vector2Int(17,  5), false, true), // 177
	World_object::Scenery_part(jgl::Vector2Int(18,  5), false, true), // 178
	World_object::Scenery_part(jgl::Vector2Int(19,  5), false, true), // 179
	World_object::Scenery_part(jgl::Vector2Int(20,  5), false, true), // -- 180
	World_object::Scenery_part(jgl::Vector2Int(21,  5), false, true), // 181
	World_object::Scenery_part(jgl::Vector2Int(22,  5), false, true), // 182
	World_object::Scenery_part(jgl::Vector2Int(23,  5), false, true), // 183
	World_object::Scenery_part(jgl::Vector2Int(24,  5), false, true), // 184
	World_object::Scenery_part(jgl::Vector2Int(25,  5), false, true), // 185
	World_object::Scenery_part(jgl::Vector2Int(26,  5), false, true), // 186
	World_object::Scenery_part(jgl::Vector2Int(27,  5), false, true), // 187
	World_object::Scenery_part(jgl::Vector2Int(28,  5), false, true), // 188
	World_object::Scenery_part(jgl::Vector2Int(29,  5), false, true), // 189
	World_object::Scenery_part(jgl::Vector2Int(30,  5), false, true), // -- 190
	World_object::Scenery_part(jgl::Vector2Int(31,  5), false, true), // 191
	World_object::Scenery_part(jgl::Vector2Int( 0,  6), false, true), // 192
	World_object::Scenery_part(jgl::Vector2Int( 1,  6), false, true), // 193
	World_object::Scenery_part(jgl::Vector2Int( 2,  6), false, true), // 194
	World_object::Scenery_part(jgl::Vector2Int( 3,  6), false, true), // 195
	World_object::Scenery_part(jgl::Vector2Int( 4,  6), false, true), // 196
	World_object::Scenery_part(jgl::Vector2Int( 5,  6), false, true), // 197
	World_object::Scenery_part(jgl::Vector2Int( 6,  6), false, true), // 198
	World_object::Scenery_part(jgl::Vector2Int( 7,  6), false, true), // 199
	World_object::Scenery_part(jgl::Vector2Int( 8,  6), false, true), // 	---- 200
	World_object::Scenery_part(jgl::Vector2Int( 9,  6), false, true), // 201
	World_object::Scenery_part(jgl::Vector2Int(10,  6), false, true), // 202
	World_object::Scenery_part(jgl::Vector2Int(11,  6), false, true), // 203
	World_object::Scenery_part(jgl::Vector2Int(12,  6), false, true), // 204
	World_object::Scenery_part(jgl::Vector2Int(13,  6), false, true), // 205
	World_object::Scenery_part(jgl::Vector2Int(14,  6), false, true), // 206
	World_object::Scenery_part(jgl::Vector2Int(15,  6), false, true), // 207
	World_object::Scenery_part(jgl::Vector2Int(16,  6), false, true), // 208
	World_object::Scenery_part(jgl::Vector2Int(17,  6), false, true), // 209
	World_object::Scenery_part(jgl::Vector2Int(18,  6), false, true), // -- 210
	World_object::Scenery_part(jgl::Vector2Int(19,  6), false, true), // 211
	World_object::Scenery_part(jgl::Vector2Int(20,  6), false, true), // 212
	World_object::Scenery_part(jgl::Vector2Int(21,  6), false, true), // 213
	World_object::Scenery_part(jgl::Vector2Int(22,  6), false, true), // 214
	World_object::Scenery_part(jgl::Vector2Int(23,  6), false, true), // 215
	World_object::Scenery_part(jgl::Vector2Int(24,  6), false, true), // 216
	World_object::Scenery_part(jgl::Vector2Int(25,  6), false, true), // 217
	World_object::Scenery_part(jgl::Vector2Int(26,  6), false, true), // 218
	World_object::Scenery_part(jgl::Vector2Int(27,  6), false, true), // 219
	World_object::Scenery_part(jgl::Vector2Int(28,  6), false, true), // -- 220
	World_object::Scenery_part(jgl::Vector2Int(29,  6), false, true), // 221
	World_object::Scenery_part(jgl::Vector2Int(30,  6), false, true), // 222
	World_object::Scenery_part(jgl::Vector2Int(31,  6), false, true), // 223
	World_object::Scenery_part(jgl::Vector2Int( 0,  7), false, true), // 224
	World_object::Scenery_part(jgl::Vector2Int( 1,  7), false, true), // 225
	World_object::Scenery_part(jgl::Vector2Int( 2,  7), false, true), // 226
	World_object::Scenery_part(jgl::Vector2Int( 3,  7), false, true), // 227
	World_object::Scenery_part(jgl::Vector2Int( 4,  7), false, true), // 228
	World_object::Scenery_part(jgl::Vector2Int( 5,  7), false, true), // 229
	World_object::Scenery_part(jgl::Vector2Int( 6,  7), false, true), // -- 230
	World_object::Scenery_part(jgl::Vector2Int( 7,  7), false, true), // 231
	World_object::Scenery_part(jgl::Vector2Int( 8,  7), false, true), // 232
	World_object::Scenery_part(jgl::Vector2Int( 9,  7), false, true), // 233
	World_object::Scenery_part(jgl::Vector2Int(10,  7), false, true), // 234
	World_object::Scenery_part(jgl::Vector2Int(11,  7), false, true), // 235
	World_object::Scenery_part(jgl::Vector2Int(12,  7), false, true), // 236
	World_object::Scenery_part(jgl::Vector2Int(13,  7), false, true), // 237
	World_object::Scenery_part(jgl::Vector2Int(14,  7), false, true), // 238
	World_object::Scenery_part(jgl::Vector2Int(15,  7), false, true), // 239
	World_object::Scenery_part(jgl::Vector2Int(16,  7), false, true), // -- 240
	World_object::Scenery_part(jgl::Vector2Int(17,  7), false, true), // 241
	World_object::Scenery_part(jgl::Vector2Int(18,  7), false, true), // 242
	World_object::Scenery_part(jgl::Vector2Int(19,  7), false, true), // 243
	World_object::Scenery_part(jgl::Vector2Int(20,  7), false, true), // 244
	World_object::Scenery_part(jgl::Vector2Int(21,  7), false, true), // 245
	World_object::Scenery_part(jgl::Vector2Int(22,  7), false, true), // 246
	World_object::Scenery_part(jgl::Vector2Int(23,  7), false, true), // 247
	World_object::Scenery_part(jgl::Vector2Int(24,  7), false, true), // 248
	World_object::Scenery_part(jgl::Vector2Int(25,  7), false, true), // 249
	World_object::Scenery_part(jgl::Vector2Int(26,  7), false, true), // -- 250
	World_object::Scenery_part(jgl::Vector2Int(27,  7), false, true), // 251
	World_object::Scenery_part(jgl::Vector2Int(28,  7), false, true), // 252
	World_object::Scenery_part(jgl::Vector2Int(29,  7), false, true), // 253
	World_object::Scenery_part(jgl::Vector2Int(30,  7), false, true), // 254
	World_object::Scenery_part(jgl::Vector2Int(31,  7), false, true), // 255
	World_object::Scenery_part(jgl::Vector2Int( 0,  8), false, true), // 256
	World_object::Scenery_part(jgl::Vector2Int( 1,  8), false, true), // 257
	World_object::Scenery_part(jgl::Vector2Int( 2,  8), false, true), // 258
	World_object::Scenery_part(jgl::Vector2Int( 3,  8), false, true), // 259
	World_object::Scenery_part(jgl::Vector2Int( 4,  8), false, true), // -- 260
	World_object::Scenery_part(jgl::Vector2Int( 5,  8), false, true), // 261
	World_object::Scenery_part(jgl::Vector2Int( 6,  8), false, true), // 262
	World_object::Scenery_part(jgl::Vector2Int( 7,  8), false, true), // 263
	World_object::Scenery_part(jgl::Vector2Int( 8,  8), false, true), // 264
	World_object::Scenery_part(jgl::Vector2Int( 9,  8), false, true), // 265
	World_object::Scenery_part(jgl::Vector2Int(10,  8), false, true), // 266
	World_object::Scenery_part(jgl::Vector2Int(11,  8), false, true), // 267
	World_object::Scenery_part(jgl::Vector2Int(12,  8), false, true), // 268
	World_object::Scenery_part(jgl::Vector2Int(13,  8), false, true), // 269
	World_object::Scenery_part(jgl::Vector2Int(14,  8), false, true), // -- 270
	World_object::Scenery_part(jgl::Vector2Int(15,  8), false, true), // 271
	World_object::Scenery_part(jgl::Vector2Int(16,  8), false, true), // 272
	World_object::Scenery_part(jgl::Vector2Int(17,  8), false, true), // 273
	World_object::Scenery_part(jgl::Vector2Int(18,  8), false, true), // 274
	World_object::Scenery_part(jgl::Vector2Int(19,  8), false, true), // 275
	World_object::Scenery_part(jgl::Vector2Int(20,  8), false, true), // 276
	World_object::Scenery_part(jgl::Vector2Int(21,  8), false, true), // 277
	World_object::Scenery_part(jgl::Vector2Int(22,  8), false, true), // 278
	World_object::Scenery_part(jgl::Vector2Int(23,  8), false, true), // 279
	World_object::Scenery_part(jgl::Vector2Int(24,  8), false, true), // -- 280
	World_object::Scenery_part(jgl::Vector2Int(25,  8), false, true), // 281
	World_object::Scenery_part(jgl::Vector2Int(26,  8), false, true), // 282
	World_object::Scenery_part(jgl::Vector2Int(27,  8), false, true), // 283
	World_object::Scenery_part(jgl::Vector2Int(28,  8), false, true), // 284
	World_object::Scenery_part(jgl::Vector2Int(29,  8), false, true), // 285
	World_object::Scenery_part(jgl::Vector2Int(30,  8), false, true), // 286
	World_object::Scenery_part(jgl::Vector2Int(31,  8), false, true), // 287
	World_object::Scenery_part(jgl::Vector2Int( 0,  9), false, true), // 288
	World_object::Scenery_part(jgl::Vector2Int( 1,  9), false, true), // 289
	World_object::Scenery_part(jgl::Vector2Int( 2,  9), false, true), // -- 290
	World_object::Scenery_part(jgl::Vector2Int( 3,  9), false, true), // 291
	World_object::Scenery_part(jgl::Vector2Int( 4,  9), false, true), // 292
	World_object::Scenery_part(jgl::Vector2Int( 5,  9), false, true), // 293
	World_object::Scenery_part(jgl::Vector2Int( 6,  9), false, true), // 294
	World_object::Scenery_part(jgl::Vector2Int( 7,  9), false, true), // 295
	World_object::Scenery_part(jgl::Vector2Int( 8,  9), false, true), // 296
	World_object::Scenery_part(jgl::Vector2Int( 9,  9), false, true), // 297
	World_object::Scenery_part(jgl::Vector2Int(10,  9), false, true), // 298
	World_object::Scenery_part(jgl::Vector2Int(11,  9), false, true), // 299
	World_object::Scenery_part(jgl::Vector2Int(12,  9), false, true), // 	---- 300
	World_object::Scenery_part(jgl::Vector2Int(13,  9), false, true), // 301
	World_object::Scenery_part(jgl::Vector2Int(14,  9), false, true), // 302
	World_object::Scenery_part(jgl::Vector2Int(15,  9), false, true), // 303
	World_object::Scenery_part(jgl::Vector2Int(16,  9), false, true), // 304
	World_object::Scenery_part(jgl::Vector2Int(17,  9), false, true), // 305
	World_object::Scenery_part(jgl::Vector2Int(18,  9), false, true), // 306
	World_object::Scenery_part(jgl::Vector2Int(19,  9), false, true), // 307
	World_object::Scenery_part(jgl::Vector2Int(20,  9), false, true), // 308
	World_object::Scenery_part(jgl::Vector2Int(21,  9), false, true), // 309
	World_object::Scenery_part(jgl::Vector2Int(22,  9), false, true), // -- 310
	World_object::Scenery_part(jgl::Vector2Int(23,  9), false, true), // 311
	World_object::Scenery_part(jgl::Vector2Int(24,  9), false, true), // 312
	World_object::Scenery_part(jgl::Vector2Int(25,  9), false, true), // 313
	World_object::Scenery_part(jgl::Vector2Int(26,  9), false, true), // 314
	World_object::Scenery_part(jgl::Vector2Int(27,  9), false, true), // 315
	World_object::Scenery_part(jgl::Vector2Int(28,  9), false, true), // 316
	World_object::Scenery_part(jgl::Vector2Int(29,  9), false, true), // 317
	World_object::Scenery_part(jgl::Vector2Int(30,  9), false, true), // 318
	World_object::Scenery_part(jgl::Vector2Int(31,  9), false, true), // 319
	World_object::Scenery_part(jgl::Vector2Int( 0, 10), false, true), // -- 320
	World_object::Scenery_part(jgl::Vector2Int( 1, 10), false, true), // 321
	World_object::Scenery_part(jgl::Vector2Int( 2, 10), false, true), // 322
	World_object::Scenery_part(jgl::Vector2Int( 3, 10), false, true), // 323
	World_object::Scenery_part(jgl::Vector2Int( 4, 10), false, true), // 324
	World_object::Scenery_part(jgl::Vector2Int( 5, 10), false, true), // 325
	World_object::Scenery_part(jgl::Vector2Int( 6, 10), false, true), // 326
	World_object::Scenery_part(jgl::Vector2Int( 7, 10), false, true), // 327
	World_object::Scenery_part(jgl::Vector2Int( 8, 10), false, true), // 328
	World_object::Scenery_part(jgl::Vector2Int( 9, 10), false, true), // 329
	World_object::Scenery_part(jgl::Vector2Int(10, 10), false, true), // -- 330
	World_object::Scenery_part(jgl::Vector2Int(11, 10), false, true), // 331
	World_object::Scenery_part(jgl::Vector2Int(12, 10), false, true), // 332
	World_object::Scenery_part(jgl::Vector2Int(13, 10), false, true), // 333
	World_object::Scenery_part(jgl::Vector2Int(14, 10), false, true), // 334
	World_object::Scenery_part(jgl::Vector2Int(15, 10), false, true), // 335
	World_object::Scenery_part(jgl::Vector2Int(16, 10), false, true), // 336
	World_object::Scenery_part(jgl::Vector2Int(17, 10), false, true), // 337
	World_object::Scenery_part(jgl::Vector2Int(18, 10), false, true), // 338
	World_object::Scenery_part(jgl::Vector2Int(19, 10), false, true), // 339
	World_object::Scenery_part(jgl::Vector2Int(20, 10), false, true), // -- 340
	World_object::Scenery_part(jgl::Vector2Int(21, 10), false, true), // 341
	World_object::Scenery_part(jgl::Vector2Int(22, 10), false, true), // 342
	World_object::Scenery_part(jgl::Vector2Int(23, 10), false, true), // 343
	World_object::Scenery_part(jgl::Vector2Int(24, 10), false, true), // 344
	World_object::Scenery_part(jgl::Vector2Int(25, 10), false, true), // 345
	World_object::Scenery_part(jgl::Vector2Int(26, 10), false, true), // 346
	World_object::Scenery_part(jgl::Vector2Int(27, 10), false, true), // 347
	World_object::Scenery_part(jgl::Vector2Int(28, 10), false, true), // 348
	World_object::Scenery_part(jgl::Vector2Int(29, 10), false, true), // 349
	World_object::Scenery_part(jgl::Vector2Int(30, 10), false, true), // -- 350
	World_object::Scenery_part(jgl::Vector2Int(31, 10), false, true), // 351
	World_object::Scenery_part(jgl::Vector2Int( 0, 11), false, true), // 352
	World_object::Scenery_part(jgl::Vector2Int( 1, 11), false, true), // 353
	World_object::Scenery_part(jgl::Vector2Int( 2, 11), false, true), // 354
	World_object::Scenery_part(jgl::Vector2Int( 3, 11), false, true), // 355
	World_object::Scenery_part(jgl::Vector2Int( 4, 11), false, true), // 356
	World_object::Scenery_part(jgl::Vector2Int( 5, 11), false, true), // 357
	World_object::Scenery_part(jgl::Vector2Int( 6, 11), false, true), // 358
	World_object::Scenery_part(jgl::Vector2Int( 7, 11), false, true), // 359
	World_object::Scenery_part(jgl::Vector2Int( 8, 11), false, true), // -- 360
	World_object::Scenery_part(jgl::Vector2Int( 9, 11), false, true), // 361
	World_object::Scenery_part(jgl::Vector2Int(10, 11), false, true), // 362
	World_object::Scenery_part(jgl::Vector2Int(11, 11), false, true), // 363
	World_object::Scenery_part(jgl::Vector2Int(12, 11), false, true), // 364
	World_object::Scenery_part(jgl::Vector2Int(13, 11), false, true), // 365
	World_object::Scenery_part(jgl::Vector2Int(14, 11), false, true), // 366
	World_object::Scenery_part(jgl::Vector2Int(15, 11), false, true), // 367
	World_object::Scenery_part(jgl::Vector2Int(16, 11), false, true), // 368
	World_object::Scenery_part(jgl::Vector2Int(17, 11), false, true), // 369
	World_object::Scenery_part(jgl::Vector2Int(18, 11), false, true), // -- 370
	World_object::Scenery_part(jgl::Vector2Int(19, 11), false, true), // 371
	World_object::Scenery_part(jgl::Vector2Int(20, 11), false, true), // 372
	World_object::Scenery_part(jgl::Vector2Int(21, 11), false, true), // 373
	World_object::Scenery_part(jgl::Vector2Int(22, 11), false, true), // 374
	World_object::Scenery_part(jgl::Vector2Int(23, 11), false, true), // 375
	World_object::Scenery_part(jgl::Vector2Int(24, 11), false, true), // 376
	World_object::Scenery_part(jgl::Vector2Int(25, 11), false, true), // 377
	World_object::Scenery_part(jgl::Vector2Int(26, 11), false, true), // 378
	World_object::Scenery_part(jgl::Vector2Int(27, 11), false, true), // 379
	World_object::Scenery_part(jgl::Vector2Int(28, 11), false, true), // -- 380
	World_object::Scenery_part(jgl::Vector2Int(29, 11), false, true), // 381
	World_object::Scenery_part(jgl::Vector2Int(30, 11), false, true), // 382
	World_object::Scenery_part(jgl::Vector2Int(31, 11), false, true), // 383
	World_object::Scenery_part(jgl::Vector2Int( 0, 12), false, false), // 384
	World_object::Scenery_part(jgl::Vector2Int( 1, 12), false, false), // 385
	World_object::Scenery_part(jgl::Vector2Int( 2, 12), false, false), // 386
	World_object::Scenery_part(jgl::Vector2Int( 3, 12), false, false), // 387
	World_object::Scenery_part(jgl::Vector2Int( 4, 12), false, false), // 388
	World_object::Scenery_part(jgl::Vector2Int( 5, 12), false, false), // 389
	World_object::Scenery_part(jgl::Vector2Int( 6, 12), false, false), // -- 390
	World_object::Scenery_part(jgl::Vector2Int( 7, 12), false, false), // 391
	World_object::Scenery_part(jgl::Vector2Int( 8, 12), false, false), // 392
	World_object::Scenery_part(jgl::Vector2Int( 9, 12), false, false), // 393
	World_object::Scenery_part(jgl::Vector2Int(10, 12), false, false), // 394
	World_object::Scenery_part(jgl::Vector2Int(11, 12), false, false), // 395
	World_object::Scenery_part(jgl::Vector2Int(12, 12), false, false), // 396
	World_object::Scenery_part(jgl::Vector2Int(13, 12), false, false), // 397
	World_object::Scenery_part(jgl::Vector2Int(14, 12), false, false), // 398
	World_object::Scenery_part(jgl::Vector2Int(15, 12), false, false), // 399
	World_object::Scenery_part(jgl::Vector2Int(16, 12), false, false), // 	---- 400
	World_object::Scenery_part(jgl::Vector2Int(17, 12), false, false), // 401
	World_object::Scenery_part(jgl::Vector2Int(18, 12), false, false), // 402
	World_object::Scenery_part(jgl::Vector2Int(19, 12), false, false), // 403
	World_object::Scenery_part(jgl::Vector2Int(20, 12), false, false), // 404
	World_object::Scenery_part(jgl::Vector2Int(21, 12), false, false), // 405
	World_object::Scenery_part(jgl::Vector2Int(22, 12), false, false), // 406
	World_object::Scenery_part(jgl::Vector2Int(23, 12), false, false), // 407
	World_object::Scenery_part(jgl::Vector2Int(24, 12), false, false), // 408
	World_object::Scenery_part(jgl::Vector2Int(25, 12), false, false), // 409
	World_object::Scenery_part(jgl::Vector2Int(26, 12), false, false), // -- 410
	World_object::Scenery_part(jgl::Vector2Int(27, 12), false, false), // 411
	World_object::Scenery_part(jgl::Vector2Int(28, 12), false, false), // 412
	World_object::Scenery_part(jgl::Vector2Int(29, 12), false, false), // 413
	World_object::Scenery_part(jgl::Vector2Int(30, 12), false, false), // 414
	World_object::Scenery_part(jgl::Vector2Int(31, 12), false, false), // 415
	World_object::Scenery_part(jgl::Vector2Int( 0, 13), false, false), // 416
	World_object::Scenery_part(jgl::Vector2Int( 1, 13), false, false), // 417
	World_object::Scenery_part(jgl::Vector2Int( 2, 13), false, false), // 418
	World_object::Scenery_part(jgl::Vector2Int( 3, 13), false, false), // 419
	World_object::Scenery_part(jgl::Vector2Int( 4, 13), false, false), // -- 420
	World_object::Scenery_part(jgl::Vector2Int( 5, 13), false, false), // 421
	World_object::Scenery_part(jgl::Vector2Int( 6, 13), false, false), // 422
	World_object::Scenery_part(jgl::Vector2Int( 7, 13), false, false), // 423
	World_object::Scenery_part(jgl::Vector2Int( 8, 13), false, false), // 424
	World_object::Scenery_part(jgl::Vector2Int( 9, 13), false, false), // 425
	World_object::Scenery_part(jgl::Vector2Int(10, 13), false, false), // 426
	World_object::Scenery_part(jgl::Vector2Int(11, 13), false, false), // 427
	World_object::Scenery_part(jgl::Vector2Int(12, 13), false, false), // 428
	World_object::Scenery_part(jgl::Vector2Int(13, 13), false, false), // 429
	World_object::Scenery_part(jgl::Vector2Int(14, 13), false, false), // -- 430
	World_object::Scenery_part(jgl::Vector2Int(15, 13), false, false), // 431
	World_object::Scenery_part(jgl::Vector2Int(16, 13), false, false), // 432
	World_object::Scenery_part(jgl::Vector2Int(17, 13), false, false), // 433
	World_object::Scenery_part(jgl::Vector2Int(18, 13), false, false), // 434
	World_object::Scenery_part(jgl::Vector2Int(19, 13), false, false), // 435
	World_object::Scenery_part(jgl::Vector2Int(20, 13), false, false), // 436
	World_object::Scenery_part(jgl::Vector2Int(21, 13), false, false), // 437
	World_object::Scenery_part(jgl::Vector2Int(22, 13), false, false), // 438
	World_object::Scenery_part(jgl::Vector2Int(23, 13), false, false), // 439
	World_object::Scenery_part(jgl::Vector2Int(24, 13), false, false), // -- 440
	World_object::Scenery_part(jgl::Vector2Int(25, 13), false, false), // 441
	World_object::Scenery_part(jgl::Vector2Int(26, 13), false, false), // 442
	World_object::Scenery_part(jgl::Vector2Int(27, 13), false, false), // 443
	World_object::Scenery_part(jgl::Vector2Int(28, 13), false, false), // 444
	World_object::Scenery_part(jgl::Vector2Int(29, 13), false, false), // 445
	World_object::Scenery_part(jgl::Vector2Int(30, 13), false, false), // 446
	World_object::Scenery_part(jgl::Vector2Int(31, 13), false, false), // 447
	World_object::Scenery_part(jgl::Vector2Int( 0, 14), false, false), // 448
	World_object::Scenery_part(jgl::Vector2Int( 1, 14), false, false), // 449
	World_object::Scenery_part(jgl::Vector2Int( 2, 14), false, false), // -- 450
	World_object::Scenery_part(jgl::Vector2Int( 3, 14), false, false), // 451
	World_object::Scenery_part(jgl::Vector2Int( 4, 14), false, false), // 452
	World_object::Scenery_part(jgl::Vector2Int( 5, 14), false, false), // 453
	World_object::Scenery_part(jgl::Vector2Int( 6, 14), false, false), // 454
	World_object::Scenery_part(jgl::Vector2Int( 7, 14), false, false), // 455
	World_object::Scenery_part(jgl::Vector2Int( 8, 14), false, false), // 456
	World_object::Scenery_part(jgl::Vector2Int( 9, 14), false, false), // 457
	World_object::Scenery_part(jgl::Vector2Int(10, 14), false, false), // 458
	World_object::Scenery_part(jgl::Vector2Int(11, 14), false, false), // 459
	World_object::Scenery_part(jgl::Vector2Int(12, 14), false, false), // -- 460
	World_object::Scenery_part(jgl::Vector2Int(13, 14), false, false), // 461
	World_object::Scenery_part(jgl::Vector2Int(14, 14), false, false), // 462
	World_object::Scenery_part(jgl::Vector2Int(15, 14), false, false), // 463
	World_object::Scenery_part(jgl::Vector2Int(16, 14), false, false), // 464
	World_object::Scenery_part(jgl::Vector2Int(17, 14), false, false), // 465
	World_object::Scenery_part(jgl::Vector2Int(18, 14), false, false), // 466
	World_object::Scenery_part(jgl::Vector2Int(19, 14), false, false), // 467
	World_object::Scenery_part(jgl::Vector2Int(20, 14), false, false), // 468
	World_object::Scenery_part(jgl::Vector2Int(21, 14), false, false), // 469
	World_object::Scenery_part(jgl::Vector2Int(22, 14), false, false), // -- 470
	World_object::Scenery_part(jgl::Vector2Int(23, 14), false, false), // 471
	World_object::Scenery_part(jgl::Vector2Int(24, 14), false, false), // 472
	World_object::Scenery_part(jgl::Vector2Int(25, 14), false, false), // 473
	World_object::Scenery_part(jgl::Vector2Int(26, 14), false, false), // 474
	World_object::Scenery_part(jgl::Vector2Int(27, 14), false, false), // 475
	World_object::Scenery_part(jgl::Vector2Int(28, 14), false, false), // 476
	World_object::Scenery_part(jgl::Vector2Int(29, 14), false, false), // 477
	World_object::Scenery_part(jgl::Vector2Int(30, 14), false, false), // 478
	World_object::Scenery_part(jgl::Vector2Int(31, 14), false, false), // 479
	World_object::Scenery_part(jgl::Vector2Int( 0, 15), false, false), // -- 480
	World_object::Scenery_part(jgl::Vector2Int( 1, 15), false, false), // 481
	World_object::Scenery_part(jgl::Vector2Int( 2, 15), false, false), // 482
	World_object::Scenery_part(jgl::Vector2Int( 3, 15), false, false), // 483
	World_object::Scenery_part(jgl::Vector2Int( 4, 15), false, false), // 484
	World_object::Scenery_part(jgl::Vector2Int( 5, 15), false, false), // 485
	World_object::Scenery_part(jgl::Vector2Int( 6, 15), false, false), // 486
	World_object::Scenery_part(jgl::Vector2Int( 7, 15), false, false), // 487
	World_object::Scenery_part(jgl::Vector2Int( 8, 15), false, false), // 488
	World_object::Scenery_part(jgl::Vector2Int( 9, 15), false, false), // 489
	World_object::Scenery_part(jgl::Vector2Int(10, 15), false, false), // -- 490
	World_object::Scenery_part(jgl::Vector2Int(11, 15), false, false), // 491
	World_object::Scenery_part(jgl::Vector2Int(12, 15), false, false), // 492
	World_object::Scenery_part(jgl::Vector2Int(13, 15), false, false), // 493
	World_object::Scenery_part(jgl::Vector2Int(14, 15), false, false), // 494
	World_object::Scenery_part(jgl::Vector2Int(15, 15), false, false), // 495
	World_object::Scenery_part(jgl::Vector2Int(16, 15), false, false), // 496
	World_object::Scenery_part(jgl::Vector2Int(17, 15), false, false), // 497
	World_object::Scenery_part(jgl::Vector2Int(18, 15), false, false), // 498
	World_object::Scenery_part(jgl::Vector2Int(19, 15), false, false), // 499
	World_object::Scenery_part(jgl::Vector2Int(20, 15), false, false), // 	---- 500
	World_object::Scenery_part(jgl::Vector2Int(21, 15), false, false), // 501
	World_object::Scenery_part(jgl::Vector2Int(22, 15), false, false), // 502
	World_object::Scenery_part(jgl::Vector2Int(23, 15), false, false), // 503
	World_object::Scenery_part(jgl::Vector2Int(24, 15), false, false), // 504
	World_object::Scenery_part(jgl::Vector2Int(25, 15), false, false), // 505
	World_object::Scenery_part(jgl::Vector2Int(26, 15), false, false), // 506
	World_object::Scenery_part(jgl::Vector2Int(27, 15), false, false), // 507
	World_object::Scenery_part(jgl::Vector2Int(28, 15), false, false), // 508
	World_object::Scenery_part(jgl::Vector2Int(29, 15), false, false), // 509
	World_object::Scenery_part(jgl::Vector2Int(30, 15), false, false), // -- 510
	World_object::Scenery_part(jgl::Vector2Int(31, 15), false, false), // 511
	World_object::Scenery_part(jgl::Vector2Int( 0, 16), false, false), // 512
	World_object::Scenery_part(jgl::Vector2Int( 1, 16), false, false), // 513
	World_object::Scenery_part(jgl::Vector2Int( 2, 16), false, false), // 514
	World_object::Scenery_part(jgl::Vector2Int( 3, 16), false, false), // 515
	World_object::Scenery_part(jgl::Vector2Int( 4, 16), false, false), // 516
	World_object::Scenery_part(jgl::Vector2Int( 5, 16), false, false), // 517
	World_object::Scenery_part(jgl::Vector2Int( 6, 16), false, false), // 518
	World_object::Scenery_part(jgl::Vector2Int( 7, 16), false, false), // 519
	World_object::Scenery_part(jgl::Vector2Int( 8, 16), false, false), // -- 520
	World_object::Scenery_part(jgl::Vector2Int( 9, 16), false, false), // 521
	World_object::Scenery_part(jgl::Vector2Int(10, 16), false, false), // 522
	World_object::Scenery_part(jgl::Vector2Int(11, 16), false, false), // 523
	World_object::Scenery_part(jgl::Vector2Int(12, 16), false, false), // 524
	World_object::Scenery_part(jgl::Vector2Int(13, 16), false, false), // 525
	World_object::Scenery_part(jgl::Vector2Int(14, 16), false, false), // 526
	World_object::Scenery_part(jgl::Vector2Int(15, 16), false, false), // 527
	World_object::Scenery_part(jgl::Vector2Int(16, 16), false, false), // 528
	World_object::Scenery_part(jgl::Vector2Int(17, 16), false, false), // 529
	World_object::Scenery_part(jgl::Vector2Int(18, 16), false, false), // -- 530
	World_object::Scenery_part(jgl::Vector2Int(19, 16), false, false), // 531
	World_object::Scenery_part(jgl::Vector2Int(20, 16), false, false), // 532
	World_object::Scenery_part(jgl::Vector2Int(21, 16), false, false), // 533
	World_object::Scenery_part(jgl::Vector2Int(22, 16), false, false), // 534
	World_object::Scenery_part(jgl::Vector2Int(23, 16), false, false), // 535
	World_object::Scenery_part(jgl::Vector2Int(24, 16), false, false), // 536
	World_object::Scenery_part(jgl::Vector2Int(25, 16), false, false), // 537
	World_object::Scenery_part(jgl::Vector2Int(26, 16), false, false), // 538
	World_object::Scenery_part(jgl::Vector2Int(27, 16), false, false), // 539
	World_object::Scenery_part(jgl::Vector2Int(28, 16), false, false), // -- 540
	World_object::Scenery_part(jgl::Vector2Int(29, 16), false, false), // 541
	World_object::Scenery_part(jgl::Vector2Int(30, 16), false, false), // 542
	World_object::Scenery_part(jgl::Vector2Int(31, 16), false, false), // 543
	World_object::Scenery_part(jgl::Vector2Int( 0, 17), false, false), // 544
	World_object::Scenery_part(jgl::Vector2Int( 1, 17), false, false), // 545
	World_object::Scenery_part(jgl::Vector2Int( 2, 17), false, false), // 546
	World_object::Scenery_part(jgl::Vector2Int( 3, 17), false, false), // 547
	World_object::Scenery_part(jgl::Vector2Int( 4, 17), false, false), // 548
	World_object::Scenery_part(jgl::Vector2Int( 5, 17), false, false), // 549
	World_object::Scenery_part(jgl::Vector2Int( 6, 17), false, false), // -- 550
	World_object::Scenery_part(jgl::Vector2Int( 7, 17), false, false), // 551
	World_object::Scenery_part(jgl::Vector2Int( 8, 17), false, false), // 552
	World_object::Scenery_part(jgl::Vector2Int( 9, 17), false, false), // 553
	World_object::Scenery_part(jgl::Vector2Int(10, 17), false, false), // 554
	World_object::Scenery_part(jgl::Vector2Int(11, 17), false, false), // 555
	World_object::Scenery_part(jgl::Vector2Int(12, 17), false, false), // 556
	World_object::Scenery_part(jgl::Vector2Int(13, 17), false, false), // 557
	World_object::Scenery_part(jgl::Vector2Int(14, 17), false, false), // 558
	World_object::Scenery_part(jgl::Vector2Int(15, 17), false, false), // 559
	World_object::Scenery_part(jgl::Vector2Int(16, 17), false, false), // -- 560
	World_object::Scenery_part(jgl::Vector2Int(17, 17), false, false), // 561
	World_object::Scenery_part(jgl::Vector2Int(18, 17), false, false), // 562
	World_object::Scenery_part(jgl::Vector2Int(19, 17), false, false), // 563
	World_object::Scenery_part(jgl::Vector2Int(20, 17), false, false), // 564
	World_object::Scenery_part(jgl::Vector2Int(21, 17), false, false), // 565
	World_object::Scenery_part(jgl::Vector2Int(22, 17), false, false), // 566
	World_object::Scenery_part(jgl::Vector2Int(23, 17), false, false), // 567
	World_object::Scenery_part(jgl::Vector2Int(24, 17), false, false), // 568
	World_object::Scenery_part(jgl::Vector2Int(25, 17), false, false), // 569
	World_object::Scenery_part(jgl::Vector2Int(26, 17), false, false), // -- 570
	World_object::Scenery_part(jgl::Vector2Int(27, 17), false, false), // 571
	World_object::Scenery_part(jgl::Vector2Int(28, 17), false, false), // 572
	World_object::Scenery_part(jgl::Vector2Int(29, 17), false, false), // 573
	World_object::Scenery_part(jgl::Vector2Int(30, 17), false, false), // 574
	World_object::Scenery_part(jgl::Vector2Int(31, 17), false, false), // 575
	World_object::Scenery_part(jgl::Vector2Int( 0, 18), false, true), // 576
	World_object::Scenery_part(jgl::Vector2Int( 1, 18), false, true), // 577
	World_object::Scenery_part(jgl::Vector2Int( 2, 18), false, true), // 578
	World_object::Scenery_part(jgl::Vector2Int( 3, 18), false, true), // 579
	World_object::Scenery_part(jgl::Vector2Int( 4, 18), false, true), // -- 580
	World_object::Scenery_part(jgl::Vector2Int( 5, 18), false, true), // 581
	World_object::Scenery_part(jgl::Vector2Int( 6, 18), false, true), // 582
	World_object::Scenery_part(jgl::Vector2Int( 7, 18), false, true), // 583
	World_object::Scenery_part(jgl::Vector2Int( 8, 18), false, true), // 584
	World_object::Scenery_part(jgl::Vector2Int( 9, 18), false, true), // 585
	World_object::Scenery_part(jgl::Vector2Int(10, 18), false, true), // 586
	World_object::Scenery_part(jgl::Vector2Int(11, 18), false, true), // 587
	World_object::Scenery_part(jgl::Vector2Int(12, 18), false, true), // 588
	World_object::Scenery_part(jgl::Vector2Int(13, 18), false, true), // 589
	World_object::Scenery_part(jgl::Vector2Int(14, 18), false, true), // -- 590
	World_object::Scenery_part(jgl::Vector2Int(15, 18), false, true), // 591
	World_object::Scenery_part(jgl::Vector2Int(16, 18), false, false), // 592
	World_object::Scenery_part(jgl::Vector2Int(17, 18), false, false), // 593
	World_object::Scenery_part(jgl::Vector2Int(18, 18), false, false), // 594
	World_object::Scenery_part(jgl::Vector2Int(19, 18), false, false), // 595
	World_object::Scenery_part(jgl::Vector2Int(20, 18), false, false), // 596
	World_object::Scenery_part(jgl::Vector2Int(21, 18), false, false), // 597
	World_object::Scenery_part(jgl::Vector2Int(22, 18), false, false), // 598
	World_object::Scenery_part(jgl::Vector2Int(23, 18), false, false), // 599
	World_object::Scenery_part(jgl::Vector2Int(24, 18), false, true), // 	---- 600
	World_object::Scenery_part(jgl::Vector2Int(25, 18), false, true), // 601
	World_object::Scenery_part(jgl::Vector2Int(26, 18), false, true), // 602
	World_object::Scenery_part(jgl::Vector2Int(27, 18), false, true), // 603
	World_object::Scenery_part(jgl::Vector2Int(28, 18), false, true), // 604
	World_object::Scenery_part(jgl::Vector2Int(29, 18), false, true), // 605
	World_object::Scenery_part(jgl::Vector2Int(30, 18), false, true), // 606
	World_object::Scenery_part(jgl::Vector2Int(31, 18), false, true), // 607
	World_object::Scenery_part(jgl::Vector2Int( 0, 19), false, false), // 608
	World_object::Scenery_part(jgl::Vector2Int( 1, 19), false, false), // 609
	World_object::Scenery_part(jgl::Vector2Int( 2, 19), false, false), // -- 610
	World_object::Scenery_part(jgl::Vector2Int( 3, 19), false, false), // 611
	World_object::Scenery_part(jgl::Vector2Int( 4, 19), false, false), // 612
	World_object::Scenery_part(jgl::Vector2Int( 5, 19), false, false), // 613
	World_object::Scenery_part(jgl::Vector2Int( 6, 19), false, false), // 614
	World_object::Scenery_part(jgl::Vector2Int( 7, 19), false, false), // 615
	World_object::Scenery_part(jgl::Vector2Int( 8, 19), false, false), // 616
	World_object::Scenery_part(jgl::Vector2Int( 9, 19), false, false), // 617
	World_object::Scenery_part(jgl::Vector2Int(10, 19), false, false), // 618
	World_object::Scenery_part(jgl::Vector2Int(11, 19), false, false), // 619
	World_object::Scenery_part(jgl::Vector2Int(12, 19), false, false), // -- 620
	World_object::Scenery_part(jgl::Vector2Int(13, 19), false, false), // 621
	World_object::Scenery_part(jgl::Vector2Int(14, 19), false, false), // 622
	World_object::Scenery_part(jgl::Vector2Int(15, 19), false, false), // 623
	World_object::Scenery_part(jgl::Vector2Int(16, 19),  false, true), // 624
	World_object::Scenery_part(jgl::Vector2Int(17, 19),  false, true), // 625
	World_object::Scenery_part(jgl::Vector2Int(18, 19),  false, true), // 626
	World_object::Scenery_part(jgl::Vector2Int(19, 19),  false, true), // 627
	World_object::Scenery_part(jgl::Vector2Int(20, 19),  false, true), // 628
	World_object::Scenery_part(jgl::Vector2Int(21, 19),  false, true), // 629
	World_object::Scenery_part(jgl::Vector2Int(22, 19),  false, true), // -- 630
	World_object::Scenery_part(jgl::Vector2Int(23, 19),  false, true), // 631
	World_object::Scenery_part(jgl::Vector2Int(24, 19),  false, true), // 632
	World_object::Scenery_part(jgl::Vector2Int(25, 19),  false, true), // 633
	World_object::Scenery_part(jgl::Vector2Int(26, 19),  false, true), // 634
	World_object::Scenery_part(jgl::Vector2Int(27, 19),  false, true), // 635
	World_object::Scenery_part(jgl::Vector2Int(28, 19),  false, true), // 636
	World_object::Scenery_part(jgl::Vector2Int(29, 19),  false, true), // 637
	World_object::Scenery_part(jgl::Vector2Int(30, 19),  false, true), // 638
	World_object::Scenery_part(jgl::Vector2Int(31, 19),  false, true), // 639
	World_object::Scenery_part(jgl::Vector2Int( 0, 20),  false, true), // -- 640
	World_object::Scenery_part(jgl::Vector2Int( 1, 20),  false, true), // 641
	World_object::Scenery_part(jgl::Vector2Int( 2, 20),  false, true), // 642
	World_object::Scenery_part(jgl::Vector2Int( 3, 20),  false, true), // 643
	World_object::Scenery_part(jgl::Vector2Int( 4, 20),  false, true), // 644
	World_object::Scenery_part(jgl::Vector2Int( 5, 20),  false, true), // 645
	World_object::Scenery_part(jgl::Vector2Int( 6, 20),  false, true), // 646
	World_object::Scenery_part(jgl::Vector2Int( 7, 20),  false, true), // 647
	World_object::Scenery_part(jgl::Vector2Int( 8, 20),  false, true), // 648
	World_object::Scenery_part(jgl::Vector2Int( 9, 20),  false, true), // 649
	World_object::Scenery_part(jgl::Vector2Int(10, 20),  false, true), // -- 650
	World_object::Scenery_part(jgl::Vector2Int(11, 20),  false, true), // 651
	World_object::Scenery_part(jgl::Vector2Int(12, 20),  false, true), // 652
	World_object::Scenery_part(jgl::Vector2Int(13, 20),  false, true), // 653
	World_object::Scenery_part(jgl::Vector2Int(14, 20),  false, true), // 654
	World_object::Scenery_part(jgl::Vector2Int(15, 20),  false, true), // 655
	World_object::Scenery_part(jgl::Vector2Int(16, 20),  false, true), // 656
	World_object::Scenery_part(jgl::Vector2Int(17, 20),  false, true), // 657
	World_object::Scenery_part(jgl::Vector2Int(18, 20),  false, true), // 658
	World_object::Scenery_part(jgl::Vector2Int(19, 20),  false, true), // 659
	World_object::Scenery_part(jgl::Vector2Int(20, 20),  false, true), // -- 660
	World_object::Scenery_part(jgl::Vector2Int(21, 20),  false, true), // 661
	World_object::Scenery_part(jgl::Vector2Int(22, 20),  false, true), // 662
	World_object::Scenery_part(jgl::Vector2Int(23, 20),  false, true), // 663
	World_object::Scenery_part(jgl::Vector2Int(24, 20),  false, true), // 664
	World_object::Scenery_part(jgl::Vector2Int(25, 20),  false, true), // 665
	World_object::Scenery_part(jgl::Vector2Int(26, 20),  false, true), // 666
	World_object::Scenery_part(jgl::Vector2Int(27, 20),  false, true), // 667
	World_object::Scenery_part(jgl::Vector2Int(28, 20),  false, true), // 668
	World_object::Scenery_part(jgl::Vector2Int(29, 20),  false, true), // 669
	World_object::Scenery_part(jgl::Vector2Int(30, 20),  false, true), // -- 670
	World_object::Scenery_part(jgl::Vector2Int(31, 20),  false, true), // 671
	World_object::Scenery_part(jgl::Vector2Int( 0, 21), false, false), // 672
	World_object::Scenery_part(jgl::Vector2Int( 1, 21), false, false), // 673
	World_object::Scenery_part(jgl::Vector2Int( 2, 21), false, false), // 674
	World_object::Scenery_part(jgl::Vector2Int( 3, 21), false, false), // 675
	World_object::Scenery_part(jgl::Vector2Int( 4, 21), false, false), // 676
	World_object::Scenery_part(jgl::Vector2Int( 5, 21), false, false), // 677
	World_object::Scenery_part(jgl::Vector2Int( 6, 21), false, false), // 678
	World_object::Scenery_part(jgl::Vector2Int( 7, 21), false, false), // 679
	World_object::Scenery_part(jgl::Vector2Int( 8, 21), false, false), // -- 680
	World_object::Scenery_part(jgl::Vector2Int( 9, 21), false, false), // 681
	World_object::Scenery_part(jgl::Vector2Int(10, 21), false, false), // 682
	World_object::Scenery_part(jgl::Vector2Int(11, 21), false, false), // 683
	World_object::Scenery_part(jgl::Vector2Int(12, 21), false, false), // 684
	World_object::Scenery_part(jgl::Vector2Int(13, 21), false, false), // 685
	World_object::Scenery_part(jgl::Vector2Int(14, 21), false, false), // 686
	World_object::Scenery_part(jgl::Vector2Int(15, 21), false, false), // 687
	World_object::Scenery_part(jgl::Vector2Int(16, 21),  false, true), // 688
	World_object::Scenery_part(jgl::Vector2Int(17, 21),  false, true), // 689
	World_object::Scenery_part(jgl::Vector2Int(18, 21),  false, true), // -- 690
	World_object::Scenery_part(jgl::Vector2Int(19, 21),  false, true), // 691
	World_object::Scenery_part(jgl::Vector2Int(20, 21),  false, true), // 692
	World_object::Scenery_part(jgl::Vector2Int(21, 21),  false, true), // 693
	World_object::Scenery_part(jgl::Vector2Int(22, 21),  false, true), // 694
	World_object::Scenery_part(jgl::Vector2Int(23, 21),  false, true), // 695
	World_object::Scenery_part(jgl::Vector2Int(24, 21),  false, true), // 696
	World_object::Scenery_part(jgl::Vector2Int(25, 21),  false, true), // 697
	World_object::Scenery_part(jgl::Vector2Int(26, 21),  false, true), // 698
	World_object::Scenery_part(jgl::Vector2Int(27, 21),  false, true), // 699
	World_object::Scenery_part(jgl::Vector2Int(28, 21),  false, true), // 	---- 700
	World_object::Scenery_part(jgl::Vector2Int(29, 21),  false, true), // 701
	World_object::Scenery_part(jgl::Vector2Int(30, 21),  false, true), // 702
	World_object::Scenery_part(jgl::Vector2Int(31, 21),  false, true), // 703
	World_object::Scenery_part(jgl::Vector2Int( 0, 22),  false, true), // 704
	World_object::Scenery_part(jgl::Vector2Int( 1, 22),  false, true), // 705
	World_object::Scenery_part(jgl::Vector2Int( 2, 22),  false, true), // 706
	World_object::Scenery_part(jgl::Vector2Int( 3, 22),  false, true), // 707
	World_object::Scenery_part(jgl::Vector2Int( 4, 22),  false, true), // 708
	World_object::Scenery_part(jgl::Vector2Int( 5, 22),  false, true), // 709
	World_object::Scenery_part(jgl::Vector2Int( 6, 22),  false, true), // -- 710
	World_object::Scenery_part(jgl::Vector2Int( 7, 22),  false, true), // 711
	World_object::Scenery_part(jgl::Vector2Int( 8, 22),  false, true), // 712
	World_object::Scenery_part(jgl::Vector2Int( 9, 22),  false, true), // 713
	World_object::Scenery_part(jgl::Vector2Int(10, 22),  false, true), // 714
	World_object::Scenery_part(jgl::Vector2Int(11, 22),  false, true), // 715
	World_object::Scenery_part(jgl::Vector2Int(12, 22),  false, true), // 716
	World_object::Scenery_part(jgl::Vector2Int(13, 22),  false, true), // 717
	World_object::Scenery_part(jgl::Vector2Int(14, 22),  false, true), // 718
	World_object::Scenery_part(jgl::Vector2Int(15, 22),  false, true), // 719
	World_object::Scenery_part(jgl::Vector2Int(16, 22),  false, true), // -- 720
	World_object::Scenery_part(jgl::Vector2Int(17, 22),  false, true), // 721
	World_object::Scenery_part(jgl::Vector2Int(18, 22),  false, true), // 722
	World_object::Scenery_part(jgl::Vector2Int(19, 22),  false, true), // 723
	World_object::Scenery_part(jgl::Vector2Int(20, 22),  false, true), // 724
	World_object::Scenery_part(jgl::Vector2Int(21, 22),  false, true), // 725
	World_object::Scenery_part(jgl::Vector2Int(22, 22),  false, true), // 726
	World_object::Scenery_part(jgl::Vector2Int(23, 22),  false, true), // 727
	World_object::Scenery_part(jgl::Vector2Int(24, 22),  false, true), // 728
	World_object::Scenery_part(jgl::Vector2Int(25, 22),  false, true), // 729
	World_object::Scenery_part(jgl::Vector2Int(26, 22),  false, true), // -- 730
	World_object::Scenery_part(jgl::Vector2Int(27, 22),  false, true), // 731
	World_object::Scenery_part(jgl::Vector2Int(28, 22),  false, true), // 732
	World_object::Scenery_part(jgl::Vector2Int(29, 22),  false, true), // 733
	World_object::Scenery_part(jgl::Vector2Int(30, 22),  false, true), // 734
	World_object::Scenery_part(jgl::Vector2Int(31, 22),  false, true), // 735
	World_object::Scenery_part(jgl::Vector2Int( 0, 23), false, false), // 736
	World_object::Scenery_part(jgl::Vector2Int( 1, 23), false, false), // 737
	World_object::Scenery_part(jgl::Vector2Int( 2, 23), false, false), // 738
	World_object::Scenery_part(jgl::Vector2Int( 3, 23), false, false), // 739
	World_object::Scenery_part(jgl::Vector2Int( 4, 23), false, false), // -- 740
	World_object::Scenery_part(jgl::Vector2Int( 5, 23), false, false), // 741
	World_object::Scenery_part(jgl::Vector2Int( 6, 23), false, false), // 742
	World_object::Scenery_part(jgl::Vector2Int( 7, 23), false, false), // 743
	World_object::Scenery_part(jgl::Vector2Int( 8, 23), false, false), // 744
	World_object::Scenery_part(jgl::Vector2Int( 9, 23), false, false), // 745
	World_object::Scenery_part(jgl::Vector2Int(10, 23), false, false), // 746
	World_object::Scenery_part(jgl::Vector2Int(11, 23), false, false), // 747
	World_object::Scenery_part(jgl::Vector2Int(12, 23), false, false), // 748
	World_object::Scenery_part(jgl::Vector2Int(13, 23), false, false), // 749
	World_object::Scenery_part(jgl::Vector2Int(14, 23), false, false), // -- 750
	World_object::Scenery_part(jgl::Vector2Int(15, 23), false, false), // 751
	World_object::Scenery_part(jgl::Vector2Int(16, 23),  false, true), // 752
	World_object::Scenery_part(jgl::Vector2Int(17, 23),  false, true), // 753
	World_object::Scenery_part(jgl::Vector2Int(18, 23),  false, true), // 754
	World_object::Scenery_part(jgl::Vector2Int(19, 23),  false, true), // 755
	World_object::Scenery_part(jgl::Vector2Int(20, 23),  false, true), // 756
	World_object::Scenery_part(jgl::Vector2Int(21, 23),  false, true), // 757
	World_object::Scenery_part(jgl::Vector2Int(22, 23),  false, true), // 758
	World_object::Scenery_part(jgl::Vector2Int(23, 23),  false, true), // 759
	World_object::Scenery_part(jgl::Vector2Int(24, 23),  false, true), // -- 760
	World_object::Scenery_part(jgl::Vector2Int(25, 23),  false, true), // 761
	World_object::Scenery_part(jgl::Vector2Int(26, 23),  false, true), // 762
	World_object::Scenery_part(jgl::Vector2Int(27, 23),  false, true), // 763
	World_object::Scenery_part(jgl::Vector2Int(28, 23),  false, true), // 764
	World_object::Scenery_part(jgl::Vector2Int(29, 23),  false, true), // 765
	World_object::Scenery_part(jgl::Vector2Int(30, 23),  false, true), // 766
	World_object::Scenery_part(jgl::Vector2Int(31, 23),  false, true), // 767
	World_object::Scenery_part(jgl::Vector2Int( 0, 24),  false, true), // 768
	World_object::Scenery_part(jgl::Vector2Int( 1, 24),  false, true), // 769
	World_object::Scenery_part(jgl::Vector2Int( 2, 24),  false, true), // -- 770
	World_object::Scenery_part(jgl::Vector2Int( 3, 24),  false, true), // 771
	World_object::Scenery_part(jgl::Vector2Int( 4, 24),  false, true), // 772
	World_object::Scenery_part(jgl::Vector2Int( 5, 24),  false, true), // 773
	World_object::Scenery_part(jgl::Vector2Int( 6, 24),  false, true), // 774
	World_object::Scenery_part(jgl::Vector2Int( 7, 24),  false, true), // 775
	World_object::Scenery_part(jgl::Vector2Int( 8, 24),  false, true), // 776
	World_object::Scenery_part(jgl::Vector2Int( 9, 24),  false, true), // 777
	World_object::Scenery_part(jgl::Vector2Int(10, 24),  false, true), // 778
	World_object::Scenery_part(jgl::Vector2Int(11, 24),  false, true), // 779
	World_object::Scenery_part(jgl::Vector2Int(12, 24),  false, true), // -- 780
	World_object::Scenery_part(jgl::Vector2Int(13, 24),  false, true), // 781
	World_object::Scenery_part(jgl::Vector2Int(14, 24),  false, true), // 782
	World_object::Scenery_part(jgl::Vector2Int(15, 24),  false, true), // 783
	World_object::Scenery_part(jgl::Vector2Int(16, 24),  false, true), // 784
	World_object::Scenery_part(jgl::Vector2Int(17, 24),  false, true), // 785
	World_object::Scenery_part(jgl::Vector2Int(18, 24),  false, true), // 786
	World_object::Scenery_part(jgl::Vector2Int(19, 24),  false, true), // 787
	World_object::Scenery_part(jgl::Vector2Int(20, 24),  false, true), // 788
	World_object::Scenery_part(jgl::Vector2Int(21, 24),  false, true), // 789
	World_object::Scenery_part(jgl::Vector2Int(22, 24),  false, true), // -- 790
	World_object::Scenery_part(jgl::Vector2Int(23, 24),  false, true), // 791
	World_object::Scenery_part(jgl::Vector2Int(24, 24),  false, true), // 792
	World_object::Scenery_part(jgl::Vector2Int(25, 24),  false, true), // 793
	World_object::Scenery_part(jgl::Vector2Int(26, 24),  false, true), // 794
	World_object::Scenery_part(jgl::Vector2Int(27, 24),  false, true), // 795
	World_object::Scenery_part(jgl::Vector2Int(28, 24),  false, true), // 796
	World_object::Scenery_part(jgl::Vector2Int(29, 24),  false, true), // 797
	World_object::Scenery_part(jgl::Vector2Int(30, 24),  false, true), // 798
	World_object::Scenery_part(jgl::Vector2Int(31, 24),  false, true), // 799
	World_object::Scenery_part(jgl::Vector2Int( 0, 25), false, false), // 	---- 800
	World_object::Scenery_part(jgl::Vector2Int( 1, 25), false, false), // 801
	World_object::Scenery_part(jgl::Vector2Int( 2, 25), false, false), // 802
	World_object::Scenery_part(jgl::Vector2Int( 3, 25), false, false), // 803
	World_object::Scenery_part(jgl::Vector2Int( 4, 25), false, false), // 804
	World_object::Scenery_part(jgl::Vector2Int( 5, 25), false, false), // 805
	World_object::Scenery_part(jgl::Vector2Int( 6, 25), false, false), // 806
	World_object::Scenery_part(jgl::Vector2Int( 7, 25), false, false), // 807
	World_object::Scenery_part(jgl::Vector2Int( 8, 25),  false, true), // 808
	World_object::Scenery_part(jgl::Vector2Int( 9, 25),  false, true), // 809
	World_object::Scenery_part(jgl::Vector2Int(10, 25),  false, true), // -- 810
	World_object::Scenery_part(jgl::Vector2Int(11, 25),  false, true), // 811
	World_object::Scenery_part(jgl::Vector2Int(12, 25),  false, true), // 812
	World_object::Scenery_part(jgl::Vector2Int(13, 25),  false, true), // 813
	World_object::Scenery_part(jgl::Vector2Int(14, 25),  false, true), // 814
	World_object::Scenery_part(jgl::Vector2Int(15, 25),  false, true), // 815
	World_object::Scenery_part(jgl::Vector2Int(16, 25),  false, true), // 816
	World_object::Scenery_part(jgl::Vector2Int(17, 25),  false, true), // 817
	World_object::Scenery_part(jgl::Vector2Int(18, 25),  false, true), // 818
	World_object::Scenery_part(jgl::Vector2Int(19, 25),  false, true), // 819
	World_object::Scenery_part(jgl::Vector2Int(20, 25),  false, true), // -- 820
	World_object::Scenery_part(jgl::Vector2Int(21, 25),  false, true), // 821
	World_object::Scenery_part(jgl::Vector2Int(22, 25),  false, true), // 822
	World_object::Scenery_part(jgl::Vector2Int(23, 25),  false, true), // 823
	World_object::Scenery_part(jgl::Vector2Int(24, 25),  false, true), // 824
	World_object::Scenery_part(jgl::Vector2Int(25, 25),  false, true), // 825
	World_object::Scenery_part(jgl::Vector2Int(26, 25),  false, true), // 826
	World_object::Scenery_part(jgl::Vector2Int(27, 25),  false, true), // 827
	World_object::Scenery_part(jgl::Vector2Int(28, 25),  false, true), // 828
	World_object::Scenery_part(jgl::Vector2Int(29, 25),  false, true), // 829
	World_object::Scenery_part(jgl::Vector2Int(30, 25),  false, true), // -- 830
	World_object::Scenery_part(jgl::Vector2Int(31, 25),  false, true), // 831
	World_object::Scenery_part(jgl::Vector2Int( 0, 26), false, false), // 832
	World_object::Scenery_part(jgl::Vector2Int( 1, 26), false, false), // 833
	World_object::Scenery_part(jgl::Vector2Int( 2, 26), false, false), // 834
	World_object::Scenery_part(jgl::Vector2Int( 3, 26), false, false), // 835
	World_object::Scenery_part(jgl::Vector2Int( 4, 26), false, false), // 836
	World_object::Scenery_part(jgl::Vector2Int( 5, 26), false, false), // 837
	World_object::Scenery_part(jgl::Vector2Int( 6, 26), false, false), // 838
	World_object::Scenery_part(jgl::Vector2Int( 7, 26), false, false), // 839
	World_object::Scenery_part(jgl::Vector2Int( 8, 26), false, false), // -- 840
	World_object::Scenery_part(jgl::Vector2Int( 9, 26), false, false), // 841
	World_object::Scenery_part(jgl::Vector2Int(10, 26), false, false), // 842
	World_object::Scenery_part(jgl::Vector2Int(11, 26), false, false), // 843
	World_object::Scenery_part(jgl::Vector2Int(12, 26), false, false), // 844
	World_object::Scenery_part(jgl::Vector2Int(13, 26), false, false), // 845
	World_object::Scenery_part(jgl::Vector2Int(14, 26), false, false), // 846
	World_object::Scenery_part(jgl::Vector2Int(15, 26), false, false), // 847
	World_object::Scenery_part(jgl::Vector2Int(16, 26),  false, true), // 848
	World_object::Scenery_part(jgl::Vector2Int(17, 26),  false, true), // 849
	World_object::Scenery_part(jgl::Vector2Int(18, 26),  false, true), // -- 850
	World_object::Scenery_part(jgl::Vector2Int(19, 26),  false, true), // 851
	World_object::Scenery_part(jgl::Vector2Int(20, 26),  false, true), // 852
	World_object::Scenery_part(jgl::Vector2Int(21, 26),  false, true), // 853
	World_object::Scenery_part(jgl::Vector2Int(22, 26),  false, true), // 854
	World_object::Scenery_part(jgl::Vector2Int(23, 26),  false, true), // 855
	World_object::Scenery_part(jgl::Vector2Int(24, 26),  false, true), // 856
	World_object::Scenery_part(jgl::Vector2Int(25, 26),  false, true), // 857
	World_object::Scenery_part(jgl::Vector2Int(26, 26),  false, true), // 858
	World_object::Scenery_part(jgl::Vector2Int(27, 26),  false, true), // 859
	World_object::Scenery_part(jgl::Vector2Int(28, 26),  false, true), // -- 860
	World_object::Scenery_part(jgl::Vector2Int(29, 26),  false, true), // 861
	World_object::Scenery_part(jgl::Vector2Int(30, 26),  false, true), // 862
	World_object::Scenery_part(jgl::Vector2Int(31, 26),  false, true), // 863
	World_object::Scenery_part(jgl::Vector2Int( 0, 27), false, false), // 864
	World_object::Scenery_part(jgl::Vector2Int( 1, 27), false, false), // 865
	World_object::Scenery_part(jgl::Vector2Int( 2, 27), false, false), // 866
	World_object::Scenery_part(jgl::Vector2Int( 3, 27), false, false), // 867
	World_object::Scenery_part(jgl::Vector2Int( 4, 27), false, false), // 868
	World_object::Scenery_part(jgl::Vector2Int( 5, 27), false, false), // 869
	World_object::Scenery_part(jgl::Vector2Int( 6, 27), false, false), // -- 870
	World_object::Scenery_part(jgl::Vector2Int( 7, 27), false, false), // 871
	World_object::Scenery_part(jgl::Vector2Int( 8, 27),  false, true), // 872
	World_object::Scenery_part(jgl::Vector2Int( 9, 27),  false, true), // 873
	World_object::Scenery_part(jgl::Vector2Int(10, 27),  false, true), // 874
	World_object::Scenery_part(jgl::Vector2Int(11, 27),  false, true), // 875
	World_object::Scenery_part(jgl::Vector2Int(12, 27),  false, true), // 876
	World_object::Scenery_part(jgl::Vector2Int(13, 27),  false, true), // 877
	World_object::Scenery_part(jgl::Vector2Int(14, 27),  false, true), // 878
	World_object::Scenery_part(jgl::Vector2Int(15, 27),  false, true), // 879
	World_object::Scenery_part(jgl::Vector2Int(16, 27),  false, true), // -- 880
	World_object::Scenery_part(jgl::Vector2Int(17, 27),  false, true), // 881
	World_object::Scenery_part(jgl::Vector2Int(18, 27),  false, true), // 882
	World_object::Scenery_part(jgl::Vector2Int(19, 27),  false, true), // 883
	World_object::Scenery_part(jgl::Vector2Int(20, 27),  false, true), // 884
	World_object::Scenery_part(jgl::Vector2Int(21, 27),  false, true), // 885
	World_object::Scenery_part(jgl::Vector2Int(22, 27),  false, true), // 886
	World_object::Scenery_part(jgl::Vector2Int(23, 27),  false, true), // 887
	World_object::Scenery_part(jgl::Vector2Int(24, 27),  false, true), // 888
	World_object::Scenery_part(jgl::Vector2Int(25, 27),  false, true), // 889
	World_object::Scenery_part(jgl::Vector2Int(26, 27),  false, true), // -- 890
	World_object::Scenery_part(jgl::Vector2Int(27, 27),  false, true), // 891
	World_object::Scenery_part(jgl::Vector2Int(28, 27),  false, true), // 892
	World_object::Scenery_part(jgl::Vector2Int(29, 27),  false, true), // 893
	World_object::Scenery_part(jgl::Vector2Int(30, 27),  false, true), // 894
	World_object::Scenery_part(jgl::Vector2Int(31, 27),  false, true), // 895
	World_object::Scenery_part(jgl::Vector2Int( 0, 28),  false, true), // 896
	World_object::Scenery_part(jgl::Vector2Int( 1, 28),  false, true), // 897
	World_object::Scenery_part(jgl::Vector2Int( 2, 28),  false, true), // 898
	World_object::Scenery_part(jgl::Vector2Int( 3, 28),  false, true), // 899
	World_object::Scenery_part(jgl::Vector2Int( 4, 28),  false, true), // 	---- 900
	World_object::Scenery_part(jgl::Vector2Int( 5, 28),  false, true), // 901
	World_object::Scenery_part(jgl::Vector2Int( 6, 28),  false, true), // 902
	World_object::Scenery_part(jgl::Vector2Int( 7, 28),  false, true), // 903
	World_object::Scenery_part(jgl::Vector2Int( 8, 28),  false, true), // 904
	World_object::Scenery_part(jgl::Vector2Int( 9, 28),  false, true), // 905
	World_object::Scenery_part(jgl::Vector2Int(10, 28),  false, true), // 906
	World_object::Scenery_part(jgl::Vector2Int(11, 28),  false, true), // 907
	World_object::Scenery_part(jgl::Vector2Int(12, 28),  false, true), // 908
	World_object::Scenery_part(jgl::Vector2Int(13, 28),  false, true), // 909
	World_object::Scenery_part(jgl::Vector2Int(14, 28),  false, true), // -- 910
	World_object::Scenery_part(jgl::Vector2Int(15, 28),  false, true), // 911
	World_object::Scenery_part(jgl::Vector2Int(16, 28),  false, true), // 912
	World_object::Scenery_part(jgl::Vector2Int(17, 28),  false, true), // 913
	World_object::Scenery_part(jgl::Vector2Int(18, 28),  false, true), // 914
	World_object::Scenery_part(jgl::Vector2Int(19, 28),  false, true), // 915
	World_object::Scenery_part(jgl::Vector2Int(20, 28),  false, true), // 916
	World_object::Scenery_part(jgl::Vector2Int(21, 28),  false, true), // 917
	World_object::Scenery_part(jgl::Vector2Int(22, 28),  false, true), // 918
	World_object::Scenery_part(jgl::Vector2Int(23, 28),  false, true), // 919
	World_object::Scenery_part(jgl::Vector2Int(24, 28),  false, true), // -- 920
	World_object::Scenery_part(jgl::Vector2Int(25, 28),  false, true), // 921
	World_object::Scenery_part(jgl::Vector2Int(26, 28),  false, true), // 922
	World_object::Scenery_part(jgl::Vector2Int(27, 28),  false, true), // 923
	World_object::Scenery_part(jgl::Vector2Int(28, 28),  false, true), // 924
	World_object::Scenery_part(jgl::Vector2Int(29, 28),  false, true), // 925
	World_object::Scenery_part(jgl::Vector2Int(30, 28),  false, true), // 926
	World_object::Scenery_part(jgl::Vector2Int(31, 28),  false, true), // 927
	World_object::Scenery_part(jgl::Vector2Int( 0, 29), false, false), // 928
	World_object::Scenery_part(jgl::Vector2Int( 1, 29), false, false), // 929
	World_object::Scenery_part(jgl::Vector2Int( 2, 29), false, false), // -- 930
	World_object::Scenery_part(jgl::Vector2Int( 3, 29), false, false), // 931
	World_object::Scenery_part(jgl::Vector2Int( 4, 29), false, false), // 932
	World_object::Scenery_part(jgl::Vector2Int( 5, 29), false, false), // 933
	World_object::Scenery_part(jgl::Vector2Int( 6, 29), false, false), // 934
	World_object::Scenery_part(jgl::Vector2Int( 7, 29), false, false), // 935
	World_object::Scenery_part(jgl::Vector2Int( 8, 29),  false, true), // 936
	World_object::Scenery_part(jgl::Vector2Int( 9, 29),  false, true), // 937
	World_object::Scenery_part(jgl::Vector2Int(10, 29),  false, true), // 938
	World_object::Scenery_part(jgl::Vector2Int(11, 29),  false, true), // 939
	World_object::Scenery_part(jgl::Vector2Int(12, 29),  false, true), // -- 940
	World_object::Scenery_part(jgl::Vector2Int(13, 29),  false, true), // 941
	World_object::Scenery_part(jgl::Vector2Int(14, 29),  false, true), // 942
	World_object::Scenery_part(jgl::Vector2Int(15, 29),  false, true), // 943
	World_object::Scenery_part(jgl::Vector2Int(16, 29),  false, true), // 944
	World_object::Scenery_part(jgl::Vector2Int(17, 29),  false, true), // 945
	World_object::Scenery_part(jgl::Vector2Int(18, 29),  false, true), // 946
	World_object::Scenery_part(jgl::Vector2Int(19, 29),  false, true), // 947
	World_object::Scenery_part(jgl::Vector2Int(20, 29),  false, true), // 948
	World_object::Scenery_part(jgl::Vector2Int(21, 29),  false, true), // 949
	World_object::Scenery_part(jgl::Vector2Int(22, 29),  false, true), // -- 950
	World_object::Scenery_part(jgl::Vector2Int(23, 29),  false, true), // 951
	World_object::Scenery_part(jgl::Vector2Int(24, 29),  false, true), // 952
	World_object::Scenery_part(jgl::Vector2Int(25, 29),  false, true), // 953
	World_object::Scenery_part(jgl::Vector2Int(26, 29),  false, true), // 954
	World_object::Scenery_part(jgl::Vector2Int(27, 29),  false, true), // 955
	World_object::Scenery_part(jgl::Vector2Int(28, 29),  false, true), // 956
	World_object::Scenery_part(jgl::Vector2Int(29, 29),  false, true), // 957
	World_object::Scenery_part(jgl::Vector2Int(30, 29),  false, true), // 958
	World_object::Scenery_part(jgl::Vector2Int(31, 29),  false, true), // 959
	World_object::Scenery_part(jgl::Vector2Int( 0, 30),  false, true), // -- 960
	World_object::Scenery_part(jgl::Vector2Int( 1, 30),  false, true), // 961
	World_object::Scenery_part(jgl::Vector2Int( 2, 30),  false, true), // 962
	World_object::Scenery_part(jgl::Vector2Int( 3, 30),  false, true), // 963
	World_object::Scenery_part(jgl::Vector2Int( 4, 30),  false, true), // 964
	World_object::Scenery_part(jgl::Vector2Int( 5, 30),  false, true), // 965
	World_object::Scenery_part(jgl::Vector2Int( 6, 30),  false, true), // 966
	World_object::Scenery_part(jgl::Vector2Int( 7, 30),  false, true), // 967
	World_object::Scenery_part(jgl::Vector2Int( 8, 30),  false, true), // 968
	World_object::Scenery_part(jgl::Vector2Int( 9, 30),  false, true), // 969
	World_object::Scenery_part(jgl::Vector2Int(10, 30),  false, true), // -- 970
	World_object::Scenery_part(jgl::Vector2Int(11, 30),  false, true), // 971
	World_object::Scenery_part(jgl::Vector2Int(12, 30),  false, true), // 972
	World_object::Scenery_part(jgl::Vector2Int(13, 30),  false, true), // 973
	World_object::Scenery_part(jgl::Vector2Int(14, 30),  false, true), // 974
	World_object::Scenery_part(jgl::Vector2Int(15, 30),  false, true), // 975
	World_object::Scenery_part(jgl::Vector2Int(16, 30),  false, true), // 976
	World_object::Scenery_part(jgl::Vector2Int(17, 30),  false, true), // 977
	World_object::Scenery_part(jgl::Vector2Int(18, 30),  false, true), // 978
	World_object::Scenery_part(jgl::Vector2Int(19, 30),  false, true), // 979
	World_object::Scenery_part(jgl::Vector2Int(20, 30),  false, true), // -- 980
	World_object::Scenery_part(jgl::Vector2Int(21, 30),  false, true), // 981
	World_object::Scenery_part(jgl::Vector2Int(22, 30),  false, true), // 982
	World_object::Scenery_part(jgl::Vector2Int(23, 30),  false, true), // 983
	World_object::Scenery_part(jgl::Vector2Int(24, 30),  false, true), // 984
	World_object::Scenery_part(jgl::Vector2Int(25, 30),  false, true), // 985
	World_object::Scenery_part(jgl::Vector2Int(26, 30),  false, true), // 986
	World_object::Scenery_part(jgl::Vector2Int(27, 30),  false, true), // 987
	World_object::Scenery_part(jgl::Vector2Int(28, 30),  false, true), // 988
	World_object::Scenery_part(jgl::Vector2Int(29, 30),  false, true), // 989
	World_object::Scenery_part(jgl::Vector2Int(30, 30),  false, true), // -- 990
	World_object::Scenery_part(jgl::Vector2Int(31, 30),  false, true), // 991
	World_object::Scenery_part(jgl::Vector2Int( 0, 31), false, false), // 992
	World_object::Scenery_part(jgl::Vector2Int( 1, 31), false, false), // 993
	World_object::Scenery_part(jgl::Vector2Int( 2, 31), false, false), // 994
	World_object::Scenery_part(jgl::Vector2Int( 3, 31), false, false), // 995
	World_object::Scenery_part(jgl::Vector2Int( 4, 31), false, false), // 996
	World_object::Scenery_part(jgl::Vector2Int( 5, 31), false, false), // 997
	World_object::Scenery_part(jgl::Vector2Int( 6, 31),  false, true), // 998
	World_object::Scenery_part(jgl::Vector2Int( 7, 31),  false, true), // 999
	World_object::Scenery_part(jgl::Vector2Int( 8, 31),  false, true), // 	---- 1000
	World_object::Scenery_part(jgl::Vector2Int( 9, 31),  false, true), // 1001
	World_object::Scenery_part(jgl::Vector2Int(10, 31),  false, true), // 1002
	World_object::Scenery_part(jgl::Vector2Int(11, 31),  false, true), // 1003
	World_object::Scenery_part(jgl::Vector2Int(12, 31),  false, true), // 1004
	World_object::Scenery_part(jgl::Vector2Int(13, 31),  false, true), // 1005
	World_object::Scenery_part(jgl::Vector2Int(14, 31),  false, true), // 1006
	World_object::Scenery_part(jgl::Vector2Int(15, 31),  false, true), // 1007
	World_object::Scenery_part(jgl::Vector2Int(16, 31),  false, true), // 1008
	World_object::Scenery_part(jgl::Vector2Int(17, 31),  false, true), // 1009
	World_object::Scenery_part(jgl::Vector2Int(18, 31),  false, true), // -- 1010
	World_object::Scenery_part(jgl::Vector2Int(19, 31),  false, true), // 1011
	World_object::Scenery_part(jgl::Vector2Int(20, 31),  false, true), // 1012
	World_object::Scenery_part(jgl::Vector2Int(21, 31),  false, true), // 1013
	World_object::Scenery_part(jgl::Vector2Int(22, 31),  false, true), // 1014
	World_object::Scenery_part(jgl::Vector2Int(23, 31),  false, true), // 1015
	World_object::Scenery_part(jgl::Vector2Int(24, 31),  false, true), // 1016
	World_object::Scenery_part(jgl::Vector2Int(25, 31),  false, true), // 1017
	World_object::Scenery_part(jgl::Vector2Int(26, 31),  false, true), // 1018
	World_object::Scenery_part(jgl::Vector2Int(27, 31),  false, true), // 1019
	World_object::Scenery_part(jgl::Vector2Int(28, 31),  false, true), // -- 1020
	World_object::Scenery_part(jgl::Vector2Int(29, 31),  false, true), // 1021
	World_object::Scenery_part(jgl::Vector2Int(30, 31),  false, true), // 1022
	World_object::Scenery_part(jgl::Vector2Int(31, 31),  false, true), // 1023
	World_object::Scenery_part(jgl::Vector2Int( 0, 32), false, false), // 1024
	World_object::Scenery_part(jgl::Vector2Int( 1, 32), false, false), // 1025
	World_object::Scenery_part(jgl::Vector2Int( 2, 32), false, false), // 1026
	World_object::Scenery_part(jgl::Vector2Int( 3, 32), false, false), // 1027
	World_object::Scenery_part(jgl::Vector2Int( 4, 32), false, false), // 1028
	World_object::Scenery_part(jgl::Vector2Int( 5, 32), false, false), // 1029
	World_object::Scenery_part(jgl::Vector2Int( 6, 32),  false, true), // -- 1030
	World_object::Scenery_part(jgl::Vector2Int( 7, 32),  false, true), // 1031
	World_object::Scenery_part(jgl::Vector2Int( 8, 32),  false, true), // 1032
	World_object::Scenery_part(jgl::Vector2Int( 9, 32),  false, true), // 1033
	World_object::Scenery_part(jgl::Vector2Int(10, 32),  false, true), // 1034
	World_object::Scenery_part(jgl::Vector2Int(11, 32),  false, true), // 1035
	World_object::Scenery_part(jgl::Vector2Int(12, 32),  false, true), // 1036
	World_object::Scenery_part(jgl::Vector2Int(13, 32),  false, true), // 1037
	World_object::Scenery_part(jgl::Vector2Int(14, 32),  false, true), // 1038
	World_object::Scenery_part(jgl::Vector2Int(15, 32),  false, true), // 1039
	World_object::Scenery_part(jgl::Vector2Int(16, 32),  false, true), // -- 1040
	World_object::Scenery_part(jgl::Vector2Int(17, 32),  false, true), // 1041
	World_object::Scenery_part(jgl::Vector2Int(18, 32),  false, true), // 1042
	World_object::Scenery_part(jgl::Vector2Int(19, 32),  false, true), // 1043
	World_object::Scenery_part(jgl::Vector2Int(20, 32),  false, true), // 1044
	World_object::Scenery_part(jgl::Vector2Int(21, 32),  false, true), // 1045
	World_object::Scenery_part(jgl::Vector2Int(22, 32),  false, true), // 1046
	World_object::Scenery_part(jgl::Vector2Int(23, 32),  false, true), // 1047
	World_object::Scenery_part(jgl::Vector2Int(24, 32),  false, true), // 1048
	World_object::Scenery_part(jgl::Vector2Int(25, 32),  false, true), // 1049
	World_object::Scenery_part(jgl::Vector2Int(26, 32),  false, true), // -- 1050
	World_object::Scenery_part(jgl::Vector2Int(27, 32),  false, true), // 1051
	World_object::Scenery_part(jgl::Vector2Int(28, 32),  false, true), // 1052
	World_object::Scenery_part(jgl::Vector2Int(29, 32),  false, true), // 1053
	World_object::Scenery_part(jgl::Vector2Int(30, 32),  false, true), // 1054
	World_object::Scenery_part(jgl::Vector2Int(31, 32),  false, true), // 1055
	World_object::Scenery_part(jgl::Vector2Int( 0, 33),  false, true), // 1056
	World_object::Scenery_part(jgl::Vector2Int( 1, 33),  false, true), // 1057
	World_object::Scenery_part(jgl::Vector2Int( 2, 33),  false, true), // 1058
	World_object::Scenery_part(jgl::Vector2Int( 3, 33),  false, true), // 1059
	World_object::Scenery_part(jgl::Vector2Int( 4, 33),  false, true), // -- 1060
	World_object::Scenery_part(jgl::Vector2Int( 5, 33),  false, true), // 1061
	World_object::Scenery_part(jgl::Vector2Int( 6, 33),  false, true), // 1062
	World_object::Scenery_part(jgl::Vector2Int( 7, 33),  false, true), // 1063
	World_object::Scenery_part(jgl::Vector2Int( 8, 33), false, false), // 1064
	World_object::Scenery_part(jgl::Vector2Int( 9, 33), false, false), // 1065
	World_object::Scenery_part(jgl::Vector2Int(10, 33),  false, true), // 1066
	World_object::Scenery_part(jgl::Vector2Int(11, 33),  false, true), // 1067
	World_object::Scenery_part(jgl::Vector2Int(12, 33),  false, true), // 1068
	World_object::Scenery_part(jgl::Vector2Int(13, 33),  false, true), // 1069
	World_object::Scenery_part(jgl::Vector2Int(14, 33),  false, true), // -- 1070
	World_object::Scenery_part(jgl::Vector2Int(15, 33),  false, true), // 1071
	World_object::Scenery_part(jgl::Vector2Int(16, 33),  false, true), // 1072
	World_object::Scenery_part(jgl::Vector2Int(17, 33),  false, true), // 1073
	World_object::Scenery_part(jgl::Vector2Int(18, 33),  false, true), // 1074
	World_object::Scenery_part(jgl::Vector2Int(19, 33),  false, true), // 1075
	World_object::Scenery_part(jgl::Vector2Int(20, 33),  false, true), // 1076
	World_object::Scenery_part(jgl::Vector2Int(21, 33),  false, true), // 1077
	World_object::Scenery_part(jgl::Vector2Int(22, 33),  false, true), // 1078
	World_object::Scenery_part(jgl::Vector2Int(23, 33),  false, true), // 1079
	World_object::Scenery_part(jgl::Vector2Int(24, 33),  false, true), // -- 1080
	World_object::Scenery_part(jgl::Vector2Int(25, 33),  false, true), // 1081
	World_object::Scenery_part(jgl::Vector2Int(26, 33),  false, true), // 1082
	World_object::Scenery_part(jgl::Vector2Int(27, 33),  false, true), // 1083
	World_object::Scenery_part(jgl::Vector2Int(28, 33),  false, true), // 1084
	World_object::Scenery_part(jgl::Vector2Int(29, 33),  false, true), // 1085
	World_object::Scenery_part(jgl::Vector2Int(30, 33),  false, true), // 1086
	World_object::Scenery_part(jgl::Vector2Int(31, 33),  false, true), // 1087
	World_object::Scenery_part(jgl::Vector2Int( 0, 34),  false, true), // 1088
	World_object::Scenery_part(jgl::Vector2Int( 1, 34),  false, true), // 1089
	World_object::Scenery_part(jgl::Vector2Int( 2, 34),  false, true), // -- 1090
	World_object::Scenery_part(jgl::Vector2Int( 3, 34),  false, true), // 1091
	World_object::Scenery_part(jgl::Vector2Int( 4, 34),  false, true), // 1092
	World_object::Scenery_part(jgl::Vector2Int( 5, 34),  false, true), // 1093
	World_object::Scenery_part(jgl::Vector2Int( 6, 34),  false, true), // 1094
	World_object::Scenery_part(jgl::Vector2Int( 7, 34),  false, true), // 1095
	World_object::Scenery_part(jgl::Vector2Int( 8, 34),  false, true), // 1096
	World_object::Scenery_part(jgl::Vector2Int( 9, 34),  false, true), // 1097
	World_object::Scenery_part(jgl::Vector2Int(10, 34),  false, true), // 1098
	World_object::Scenery_part(jgl::Vector2Int(11, 34),  false, true), // 1099
	World_object::Scenery_part(jgl::Vector2Int(12, 34),  false, true), // 	---- 1100
	World_object::Scenery_part(jgl::Vector2Int(13, 34),  false, true), // 1101
	World_object::Scenery_part(jgl::Vector2Int(14, 34),  false, true), // 1102
	World_object::Scenery_part(jgl::Vector2Int(15, 34),  false, true), // 1103
	World_object::Scenery_part(jgl::Vector2Int(16, 34),  false, true, 4), // 1104
	World_object::Scenery_part(jgl::Vector2Int(17, 34),  false, true, 0), // 1105
	World_object::Scenery_part(jgl::Vector2Int(18, 34),  false, true, 0), // 1106
	World_object::Scenery_part(jgl::Vector2Int(19, 34),  false, true, 0), // 1107
	World_object::Scenery_part(jgl::Vector2Int(20, 34),  false, true), // 1108
	World_object::Scenery_part(jgl::Vector2Int(21, 34),  false, true), // 1109
	World_object::Scenery_part(jgl::Vector2Int(22, 34),  false, true), // -- 1110
	World_object::Scenery_part(jgl::Vector2Int(23, 34),  false, true), // 1111
	World_object::Scenery_part(jgl::Vector2Int(24, 34),  false, true), // 1112
	World_object::Scenery_part(jgl::Vector2Int(25, 34),  false, true), // 1113
	World_object::Scenery_part(jgl::Vector2Int(26, 34),  false, true), // 1114
	World_object::Scenery_part(jgl::Vector2Int(27, 34),  false, true), // 1115
	World_object::Scenery_part(jgl::Vector2Int(28, 34),  false, true), // 1116
	World_object::Scenery_part(jgl::Vector2Int(29, 34),  false, true), // 1117
	World_object::Scenery_part(jgl::Vector2Int(30, 34),  false, true), // 1118
	World_object::Scenery_part(jgl::Vector2Int(31, 34),  false, true), // 1119
	World_object::Scenery_part(jgl::Vector2Int( 0, 35),  false, true), // -- 1120
	World_object::Scenery_part(jgl::Vector2Int( 1, 35),  false, true), // 1121
	World_object::Scenery_part(jgl::Vector2Int( 2, 35),  false, true), // 1122
	World_object::Scenery_part(jgl::Vector2Int( 3, 35),  false, true), // 1123
	World_object::Scenery_part(jgl::Vector2Int( 4, 35),  false, true), // 1124
	World_object::Scenery_part(jgl::Vector2Int( 5, 35),  false, true), // 1125
	World_object::Scenery_part(jgl::Vector2Int( 6, 35),  false, true), // 1126
	World_object::Scenery_part(jgl::Vector2Int( 7, 35),  false, true), // 1127
	World_object::Scenery_part(jgl::Vector2Int( 8, 35), false, false), // 1128
	World_object::Scenery_part(jgl::Vector2Int( 9, 35), false, false), // 1129
	World_object::Scenery_part(jgl::Vector2Int(10, 35), false, false), // -- 1130
	World_object::Scenery_part(jgl::Vector2Int(11, 35), false, false), // 1131
	World_object::Scenery_part(jgl::Vector2Int(12, 35), false, false), // 1132
	World_object::Scenery_part(jgl::Vector2Int(13, 35), false, false), // 1133
	World_object::Scenery_part(jgl::Vector2Int(14, 35), false, false), // 1134
	World_object::Scenery_part(jgl::Vector2Int(15, 35), false, false), // 1135
	World_object::Scenery_part(jgl::Vector2Int(16, 35), false, false, 4), // 1136
	World_object::Scenery_part(jgl::Vector2Int(17, 35), false, false, 0), // 1137
	World_object::Scenery_part(jgl::Vector2Int(18, 35), false, false, 0), // 1138
	World_object::Scenery_part(jgl::Vector2Int(19, 35), false, false, 0), // 1139
	World_object::Scenery_part(jgl::Vector2Int(20, 35), false, false, 4), // -- 1140
	World_object::Scenery_part(jgl::Vector2Int(21, 35), false, false, 0), // 1141
	World_object::Scenery_part(jgl::Vector2Int(22, 35), false, false, 0), // 1142
	World_object::Scenery_part(jgl::Vector2Int(23, 35), false, false, 0), // 1143
	World_object::Scenery_part(jgl::Vector2Int(24, 35),  false, true), // 1144
	World_object::Scenery_part(jgl::Vector2Int(25, 35),  false, true), // 1145
	World_object::Scenery_part(jgl::Vector2Int(26, 35),  false, true), // 1146
	World_object::Scenery_part(jgl::Vector2Int(27, 35),  false, true), // 1147
	World_object::Scenery_part(jgl::Vector2Int(28, 35),  false, true), // 1148
	World_object::Scenery_part(jgl::Vector2Int(29, 35),  false, true), // 1149
	World_object::Scenery_part(jgl::Vector2Int(30, 35),  false, true), // -- 1150
	World_object::Scenery_part(jgl::Vector2Int(31, 35),  false, true), // 1151
	World_object::Scenery_part(jgl::Vector2Int( 0, 36),  false, true), // 1152
	World_object::Scenery_part(jgl::Vector2Int( 1, 36),  false, true), // 1153
	World_object::Scenery_part(jgl::Vector2Int( 2, 36),  false, true), // 1154
	World_object::Scenery_part(jgl::Vector2Int( 3, 36),  false, true), // 1155
	World_object::Scenery_part(jgl::Vector2Int( 4, 36),  false, true), // 1156
	World_object::Scenery_part(jgl::Vector2Int( 5, 36),  false, true), // 1157
	World_object::Scenery_part(jgl::Vector2Int( 6, 36),  false, true), // 1158
	World_object::Scenery_part(jgl::Vector2Int( 7, 36),  false, true), // 1159
	World_object::Scenery_part(jgl::Vector2Int( 8, 36),  false, true), // -- 1160
	World_object::Scenery_part(jgl::Vector2Int( 9, 36),  false, true), // 1161
	World_object::Scenery_part(jgl::Vector2Int(10, 36),  false, true), // 1162
	World_object::Scenery_part(jgl::Vector2Int(11, 36),  false, true), // 1163
	World_object::Scenery_part(jgl::Vector2Int(12, 36),  false, true), // 1164
	World_object::Scenery_part(jgl::Vector2Int(13, 36),  false, true), // 1165
	World_object::Scenery_part(jgl::Vector2Int(14, 36),  false, true), // 1166
	World_object::Scenery_part(jgl::Vector2Int(15, 36),  false, true), // 1167
	World_object::Scenery_part(jgl::Vector2Int(16, 36),  false, true), // 1168
	World_object::Scenery_part(jgl::Vector2Int(17, 36),  false, true), // 1169
	World_object::Scenery_part(jgl::Vector2Int(18, 36),  false, true), // -- 1170
	World_object::Scenery_part(jgl::Vector2Int(19, 36),  false, true), // 1171
	World_object::Scenery_part(jgl::Vector2Int(20, 36),  false, true), // 1172
	World_object::Scenery_part(jgl::Vector2Int(21, 36),  false, true), // 1173
	World_object::Scenery_part(jgl::Vector2Int(22, 36),  false, true), // 1174
	World_object::Scenery_part(jgl::Vector2Int(23, 36),  false, true), // 1175
	World_object::Scenery_part(jgl::Vector2Int(24, 36),  false, true), // 1176
	World_object::Scenery_part(jgl::Vector2Int(25, 36),  false, true), // 1177
	World_object::Scenery_part(jgl::Vector2Int(26, 36),  false, true), // 1178
	World_object::Scenery_part(jgl::Vector2Int(27, 36),  false, true), // 1179
	World_object::Scenery_part(jgl::Vector2Int(28, 36),  false, true), // -- 1180
	World_object::Scenery_part(jgl::Vector2Int(29, 36),  false, true), // 1181
	World_object::Scenery_part(jgl::Vector2Int(30, 36),  false, true), // 1182
	World_object::Scenery_part(jgl::Vector2Int(31, 36),  false, true), // 1183
	World_object::Scenery_part(jgl::Vector2Int( 0, 37),  false, true), // 1184
	World_object::Scenery_part(jgl::Vector2Int( 1, 37),  false, true), // 1185
	World_object::Scenery_part(jgl::Vector2Int( 2, 37),  false, true), // 1186
	World_object::Scenery_part(jgl::Vector2Int( 3, 37),  false, true), // 1187
	World_object::Scenery_part(jgl::Vector2Int( 4, 37),  false, true), // 1188
	World_object::Scenery_part(jgl::Vector2Int( 5, 37),  false, true), // 1189
	World_object::Scenery_part(jgl::Vector2Int( 6, 37),  false, true), // -- 1190
	World_object::Scenery_part(jgl::Vector2Int( 7, 37),  false, true), // 1191
	World_object::Scenery_part(jgl::Vector2Int( 8, 37),  false, true), // 1192
	World_object::Scenery_part(jgl::Vector2Int( 9, 37),  false, true), // 1193
	World_object::Scenery_part(jgl::Vector2Int(10, 37),  false, true), // 1194
	World_object::Scenery_part(jgl::Vector2Int(11, 37),  false, true), // 1195
	World_object::Scenery_part(jgl::Vector2Int(12, 37),  false, true), // 1196
	World_object::Scenery_part(jgl::Vector2Int(13, 37),  false, true), // 1197
	World_object::Scenery_part(jgl::Vector2Int(14, 37),  false, true), // 1198
	World_object::Scenery_part(jgl::Vector2Int(15, 37),  false, true), // 1199
	World_object::Scenery_part(jgl::Vector2Int(16, 37),  false, true, 4), // 	---- 1200
	World_object::Scenery_part(jgl::Vector2Int(17, 37),  false, true, 0), // 1201
	World_object::Scenery_part(jgl::Vector2Int(18, 37),  false, true, 0), // 1202
	World_object::Scenery_part(jgl::Vector2Int(19, 37),  false, true, 0), // 1203
	World_object::Scenery_part(jgl::Vector2Int(20, 37),  false, true, 4), // 1204
	World_object::Scenery_part(jgl::Vector2Int(21, 37),  false, true, 0), // 1205
	World_object::Scenery_part(jgl::Vector2Int(22, 37),  false, true, 0), // 1206
	World_object::Scenery_part(jgl::Vector2Int(23, 37),  false, true, 0), // 1207
	World_object::Scenery_part(jgl::Vector2Int(24, 37),  false, true), // 1208
	World_object::Scenery_part(jgl::Vector2Int(25, 37),  false, true), // 1209
	World_object::Scenery_part(jgl::Vector2Int(26, 37),  false, true), // -- 1210
	World_object::Scenery_part(jgl::Vector2Int(27, 37),  false, true), // 1211
	World_object::Scenery_part(jgl::Vector2Int(28, 37),  false, true), // 1212
	World_object::Scenery_part(jgl::Vector2Int(29, 37),  false, true), // 1213
	World_object::Scenery_part(jgl::Vector2Int(30, 37),  false, true), // 1214
	World_object::Scenery_part(jgl::Vector2Int(31, 37),  false, true), // 1215
	World_object::Scenery_part(jgl::Vector2Int( 0, 38),  false, true), // 1216
	World_object::Scenery_part(jgl::Vector2Int( 1, 38),  false, true), // 1217
	World_object::Scenery_part(jgl::Vector2Int( 2, 38),  false, true), // 1218
	World_object::Scenery_part(jgl::Vector2Int( 3, 38),  false, true), // 1219
	World_object::Scenery_part(jgl::Vector2Int( 4, 38),  false, true), // -- 1220
	World_object::Scenery_part(jgl::Vector2Int( 5, 38),  false, true), // 1221
	World_object::Scenery_part(jgl::Vector2Int( 6, 38),  false, true), // 1222
	World_object::Scenery_part(jgl::Vector2Int( 7, 38),  false, true), // 1223
	World_object::Scenery_part(jgl::Vector2Int( 8, 38),  false, true), // 1224
	World_object::Scenery_part(jgl::Vector2Int( 9, 38),  false, true), // 1225
	World_object::Scenery_part(jgl::Vector2Int(10, 38),  false, true), // 1226
	World_object::Scenery_part(jgl::Vector2Int(11, 38),  false, true), // 1227
	World_object::Scenery_part(jgl::Vector2Int(12, 38),  false, true), // 1228
	World_object::Scenery_part(jgl::Vector2Int(13, 38),  false, true), // 1229
	World_object::Scenery_part(jgl::Vector2Int(14, 38), false, false), // -- 1230
	World_object::Scenery_part(jgl::Vector2Int(15, 38), false, false), // 1231
	World_object::Scenery_part(jgl::Vector2Int(16, 38), false, false, 4), // 1232
	World_object::Scenery_part(jgl::Vector2Int(17, 38), false, false, 0), // 1233
	World_object::Scenery_part(jgl::Vector2Int(18, 38), false, false, 0), // 1234
	World_object::Scenery_part(jgl::Vector2Int(19, 38), false, false, 0), // 1235
	World_object::Scenery_part(jgl::Vector2Int(20, 38), false, false, 4), // 1236
	World_object::Scenery_part(jgl::Vector2Int(21, 38), false, false, 0), // 1237
	World_object::Scenery_part(jgl::Vector2Int(22, 38), false, false, 0), // 1238
	World_object::Scenery_part(jgl::Vector2Int(23, 38), false, false, 0), // 1239
	World_object::Scenery_part(jgl::Vector2Int(24, 38), false, false), // -- 1240
	World_object::Scenery_part(jgl::Vector2Int(25, 38), false, false), // 1241
	World_object::Scenery_part(jgl::Vector2Int(26, 38),  false, true), // 1242
	World_object::Scenery_part(jgl::Vector2Int(27, 38),  false, true), // 1243
	World_object::Scenery_part(jgl::Vector2Int(28, 38),  false, true), // 1244
	World_object::Scenery_part(jgl::Vector2Int(29, 38),  false, true), // 1245
	World_object::Scenery_part(jgl::Vector2Int(30, 38),  false, true), // 1246
	World_object::Scenery_part(jgl::Vector2Int(31, 38),  false, true), // 1247
	World_object::Scenery_part(jgl::Vector2Int( 0, 39), false, false), // 1248
	World_object::Scenery_part(jgl::Vector2Int( 1, 39), false, false), // 1249
	World_object::Scenery_part(jgl::Vector2Int( 2, 39), false, false), // -- 1250
	World_object::Scenery_part(jgl::Vector2Int( 3, 39), false, false), // 1251
	World_object::Scenery_part(jgl::Vector2Int( 4, 39), false, false), // 1252
	World_object::Scenery_part(jgl::Vector2Int( 5, 39), false, false), // 1253
	World_object::Scenery_part(jgl::Vector2Int( 6, 39), false, false), // 1254
	World_object::Scenery_part(jgl::Vector2Int( 7, 39), false, false), // 1255
	World_object::Scenery_part(jgl::Vector2Int( 8, 39),  false, true), // 1256
	World_object::Scenery_part(jgl::Vector2Int( 9, 39),  false, true), // 1257
	World_object::Scenery_part(jgl::Vector2Int(10, 39),  false, true), // 1258
	World_object::Scenery_part(jgl::Vector2Int(11, 39),  false, true), // 1259
	World_object::Scenery_part(jgl::Vector2Int(12, 39),  false, true), // -- 1260
	World_object::Scenery_part(jgl::Vector2Int(13, 39),  false, true), // 1261
	World_object::Scenery_part(jgl::Vector2Int(14, 39),  false, true), // 1262
	World_object::Scenery_part(jgl::Vector2Int(15, 39),  false, true), // 1263
	World_object::Scenery_part(jgl::Vector2Int(16, 39),  false, true), // 1264
	World_object::Scenery_part(jgl::Vector2Int(17, 39),  false, true), // 1265
	World_object::Scenery_part(jgl::Vector2Int(18, 39),  false, true), // 1266
	World_object::Scenery_part(jgl::Vector2Int(19, 39),  false, true), // 1267
	World_object::Scenery_part(jgl::Vector2Int(20, 39),  false, true), // 1268
	World_object::Scenery_part(jgl::Vector2Int(21, 39),  false, true), // 1269
	World_object::Scenery_part(jgl::Vector2Int(22, 39),  false, true), // -- 1270
	World_object::Scenery_part(jgl::Vector2Int(23, 39),  false, true), // 1271
	World_object::Scenery_part(jgl::Vector2Int(24, 39),  false, true), // 1272
	World_object::Scenery_part(jgl::Vector2Int(25, 39),  false, true), // 1273
	World_object::Scenery_part(jgl::Vector2Int(26, 39),  false, true), // 1274
	World_object::Scenery_part(jgl::Vector2Int(27, 39),  false, true), // 1275
	World_object::Scenery_part(jgl::Vector2Int(28, 39),  false, true), // 1276
	World_object::Scenery_part(jgl::Vector2Int(29, 39),  false, true), // 1277
	World_object::Scenery_part(jgl::Vector2Int(30, 39),  false, true), // 1278
	World_object::Scenery_part(jgl::Vector2Int(31, 39),  false, true), // 1279
	World_object::Scenery_part(jgl::Vector2Int( 0, 40),  false, true), // -- 1280
	World_object::Scenery_part(jgl::Vector2Int( 1, 40),  false, true), // 1281
	World_object::Scenery_part(jgl::Vector2Int( 2, 40),  false, true), // 1282
	World_object::Scenery_part(jgl::Vector2Int( 3, 40),  false, true), // 1283
	World_object::Scenery_part(jgl::Vector2Int( 4, 40),  false, true), // 1284
	World_object::Scenery_part(jgl::Vector2Int( 5, 40),  false, true), // 1285
	World_object::Scenery_part(jgl::Vector2Int( 6, 40),  false, true), // 1286
	World_object::Scenery_part(jgl::Vector2Int( 7, 40),  false, true), // 1287
	World_object::Scenery_part(jgl::Vector2Int( 8, 40),  false, true), // 1288
	World_object::Scenery_part(jgl::Vector2Int( 9, 40),  false, true), // 1289
	World_object::Scenery_part(jgl::Vector2Int(10, 40),  false, true), // -- 1290
	World_object::Scenery_part(jgl::Vector2Int(11, 40),  false, true), // 1291
	World_object::Scenery_part(jgl::Vector2Int(12, 40),  false, true), // 1292
	World_object::Scenery_part(jgl::Vector2Int(13, 40),  false, true), // 1293
	World_object::Scenery_part(jgl::Vector2Int(14, 40),  false, true), // 1294
	World_object::Scenery_part(jgl::Vector2Int(15, 40),  false, true), // 1295
	World_object::Scenery_part(jgl::Vector2Int(16, 40),  false, true), // 1296
	World_object::Scenery_part(jgl::Vector2Int(17, 40),  false, true), // 1297
	World_object::Scenery_part(jgl::Vector2Int(18, 40),  false, true), // 1298
	World_object::Scenery_part(jgl::Vector2Int(19, 40),  false, true), // 1299
	World_object::Scenery_part(jgl::Vector2Int(20, 40),  false, true), // 	---- 1300
	World_object::Scenery_part(jgl::Vector2Int(21, 40),  false, true), // 1301
	World_object::Scenery_part(jgl::Vector2Int(22, 40),  false, true), // 1302
	World_object::Scenery_part(jgl::Vector2Int(23, 40),  false, true), // 1303
	World_object::Scenery_part(jgl::Vector2Int(24, 40),  false, true), // 1304
	World_object::Scenery_part(jgl::Vector2Int(25, 40),  false, true), // 1305
	World_object::Scenery_part(jgl::Vector2Int(26, 40),  false, true), // 1306
	World_object::Scenery_part(jgl::Vector2Int(27, 40),  false, true), // 1307
	World_object::Scenery_part(jgl::Vector2Int(28, 40),  false, true), // 1308
	World_object::Scenery_part(jgl::Vector2Int(29, 40),  false, true), // 1309
	World_object::Scenery_part(jgl::Vector2Int(30, 40),  false, true), // -- 1310
	World_object::Scenery_part(jgl::Vector2Int(31, 40),  false, true), // 1311
	World_object::Scenery_part(jgl::Vector2Int( 0, 41),  false, true), // 1312
	World_object::Scenery_part(jgl::Vector2Int( 1, 41),  false, true), // 1313
	World_object::Scenery_part(jgl::Vector2Int( 2, 41),  false, true), // 1314
	World_object::Scenery_part(jgl::Vector2Int( 3, 41),  false, true), // 1315
	World_object::Scenery_part(jgl::Vector2Int( 4, 41),  false, true), // 1316
	World_object::Scenery_part(jgl::Vector2Int( 5, 41),  false, true), // 1317
	World_object::Scenery_part(jgl::Vector2Int( 6, 41),  false, true), // 1318
	World_object::Scenery_part(jgl::Vector2Int( 7, 41),  false, true), // 1319
	World_object::Scenery_part(jgl::Vector2Int( 8, 41),  false, true), // -- 1320
	World_object::Scenery_part(jgl::Vector2Int( 9, 41),  false, true), // 1321
	World_object::Scenery_part(jgl::Vector2Int(10, 41),  false, true), // 1322
	World_object::Scenery_part(jgl::Vector2Int(11, 41),  false, true), // 1323
	World_object::Scenery_part(jgl::Vector2Int(12, 41),  false, true), // 1324
	World_object::Scenery_part(jgl::Vector2Int(13, 41),  false, true), // 1325
	World_object::Scenery_part(jgl::Vector2Int(14, 41),  false, true), // 1326
	World_object::Scenery_part(jgl::Vector2Int(15, 41),  false, true), // 1327
	World_object::Scenery_part(jgl::Vector2Int(16, 41),  false, true), // 1328
	World_object::Scenery_part(jgl::Vector2Int(17, 41),  false, true), // 1329
	World_object::Scenery_part(jgl::Vector2Int(18, 41),  false, true), // -- 1330
	World_object::Scenery_part(jgl::Vector2Int(19, 41),  false, true), // 1331
	World_object::Scenery_part(jgl::Vector2Int(20, 41),  false, true), // 1332
	World_object::Scenery_part(jgl::Vector2Int(21, 41),  false, true), // 1333
	World_object::Scenery_part(jgl::Vector2Int(22, 41),  false, true), // 1334
	World_object::Scenery_part(jgl::Vector2Int(23, 41),  false, true), // 1335
	World_object::Scenery_part(jgl::Vector2Int(24, 41),  false, true), // 1336
	World_object::Scenery_part(jgl::Vector2Int(25, 41),  false, true), // 1337
	World_object::Scenery_part(jgl::Vector2Int(26, 41),  false, true), // 1338
	World_object::Scenery_part(jgl::Vector2Int(27, 41),  false, true), // 1339
	World_object::Scenery_part(jgl::Vector2Int(28, 41),  false, true), // -- 1340
	World_object::Scenery_part(jgl::Vector2Int(29, 41),  false, true), // 1341
	World_object::Scenery_part(jgl::Vector2Int(30, 41),  false, true), // 1342
	World_object::Scenery_part(jgl::Vector2Int(31, 41),  false, true), // 1343

};