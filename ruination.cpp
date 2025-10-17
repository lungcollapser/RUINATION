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



internal void AddPlayer(component_lists* component)
{
    component->transform_component[player_id] = { player_id, 0, 0, -35, -35, 70, 70, 525, 40, WHITE };
    component->health_component[player_id] = { player_id, 20, 20 };

    CreateEntity(player_id, component);
}
internal void AddEnemy(component_lists* component)
{
    component->transform_component[enemy_id] = { enemy_id, 0, 0, -25, -25, 50, 50, 525, 20, RED };
    component->health_component[enemy_id] = { enemy_id, 20, 20 };

    CreateEntity(enemy_id, component);
}
internal void AddProjectWeapon(component_lists* component)
{
    if (IsKeyPressed(KEY_ONE))
    {
        component->item_component[project_weapon_id] = { project_weapon_id, true, 10 };
    }

    component->transform_component[project_weapon_id] = { project_weapon_id,  0, 0, 10, 10, 30, 30, 0, 10, BLUE};
    component->health_component[project_weapon_id] = { project_weapon_id, 1, 1 };

    CreateEntity(project_weapon_id, component);

}
internal void AddBullet(component_lists* component)
{
    for (int i = 0; i < MAX_BULLETS; i++)
    {
        component->bullet_component[i] = { bullet_id, false, 0, 0, 0, 0, 10, 20, 1, 10, PURPLE};

    }
    CreateEntity(bullet_id, component);
}
internal void DrawPlayer(component_lists* component)
{
    DrawEntity(player_id, component);
    DrawEntityCollision(player_id, component);
}
internal void DrawEnemy(component_lists* component)
{
    DrawEntity(enemy_id, component);
    DrawEntityCollision(enemy_id, component);
}
internal void DrawBullet(uint16 ent_id, component_lists* component)
{
    for (int i = 0; i < MAX_BULLETS; i++)
    {
        if (component->bullet_component[i].active)
        {
            DrawEntityAdd(bullet_id, component->bullet_component[i].bullet_position, component->transform_component[ent_id].ent_position, component->bullet_component[i].radius, component->bullet_component[i].color, component);
            DrawEntityCollision(bullet_id, component);
        }
    }

}
/*MAKE PROJECTILEWEAPON AND BULLET USE SAME FUNCTION. RECOMMEND PUTTING BULLET IF AND FOR LOOP AROUND NEW FUNCTION THAT DRAWS*/
internal void DrawProjectileWeapon(uint16 ent_id, component_lists* component)
{
    DrawEntityAdd(project_weapon_id, component->transform_component[project_weapon_id].ent_position, component->transform_component[ent_id].ent_position, component->bullet_component[project_weapon_id].radius, component->bullet_component[project_weapon_id].color, component);
}
internal void InitGame(player *player, weapon *weapon, component_lists* component)
{
    AddPlayer(component);
    AddEnemy(component);
    AddBullet(component);
    AddProjectWeapon(component);
    init_player(player);
    init_enemy();
    init_weapon(weapon);
    init_ammo(player->player_object);
    init_cam();
}
internal void DrawGame(player *player, weapon *weapon, component_lists* component)
{

    /*need to figure out a better home for this. its more of an update than a draw state so its a bit confusing. could also be more contained and apparent.*/


    DrawFPS(-300 + player->player_object.x, -300 + player->player_object.y);
    DrawLine(800, 0, 0, 800, WHITE);
    DrawLine(0, 0, 800, 800, WHITE);


}
internal void UpdateGame(player *player, weapon* weapon, component_lists* component)
{
    UpdateEntityMovement(player_id, component);
    UpdateEntityProjectWeapon(project_weapon_id, component);
    UpdateEntityBullet(player_id, component);
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

    component_lists component;

    InitGame(&player_main, &weapon_main, &component);
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
        UpdateGame(&player_main, &weapon_main, &component);

        /*drawing*/
        DrawGame(&player_main, &weapon_main, &component);
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
