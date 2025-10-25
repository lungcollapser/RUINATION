#include "entity.h"

extern uint16 entities = 0;
extern uint16 player_id = 0;
extern uint16 enemy_id = 1;
extern uint16 weapon_id = 2;
extern uint16 project_weapon_id = 3;
extern uint16 bullet_id = 4;
extern uint16 camera_id = 5;


uint16 AddEntity(uint16 ent_id)
{
	return ent_id = entities++;
}
uint16 AddComponents(uint16 component_type)
{
	return component_type++;
}
void DrawEntity(uint16 ent_id, v2 position_one, v2 position_two, float radius, Color color, component_lists* component)
{
	if (component->health_component[ent_id].current_health > 0)
	{
		DrawCircleV(position_one + position_two, radius, color);
	}
}
void DrawCollision(uint16 ent_id, Rectangle collision, v2 position_two, component_lists* component)
{
	if (component->health_component[ent_id].current_health > 0)
	{
		DrawRectangleLines(collision.x + position_two.x, collision.y + position_two.y, collision.width, collision.height, ORANGE);
	}
}
void UpdateEntityMovement(uint16 ent_id, component_lists* component)
{
	v2 direction = { 0.0f, 0.0f };

	if (IsKeyDown(KEY_D))
	{
		direction.x++;
	}
	if (IsKeyDown(KEY_A))
	{
		direction.x--;
	}
	if (IsKeyDown(KEY_W))
	{
		direction.y--;
	}
	if (IsKeyDown(KEY_S))
	{
		direction.y++;
	}

	v2 velocity = Vector2Scale(Vector2Normalize(direction), component->transform_component[ent_id].speed * GetFrameTime());
	component->transform_component[ent_id].ent_position = Vector2Add(component->transform_component[ent_id].ent_position, velocity);
}

void UpdateEntityWeapon(uint16 ent_id, component_lists* component)
{

}
void UpdateEntityProjectWeapon(uint16 ent_id, component_lists* component)
{
	component->transform_component[ent_id].ent_position = GetMousePosition();
	DrawCircleV(component->transform_component[ent_id].ent_position + component->transform_component[player_id].ent_position, component->transform_component[ent_id].radius, component->transform_component[ent_id].color);

}
void UpdateEntityBullet(uint16 ent_id, component_lists* component)
{


	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && component->bullet_component[project_weapon_id].ammunition > 0)
	{
		for (int i = 0; i < MAX_BULLETS; i++)
		{
			if (!component->bullet_component[i].active)
			{
				uint16 t_id = component->bullet_component[i].transform_id;

				component->transform_component[t_id].active = true;
				component->transform_component[t_id].ent_velocity = Vector2MoveTowards(component->transform_component[t_id].ent_position, component->transform_component[project_weapon_id].ent_position, 25);
				break;
			}
		}
	}
	for (int i = 0; i < MAX_BULLETS; i++)
	{

		if (component->bullet_component[i].active)
		{
			uint16 t_id = component->bullet_component[i].transform_id;

			component->transform_component[t_id].ent_position += component->transform_component[t_id].ent_velocity;
			component->transform_component[t_id].ent_collision.x = component->transform_component[t_id].ent_position.x;
			component->transform_component[t_id].ent_collision.y = component->transform_component[t_id].ent_position.y;

		}
		
	}
}

void UpdateEntityCollision(uint16 ent_id, component_lists* component, v2  circle_one, float radius_one)
{
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		uint16 t_id = component->bullet_component[i].transform_id;

		if (CheckCollisionCircles(circle_one, radius_one, component->transform_component[t_id].ent_position, component->transform_component[t_id].radius))
		{
			component->bullet_component[i].active = false;
		}
	}
}

void UpdateEntityHealth(uint16 ent_id, component_lists* component, entity_health health)
{
	if (health.current_health <= 0)
	{
		KillEntity(health.entity_id, component);
	}
}

void UpdateEntityCamera(uint16 ent_id, component_lists* component)
{

	component->camera_component[camera_id].entity_cam.offset = { screen_size_x / 2.0f, screen_size_y / 2.0f };
	component->camera_component[camera_id].entity_cam.target = component->transform_component[ent_id].ent_position;
}
void KillEntity(uint16 ent_id, component_lists* component)
{

	ent_id = entities--;

	component->total_health_component--;
	component->total_transform_component--;
	component->total_item_component--;
	component->total_bullet_component--;
}


