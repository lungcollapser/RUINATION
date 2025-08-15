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

//TODO: Make bullet collision more global to where if it hits any object, it deactivates and disappears.
//TODO: Look into making a component system.

player* player_main = (player*)malloc(sizeof(player));
weapon* weapon_main = (weapon*)malloc(sizeof(weapon));
revolver* revolver_main = (revolver*)malloc(sizeof(revolver));
repeater* repeater_main = (repeater*)malloc(sizeof(repeater));

camera camera_main;
enemy enemy_main;
ammo ammo_main;
    
internal void draw_player(v2 player_object)
{

    draw_p(player_object);

}
internal void update_player(v2 player_object, v2 center_position, uint16 player_speed)
{

    update_p(player_object, center_position, player_speed);
}
internal void draw_weapon(std::vector<bullet> bullets, v2 player_object)
{
    draw_w(player_object, {0, 0});

    for (auto& bullet : get_bullets(bullets))
    {
        bullet.draw(player_object);
    }
}
internal void update_weapon(weapon* current_weapon, revolver* revolver_weapon, repeater* repeater_weapon, player* player)
{
    update_w(current_weapon, { 0, 0 }, { 0, 0 }, current_weapon->bullet_speed, current_weapon->bullet_amount);

    for (auto& bullet : get_bullets(current_weapon->bullets))
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
    local_persist v2 center_position = { 0, 0 };


    InitWindow(screen_size_x, screen_size_y, "ruin");
    SetTargetFPS(120);
    HideCursor();
    SetMouseOffset(-400, -400);
    init_mem();
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawFPS(10, 10);
        BeginMode2D(camera_main.player_camera);
        draw();
        draw_player(player_main->player_object);
        draw_weapon(weapon_main->bullets, player_main->player_object);
        input();
        update_player(player_main->player_object, center_position, player_main->player_speed);
        update_weapon(weapon_main, revolver_main, repeater_main, player_main);
        update();

        EndMode2D();
        EndDrawing();
    }
    free_mem();
    free(revolver_main);
    free(repeater_main);

    CloseWindow();

    return 0;
}
