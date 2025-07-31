#include "include.h"
#include "camera.h"
#include "player.h"
#include "enemy.h"
#include "weapon.h"
#include "ammo.h"

#define global_variable static
#define local_persist static
#define internal static

//TODO: Make collision Rectangles into collision Circles.
//TODO: Make bullet collision more global to where if it hits any object, it deactivates and disappears.
//TODO: Look into making a component system.

player player_main;
camera camera_main;
enemy enemy_main;
ammo ammo_main;
weapon weapon_main;



bool collision(Rectangle collision_one, Rectangle collision_two)
{
    if (CheckCollisionRecs(collision_one, collision_two))
    {
        return true;
    }
    else
    {
        return false;
    }
}
    

void ammo_logic()
{

    //TODO: make the item drop choice global for all things that can be destroyed have the chance to drop items.
    bool ammo_collision = collision(player_main.get_rectangle(), ammo_main.get_rectangle({ ammo_main.ammo_drop }));

    
    if (ammo_collision && ammo_main.ammo_choices == ammo_main.clips)
    {
        player_main.current_weapon->current_clips += 1;
        ammo_main.current_ammo_state = ammo_main.picked_up;
        std::cout << "picked up";
    }
    
    if (ammo_collision && player_main.current_weapon->bullet_amount < player_main.current_weapon->max_bullets && ammo_main.ammo_choices == ammo_main.bullets)
    {
        player_main.current_weapon->bullet_amount = player_main.current_weapon->max_bullets;
        ammo_main.current_ammo_state = ammo_main.picked_up;
        std::cout << "picked up";

    }
}
void draw()
{
    BeginDrawing();
    ClearBackground(BLACK);
    DrawFPS(10, 10);
    BeginMode2D(camera_main.player_camera);
    for (auto& bullet : player_main.get_bullets())
    {
        bullet.draw(player_main.player_object);
    }
    DrawLine(800, 0, 0, 800, WHITE);
    DrawLine(0, 0, 800, 800, WHITE);
    player_main.draw();
    enemy_main.draw();
    ammo_main.draw(enemy_main.enemy_object);
    EndMode2D();
    EndDrawing();
}
void input()
{
    local_persist Vector2 center_position = { 0, 0 };


    player_main.take_input(player_main.player_object);
    camera_main.take_input();

}
void update()
{
    for (auto& bullet : player_main.get_bullets())
    {
        bullet.update(screen_size_x, screen_size_y, player_main.player_object, enemy_main.get_rectangle());
    }
    camera_main.update();
    enemy_main.update(player_main.player_object);
}

// main func
int main()
{

    // creating the window using two arguments. change color in the cpp file
    InitWindow(screen_size_x, screen_size_y, "ruin");
    // fps setting
    SetTargetFPS(60);
    //hides the cursor to make way for reticle
    HideCursor();
    //sets a mouse offset due to strange mouse positioning (NEEDS TO BE FIXED)
    SetMouseOffset(-400, -400);
    // window loop to keep it open until closed by user
    while (!WindowShouldClose())
    {
        draw();
        input();
        update();
        ammo_logic();
    }
    // tells the window to close when told
    CloseWindow();

    return 0;
}
