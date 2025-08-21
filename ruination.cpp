#include "include.h"
#include "camera.h"
#include "player.h"
#include "enemy.h"
#include "weapon.h"
#include "ammo.h"
#include "timer.h"

//TODO: Make bullet collision more global to where if it hits any object, it deactivates and disappears.
//TODO: Look into making a component system.

camera camera_main;
enemy enemy_main;
ammo ammo_main;
    
internal void draw_player()
{
    draw_p(player_main);
}
internal void update_player()
{
    update_p(player_main);
}
internal void draw_weapon(player* player)
{
    draw_w(player->player_object, weapon_main);

    for (auto& bullet : get_bullets(weapon_main))
    {
        bullet.draw(player->player_object);
    }
}
internal void update_weapon(player* player)
{
    update_w(weapon_main, { 0, 0 });

    for (auto& bullet : get_bullets(weapon_main))
    {
        bullet.update(screen_size_x, screen_size_y, player->player_object, enemy_main.get_rectangle());
        enemy_main.update(player->player_object, weapon_main->bullet_damage, bullet.get_rectangle(player->player_object), enemy_main.get_rectangle());
    }

}

internal void draw()
{

    DrawLine(800, 0, 0, 800, WHITE);
    DrawLine(0, 0, 800, 800, WHITE);
    enemy_main.draw();
    ammo_main.draw(enemy_main.enemy_object);
}
internal void input()
{
    camera_main.take_input();
}
internal void update()
{
    camera_main.update();
}
internal void init_mem()
{
    player_main = new player();
    weapon_main = new weapon();

    init_p(player_main);
    init_w(weapon_main);

}
internal void free_mem()
{
    free_p(player_main);
    free_w(weapon_main);
}

// main func
int main()
{

    InitWindow(screen_size_x, screen_size_y, "ruin");
    init_mem();
    SetTargetFPS(120);
    HideCursor();
    SetMouseOffset(-400, -400);
    while (!WindowShouldClose())
    {
        input();
        update_player();
        update_weapon(player_main);
        update();

        BeginDrawing();
        ClearBackground(BLACK);
        DrawFPS(10, 10);
        BeginMode2D(camera_main.player_camera);
        draw();
        draw_player();
        draw_weapon(player_main);
        EndMode2D();
        EndDrawing();
    }
    free_mem();
    CloseWindow();

    return 0;
}
