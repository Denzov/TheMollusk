#include "App.h"

void App::init()
{
	InitWindow(SC_WIDTH, SC_HEIGHT, "App");
	SetTargetFPS(60);

}

void App::simulate()
{
    while (!WindowShouldClose())
    {
        compute();
        draw();
    }
    CloseWindow();
}

void App::compute() 
{
    /*...*/
}

void App::draw()
{
    BeginDrawing();
    BeginMode2D(camera);
    ClearBackground(RAYWHITE);

    /*...*/

    EndMode2D();
    EndDrawing();
}

void App::close() {
    CloseWindow();
}

void App::Run()
{
	init();
	simulate();
}
