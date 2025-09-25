#include "include.h"
#include "camera.h"
#include "player.h"
#include "enemy.h"
#include "weapon.h"
#include "ammo.h"
#include "timer.h"
            

//TODO: Make bullet collision more global to where if it hits any object, it deactivates and disappears.
//TODO: Look into making a component system.



internal void InitGame(player *player, weapon *weapon)
{

    init_player(player);
    init_enemy();
    init_weapon(weapon);
    init_ammo(player->player_object);
    init_cam();
}
internal void DrawGame(player *player, weapon *weapon)
{
    draw_player(player);
    draw_weapon(weapon, player->player_object);
    draw_ammo(player->player_object);
    draw_enemy();

    DrawFPS(-300 + player->player_object.x, -300 + player->player_object.y);
    DrawLine(800, 0, 0, 800, WHITE);
    DrawLine(0, 0, 800, 800, WHITE);
}
internal void UpdateGame(player *player, weapon* weapon)
{

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

    InitGame(&player_main, &weapon_main);
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
        UpdateGame(&player_main, &weapon_main);

        /*drawing*/
        DrawGame(&player_main, &weapon_main);

        /*ending functions*/
        EndDrawing();
        EndMode2D();
    }
    CloseWindow();
    
    return 0;
}
