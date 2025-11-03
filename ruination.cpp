#include "include.h"
#include "enemy.h"
#include "weapon.h"
#include "entity.h"
#include "timer.h"

/*
TODO:


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
    component->transform_component[player_id] = { player_id, 0, 0, -35, -35, 70, 70, 525, 40, WHITE };
    component->health_component[player_id] = { player_id, 20, 20 };

    AddEntity(player_id);
    AddComponents(component->total_transform_component);
    AddComponents(component->total_health_component);
    AddComponents(component->total_collision_component);
}
internal void AddEnemy(component_lists* component)
{
    component->transform_component[enemy_id] = { enemy_id, 300, 300, -15, -15, 35, 35, 525, 20, RED };
    component->health_component[enemy_id] = { enemy_id, 20, 20 };

    AddEntity(enemy_id);
    AddComponents(component->total_transform_component);
    AddComponents(component->total_health_component);
}
internal void AddProjectWeapon(component_lists* component)
{
    if (IsKeyPressed(KEY_ONE))
    {
        component->item_component[project_weapon_id] = { project_weapon_id, true, 10 };
    }

    component->transform_component[project_weapon_id] = { project_weapon_id,  0, 0, 0, 0, 0, 0, 0, 10, BLUE };
    component->health_component[project_weapon_id] = { project_weapon_id, 1, 1 };

    AddEntity(project_weapon_id);
    AddComponents(component->total_item_component);
    AddComponents(component->total_transform_component);
    AddComponents(component->total_health_component);
}
internal void AddBullet(component_lists* component)
{
    for (int i = 0; i < MAX_BULLETS; i++)
    {
        component->bullet_component[i] = { bullet_id, false, 0, 0, 0, 0, -10, -10, 20, 20, 10, 20, 1, 10, PURPLE };
        component->health_component[i] = { bullet_id, 1, 1 };
    }

    AddEntity(bullet_id);
    AddComponents(component->total_bullet_component);
    AddComponents(component->total_health_component);
    AddComponents(component->total_collision_component);

}
internal void AddCamera(component_lists* component)
{
    component->camera_component[camera_id] = { camera_id, 0, 0, 0, 0, 0, 1.0 };
    component->health_component[camera_id] = { camera_id, 20, 20 };

    AddEntity(camera_id);
    AddComponents(component->total_camera_component);
    AddComponents(component->total_health_component);

}
internal void DrawPlayer(component_lists* component)
{

    DrawEntity(player_id, component->transform_component[player_id].ent_position, { 0, 0 }, component->transform_component[player_id].radius, component->transform_component[player_id].color, component);
    DrawCollision(player_id, component->transform_component[player_id].ent_collision, component->transform_component[player_id].ent_position, component);
}
internal void DrawEnemy(component_lists* component)
{
    DrawEntity(enemy_id, component->transform_component[enemy_id].ent_position, { 0, 0 }, component->transform_component[enemy_id].radius, component->transform_component[enemy_id].color, component);
    DrawCollision(enemy_id, component->transform_component[enemy_id].ent_collision, component->transform_component[enemy_id].ent_position, component);

}
internal void DrawBullet(uint16 ent_id, component_lists* component)
{
    for (int i = 0; i < MAX_BULLETS; i++)
    {
        if (component->bullet_component[i].active)
        {
            DrawEntity(bullet_id, component->bullet_component[i].bullet_position, component->transform_component[ent_id].ent_position, component->bullet_component[i].radius, component->bullet_component[i].color, component);
            DrawCollision(bullet_id, component->bullet_component[i].bullet_collision, component->bullet_component[i].bullet_position + component->transform_component[player_id].ent_position, component);

        }
    }
}
internal void DrawProjectileWeapon(uint16 ent_id, component_lists* component)
{
    DrawEntity(project_weapon_id, component->transform_component[project_weapon_id].ent_position, component->transform_component[ent_id].ent_position, component->bullet_component[project_weapon_id].radius, component->bullet_component[project_weapon_id].color, component);
}

internal void UpdateGame(component_lists* component)
{
    UpdateEntityMovement(player_id, component);
    UpdateEntityProjectWeapon(project_weapon_id, component);
    UpdateEntityBullet(bullet_id, component);
    UpdateEntityCamera(player_id, component);
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
        DrawPlayer(&component);
        DrawEnemy(&component);
        DrawProjectileWeapon(player_id, &component);

        /*ending functions*/
        EndDrawing();
        EndMode2D();
    }
    CloseWindow();

    return 0;
}