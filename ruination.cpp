#include "include.h"
#include "camera.h"
#include "player.h"
#include "enemy.h"
#include "weapon.h"
#include "ammo.h"
#include "entity.h"
#include "timer.h"
            

//TODO: Make bullet collision more global to where if it hits any object, it deactivates and disappears.
//TODO: Look into making a component system.



internal void AddPlayer(component_lists* components)
{
    CreateEntity(player_id, components);

    components->transform_components[player_id] = { player_id, 100, 100, 525, 40, WHITE };
    components->health_components[player_id] = { player_id, 20, 20 };

}
internal void AddEnemy(component_lists* components)
{
    CreateEntity(enemy_id, components);

    components->transform_components[enemy_id] = { enemy_id, 200, 400, 525, 20, RED };
    components->health_components[enemy_id] = { enemy_id, 20, 20 };
}
internal void AddWeapon(component_lists* components, v2 position)
{
    CreateEntity(weapon_id, components);

    components->transform_components[weapon_id] = { weapon_id, 0 + position.x, 0 + position.y, 0, 10, BLUE};
    components->health_components[weapon_id] = { weapon_id, 0, 0 };
}
internal void InitGame(player *player, weapon *weapon, component_lists* components)
{
    AddPlayer(components);
    AddEnemy(components);
    AddWeapon(components, components->transform_components[player_id].ent_position);
    init_player(player);
    init_enemy();
    init_weapon(weapon);
    init_ammo(player->player_object);
    init_cam();
}
internal void DrawGame(player *player, weapon *weapon)
{
    draw_player(player);
    draw_ammo(player->player_object);
    draw_enemy();

    DrawFPS(-300 + player->player_object.x, -300 + player->player_object.y);
    DrawLine(800, 0, 0, 800, WHITE);
    DrawLine(0, 0, 800, 800, WHITE);
}
internal void UpdateGame(player *player, weapon* weapon, component_lists* components)
{
    UpdateEntityMovement(player_id, components);
    update_player(player);
    update_enemy(player->player_object);
    update_weapon(weapon);
    update_ammo(weapon->weapon_reticle);
    update_cam();
}
internal void free_mem(player *player)
{

}

// main func
int main()
{
    player player_main;
    weapon weapon_main;

    component_lists components;

    InitGame(&player_main, &weapon_main, &components);
    InitWindow(screen_size_x, screen_size_y, "ruin");
    SetTargetFPS(120);
    HideCursor();
    SetMouseOffset(-400, -400);

    while (!WindowShouldClose())
    {

        /*starting functions*/
        BeginDrawing();
        BeginMode2D(camera_main.camera);
        ClearBackground(BLACK);

        /*updates*/
        UpdateGame(&player_main, &weapon_main, &components);

        /*drawing*/
        DrawGame(&player_main, &weapon_main);
        DrawEntity(player_id, &components);
        DrawEntity(enemy_id, &components);
        DrawEntity(weapon_id, &components);

        /*ending functions*/
        EndDrawing();
        EndMode2D();
    }
    CloseWindow();
    
    return 0;
}
