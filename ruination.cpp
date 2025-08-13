#include "include.h"
#include "camera.h"
#include "player.h"
#include "enemy.h"
#include "weapon.h"
#include "ammo.h"
#include "timer.h"

#define global_variable static
#define local_persist static
#define internal static

//TODO: Make collision Rectangles into collision Circles.
//TODO: Make bullet collision more global to where if it hits any object, it deactivates and disappears.
//TODO: Look into making a component system.

camera camera_main;
enemy enemy_main;
ammo ammo_main;
    
internal void draw_player(player* player)
{

    draw_p(player->player_object);

}
internal void update_player(player* player, v2 center_position)
{

    update_p(player->player_object, center_position, 525);
}
internal void draw_weapon(weapon* current_weapon, player* player)
{
    draw_w(player->player_object, {0, 0});

    for (auto& bullet : current_weapon->get_bullets())
    {
        bullet.draw(player->player_object);
    }
}
internal void update_weapon(weapon* current_weapon, revolver* revolver_weapon, repeater* repeater_weapon, player* player)
{
    update_w(current_weapon, { 0, 0 }, { 0, 0 }, current_weapon->bullet_speed, current_weapon->bullet_amount);

    for (auto& bullet : current_weapon->get_bullets())
    {
        bullet.update(screen_size_x, screen_size_y, player->player_object, enemy_main.get_rectangle());
        enemy_main.update(player->player_object, current_weapon->bullet_damage, bullet.get_rectangle(player->player_object), enemy_main.get_rectangle());
    }

    if (IsKeyPressed(KEY_ONE))
    {
        current_weapon = revolver_weapon;
    }
    else if (IsKeyPressed(KEY_TWO))
    {
        current_weapon = repeater_weapon;
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
    local_persist v2 center_position = { 0, 0 };


    camera_main.take_input();

}
internal void update()
{
    camera_main.update();
}
internal void init_mem()
{
}
internal void free_mem()
{
    
}

// main func
int main()
{
    local_persist v2 center_position = { 0, 0 };


    player* player_main = (player*)malloc(sizeof(player));
    weapon* weapon_main = (weapon*)malloc(sizeof(weapon));
    revolver* revolver_main = (revolver*)malloc(sizeof(revolver));
    repeater* repeater_main = (repeater*)malloc(sizeof(repeater));

    InitWindow(screen_size_x, screen_size_y, "ruin");
    SetTargetFPS(60);
    HideCursor();
    SetMouseOffset(-400, -400);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawFPS(10, 10);
        BeginMode2D(camera_main.player_camera);

        draw();
        draw_player(player_main);
        draw_weapon(weapon_main, player_main);
        input();
        update_player(player_main, center_position);
        update_weapon(weapon_main, revolver_main, repeater_main, player_main);
        update();

        EndMode2D();
        EndDrawing();
    }
    free(player_main);
    free(weapon_main);
    free(revolver_main);
    free(repeater_main);

    CloseWindow();

    return 0;
}
