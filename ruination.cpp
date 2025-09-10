#include "include.h"
#include "camera.h"
#include "player.h"
#include "enemy.h"
#include "weapon.h"
#include "ammo.h"
#include "timer.h"


//TODO: Make bullet collision more global to where if it hits any object, it deactivates and disappears.
//TODO: Look into making a component system.



internal void InitGame(player *player)
{

    init_player(player);
    init_enemy();
    init_weapon();
    init_ammo(player->player_object);
    init_cam(player->player_object);
}
internal void DrawGame(player *player)
{
    draw_player(player);
    draw_weapon(player->player_object);
    draw_ammo(player->player_object);
    draw_enemy();

    DrawFPS(-300 + player->player_object.x, -300 + player->player_object.y);
    DrawLine(800, 0, 0, 800, WHITE);
    DrawLine(0, 0, 800, 800, WHITE);
}
internal void UpdateGame(player *player)
{

    update_player(player);
    update_enemy(player->player_object, 10);
    update_weapon({ 0, 0 }, player->player_object);
    update_ammo(weapon_main.weapon_reticle, player->player_object);
    update_cam();
}
internal void free_mem(player *player)
{
    free_player(player);
}

// main func
int main()
{
    player player_main;

    InitGame(&player_main);
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
        UpdateGame(&player_main);

        /*drawing*/
        DrawGame(&player_main);

        /*ending functions*/
        EndDrawing();
        EndMode2D();
    }
    CloseWindow();
    
    return 0;
}
