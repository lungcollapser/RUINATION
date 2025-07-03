#include "include.h"
#include "camera.h"
#include "player.h"
#include "enemy.h"
#include "weapon.h"
#include "ammo.h"
#include "bullet.h"

player player_main;
camera camera_main;
enemy enemy_main;
ammo ammo_main;

static int screen_size_x = 800;
static int screen_size_y = 800;


void ammo_logic()
{
    srand(time(0));
    int item_drop_choice = rand() % 2;

    //TODO: make the item drop choice global for all things that can be destroyed have the chance to drop items.
    bool clips_collision = CheckCollisionRecs(player_main.get_rectangle(), ammo_main.get_rectangle({ ammo_main.clips_drop }));
    bool ammo_collision = CheckCollisionRecs(player_main.get_rectangle(), ammo_main.get_rectangle({ ammo_main.ammo_drop }));

    switch (item_drop_choice)
    {
    case 0: ammo_main.current_clips_state = ammo_main.dropped; ammo_main.clips_drop = enemy_main.enemy_object; break;
    case 1: ammo_main.current_ammo_state = ammo_main.dropped; ammo_main.ammo_drop = enemy_main.enemy_object; break;
    case 2: break;
    }
    
    if (clips_collision && ammo_main.current_clips_state == ammo_main.dropped)
    {
        player_main.current_weapon->current_clips += 1;
        ammo_main.current_clips_state = ammo_main.picked_up;
    }
    
    if (ammo_collision && ammo_main.current_ammo_state == ammo_main.dropped)
    {
        player_main.current_weapon->bullet_amount = player_main.current_weapon->max_bullets;
        ammo_main.current_ammo_state = ammo_main.picked_up;
    }
}
void bullet_logic()
{
    bool player_collision = false;
    bool enemy_collision = false;


    for (auto& bullet : player_main.get_bullets())
    {
        bullet.update_position(screen_size_x, screen_size_y);
        player_collision = CheckCollisionRecs(bullet.get_rectangle(player_main.player_object), enemy_main.get_rectangle());
    }
    

    if (player_collision)
    {
        enemy_main.current_state = enemy_main.dead;
    }
    
    
}
void camera_logic()
{
    camera_main.update();
    camera_main.player_camera.offset = { screen_size_x / 2.0f, screen_size_y / 2.0f };
}
void enemy_logic()
{
    enemy_main.update_position(player_main.player_object);
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
    ammo_main.draw_clips(enemy_main.enemy_object);
    ammo_main.draw_ammo(enemy_main.enemy_object);
    player_main.draw();
    enemy_main.draw();
    EndMode2D();
    EndDrawing();
}
void input()
{
    Vector2 center_position = { 0, 0 };

    player_main.take_input(center_position);
    camera_main.take_input();

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
        bullet_logic();
        ammo_logic();
        enemy_logic();
        camera_logic();

    }
    // tells the window to close when told
    CloseWindow();

    return 0;
}
