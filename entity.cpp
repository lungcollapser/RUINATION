#include "entity.h"

/*component->bullet_component[i].bullet_collision.x += component->bullet_component[i].bullet_position.x;
			component->bullet_component[i].bullet_collision.y += component->bullet_component[i].bullet_position.y;
			component->bullet_component[i].bullet_collision.x = component->bullet_component[i].bullet_position.x;
			component->bullet_component[i].bullet_collision.y = component->bullet_component[i].bullet_position.y;*/

extern uint16 entities = 0;
extern uint16 player_id = 51;
extern uint16 enemy_id = 52;
extern uint16 weapon_id = 53;
extern uint16 project_weapon_id = 54;
extern uint16 bullet_id = 1;
extern uint16 camera_id = 56;

uint16 AddEntity(uint16 ent_id, component_lists* component)
{

	return ent_id = entities++;
}
uint16 AddComponents(uint16 component_type)
{
	return component_type++;
}
void DrawEntity(uint16 ent_id, v2 position, float radius, Color color, component_lists* component)
{

	if (component->health_component[ent_id].current_health > 0)
	{
		DrawCircleV(position, radius, color);
	}
}
void DrawEntityAdd(uint16 ent_id, v2 position_one, v2 position_two, float radius, Color color, component_lists* component)
{
	if (component->health_component[ent_id].current_health > 0)
	{
		DrawCircleV(position_one + position_two, radius, color);
	}
}
void DrawCollision(uint16 ent_id, Rectangle collision, v2 position, uint16 ent_size, component_lists* component)
{

	if (component->collision_component[ent_id].active || component->bullet_component[ent_id].active)
	{
		DrawRectangleLines(position.x - ent_size / 2.0f, position.y - ent_size / 2.0f, collision.width, collision.height, ORANGE);
	}

}
Rectangle CenterCollision(Rectangle collision)
{
	return Rectangle
	{
		collision.x + collision.width / 2.0f,
		collision.y + collision.height / 2.0f,
		collision.width,
		collision.height
	};
}
void UpdateEntityMovement(uint16 ent_id, component_lists* component)
{

	if (IsKeyDown(KEY_D))
	{
		component->transform_component[ent_id].ent_position.x += component->transform_component[ent_id].speed.x;
	}
	if (IsKeyDown(KEY_A))
	{
		component->transform_component[ent_id].ent_position.x -= component->transform_component[ent_id].speed.x;
	}
	if (IsKeyDown(KEY_W))
	{
		component->transform_component[ent_id].ent_position.y -= component->transform_component[ent_id].speed.y;
	}
	if (IsKeyDown(KEY_S))
	{
		component->transform_component[ent_id].ent_position.y += component->transform_component[ent_id].speed.y;
	}

	/*v2 velocity = Vector2Scale(Vector2Normalize(direction), component->transform_component[ent_id].movement_speed * GetFrameTime());
	component->transform_component[ent_id].ent_position = Vector2Add(component->transform_component[ent_id].ent_position, velocity);
	*/
}

void UpdateEntityWeapon(uint16 ent_id, component_lists* component)
{

}
void UpdateEntityProjectWeapon(uint16 ent_id, component_lists* component)
{
	Rectangle projectile_weapon
	{
		component->transform_component[player_id].ent_position.x + 10,
		component->transform_component[player_id].ent_position.y,
		100,
		50
	};

	float aim_direction_x = { 0 };
	float aim_direction_y = { 0 };

	DrawLineV(component->transform_component[player_id].ent_position, {30, 30}, PURPLE);

	aim_direction_x = GetMousePosition().x - projectile_weapon.x;
	aim_direction_y = GetMousePosition().y - projectile_weapon.y;

	component->transform_component[ent_id].ent_position = GetMousePosition();
	DrawCircleV(component->transform_component[ent_id].ent_position + component->transform_component[player_id].ent_position, component->transform_component[ent_id].radius, component->transform_component[ent_id].color);


}
void UpdateEntityBullet(uint16 ent_id, component_lists* component)
{

	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		for (int i = 0; i < MAX_BULLETS; i++)
		{
			if (!component->bullet_component[i].active)
			{

				component->transform_component[i].ent_position = component->transform_component[player_id].ent_position;
				component->bullet_component[i].active = true;
				break;
			}
		}
	}
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		if (component->bullet_component[i].active)
		{
			v2 bullet_origin = { 0, 0 };

			v2 bullet_end = component->transform_component[i].ent_position - component->transform_component[project_weapon_id].ent_position;



		}

	}
}

void UpdateEntityCollision(component_lists* component, Rectangle rec_one, Rectangle rec_two)
{
	bool collision = CheckCollisionRecs(rec_one, rec_two);

	if (collision)
	{
		component->health_component[enemy_id].current_health -= 1;
		std::cout << component->health_component[enemy_id].current_health;
	}
}
void UpdateEntityHealth(uint16 ent_id, component_lists* component, entity_health health)
{
	
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
