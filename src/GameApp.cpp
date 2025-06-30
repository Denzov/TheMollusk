#include "../include/GameApp.h"

void GameApp::init()
{
	InitWindow(CaptureParams::getInstance()->getWidth(), 
               CaptureParams::getInstance()->getHeight(),
               TITLE);

	SetTargetFPS(FPS);
    _camera.init();

    _entities.addEntity(std::make_unique<UserPlayer>());
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
    }
    else if(IsKeyDown(KEY_R)){
        CaptureParams::getInstance()->set(   
                                    GameAppParams::DEFAULT_SCREEN_WIDTH,
                                    GameAppParams::DEFAULT_SCREEN_HEIGHT);
    }
    else if(IsKeyDown(KEY_D)){
        for(uint16_t i = 0; i < 10; i++){
            const Vector2 vec = {(float)GetRandomValue(0, GameAppParams::FIELD_WIDTH ) - GameAppParams::FIELD_WIDTH/2, 
                             (float)GetRandomValue(0, GameAppParams::FIELD_HEIGHT) - GameAppParams::FIELD_HEIGHT/2};
            _entities.addEntity(std::make_unique<Enemy1>(vec, 0.0f));   
        }
    }
    
    if(IsKeyPressed(KEY_A)){
        std::cout << GetFPS() << '\t' << _entities.getEntitiesCount() << '\n';
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
