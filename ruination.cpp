#include "include.h"
#include "enemy.h"
#include "weapon.h"
#include "entity.h"
#include "timer.h"

/*
TODO:

-Create a drawing of a weapon where the bullets fires based on where its pointing, not based on the weapon reticle. Have the barrel of the gun point towards the barrel.
-Fix bullet collision due to it not having a transform component. add ent_position as a parameter to fill in for scalability.
-Make bullet collision more global to where if it hits any object, it deactivates and disappears.
-Figure out if you really need to use ENT_ID as an argument for every function (psst, probably not).
-Fix KillEntity function to function the same way as AddEntity function.
-Add ammo
-Add enemy movement and basic interaction
-Add weapon swap

*/




internal void AddPlayer(component_lists * component)
{
    component->transform_component[player_id] = { player_id, 0, 0, 5, 5, 40, WHITE };
    component->collision_component[player_id] = { player_id, true, 0, 0, 60, 60 };
    component->health_component[player_id] = { player_id, 20, 20 };

    AddEntity(player_id, component);
    AddComponents(component->total_transform_component);
    AddComponents(component->total_health_component);
    AddComponents(component->total_collision_component);
}
internal void AddEnemy(component_lists* component)
{
    component->transform_component[enemy_id] = { enemy_id, 300, 300, 5, 5, 20, RED};
    component->collision_component[enemy_id] = { enemy_id, true, 0, 0, 40, 40};
    component->health_component[enemy_id] = { enemy_id, 1, 20 };

    AddEntity(enemy_id, component);
    AddComponents(component->total_transform_component);
    AddComponents(component->total_health_component);
}
internal void AddProjectWeapon(component_lists* component)
{
    if (IsKeyPressed(KEY_ONE))
    {
        component->item_component[project_weapon_id] = { project_weapon_id, true, 10 };
    }

    component->transform_component[project_weapon_id] = { project_weapon_id,  0, 0, 0, 0, 10, BLUE };
    component->health_component[project_weapon_id] = { project_weapon_id, 1, 1 };

    AddEntity(project_weapon_id, component);
    AddComponents(component->total_item_component);
    AddComponents(component->total_transform_component);
    AddComponents(component->total_health_component);
}
internal void AddBullet(component_lists* component)
{
    for (int i = 0; i < MAX_BULLETS; i++)
    {
        component->transform_component[i] = { bullet_id, component->transform_component[player_id].ent_position.x, component->transform_component[player_id].ent_position.y, 2, 2, 10, PURPLE};
        component->bullet_component[i] = { bullet_id, false,  0, 0, 20, 20, 1, 1, 1 };
        component->health_component[i] = { bullet_id, 1, 1 };
    }

    AddEntity(bullet_id, component);
    AddComponents(component->total_transform_component);
    AddComponents(component->total_health_component);
    AddComponents(component->total_collision_component);

}
internal void AddCamera(component_lists* component)
{
    component->camera_component[camera_id] = { camera_id, 0, 0, 0, 0, 0, 1.0 };
    component->health_component[camera_id] = { camera_id, 20, 20 };

    AddEntity(camera_id, component);
    AddComponents(component->total_camera_component);
    AddComponents(component->total_health_component);

}
internal void DrawPlayer(component_lists* component)
{
    component->collision_component[player_id].collision.x = component->transform_component[player_id].ent_position.x;
    component->collision_component[player_id].collision.y = component->transform_component[player_id].ent_position.y;

    DrawEntity(player_id, component->transform_component[player_id].ent_position, component->transform_component[player_id].radius, component->transform_component[player_id].color, component);
    DrawCollision(player_id, component->collision_component[player_id].collision, component->transform_component[player_id].ent_position, PLAYER_SIZE, component);
}
internal void DrawEnemy(component_lists* component)
{
    component->collision_component[enemy_id].collision.x = component->transform_component[enemy_id].ent_position.x;
    component->collision_component[enemy_id].collision.y = component->transform_component[enemy_id].ent_position.y;

    DrawEntity(enemy_id, component->transform_component[enemy_id].ent_position, component->transform_component[enemy_id].radius, component->transform_component[enemy_id].color, component);
    DrawCollision(enemy_id, component->collision_component[enemy_id].collision, component->transform_component[enemy_id].ent_position, ENEMY_SIZE, component);

}
internal void DrawBullet(uint16 ent_id, component_lists* component)
{
    for (int i = 0; i < MAX_BULLETS; i++)
    {


        component->bullet_component[i].bullet_collision.x = component->transform_component[i].ent_position.x;
        component->bullet_component[i].bullet_collision.y = component->transform_component[i].ent_position.y;


        DrawEntity(i, component->transform_component[i].ent_position, component->transform_component[i].radius, component->transform_component[i].color, component);
        DrawCollision(i, component->bullet_component[i].bullet_collision, component->transform_component[i].ent_position, BULLET_SIZE, component);
    }
}
internal void DrawProjectileWeapon(uint16 ent_id, component_lists* component)
{
    DrawEntityAdd(project_weapon_id, component->transform_component[project_weapon_id].ent_position, component->transform_component[ent_id].ent_position, component->transform_component[project_weapon_id].radius, component->transform_component[project_weapon_id].color, component);
}

internal void UpdateGame(component_lists* component)
{
    UpdateEntityMovement(player_id, component);
    UpdateEntityProjectWeapon(project_weapon_id, component);
    UpdateEntityBullet(bullet_id, component);
    UpdateEntityCamera(player_id, component);

    for (int i = 0; i < MAX_BULLETS; i++)
    {
        UpdateEntityCollision(component, component->bullet_component[i].bullet_collision, component->collision_component[enemy_id].collision);
    }
    /*whats causing bullets not to shoot*/

}
internal void InitGame(component_lists* component)
{
    AddPlayer(component);
    AddEnemy(component);
    AddBullet(component);
    AddProjectWeapon(component);
    AddCamera(component);
}
// main func
int main()
{
    component_lists component;

    InitGame(&component);
    InitWindow(screen_size_x, screen_size_y, "ruin");
    SetTargetFPS(120);
    HideCursor();
    SetMouseOffset(-400, -400);

    while (!WindowShouldClose())
    {

        BeginDrawing();
        BeginMode2D(component.camera_component[camera_id].entity_cam);
        ClearBackground(BLACK);


        /*updates*/
        UpdateGame(&component);

        /*drawing*/
        DrawFPS(-300, -300);
        DrawLine(800, 0, 0, 800, WHITE);
        DrawLine(0, 0, 800, 800, WHITE);
        DrawBullet(player_id, &component);
        DrawProjectileWeapon(player_id, &component);
        DrawPlayer(&component);
        DrawEnemy(&component);

        /*ending functions*/
        EndDrawing();
        EndMode2D();
    }
    CloseWindow();

    return 0;
}