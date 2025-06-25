#include "../include/GameApp.h"

void GameApp::init()
{
	InitWindow(CaptureParams::getInstance()->getWidth(), 
               CaptureParams::getInstance()->getHeight(),
               TITLE);

	SetTargetFPS(FPS);
    _camera.init();

    _main_player = std::make_shared<UserPlayer>();
    _entities.addEntity(_main_player);
}

void GameApp::simulate()
{
    while (!WindowShouldClose())
    {
        compute();
        draw();
    }
    CloseWindow();
}

void GameApp::compute() 
{
    _camera.update();
    _entities.update();

    if(IsKeyPressed(KEY_Q)){
        _main_player->destroy();
    }
    else if(IsKeyDown(KEY_R)){
        _main_player->setPosition({ 0, 0 });
        CaptureParams::getInstance()->set(   
                                    GameAppParams::FIELD_WIDTH,
                                    GameAppParams::FIELD_WIDTH);
    }
    else if(IsKeyPressed(KEY_G)){
        CaptureParams::getInstance()->set(500, 500);
    }
}

void GameApp::draw()
{
    BeginDrawing();
    BeginMode2D(_camera);

    ClearBackground(BG_COLOR);
    
    _entities.draw();

    EndMode2D();
    EndDrawing();
}

void GameApp::close() {
    CloseWindow();
}

void GameApp::Run()
{
	init();
	simulate();
}
