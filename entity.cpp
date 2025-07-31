#include "entity.h"

inline uint8 entity_stats::entity_stat_assign()
{
	entity_choice = 1;
	position = { 0, 0 };
	health = 12;
}
void entity_draw::draw(v2 position)
{
	if (entity_type_pc)
	{
		DrawCircleV(position, 25, WHITE);

	}
}