#include "..\include\GameCamera.h"

void GameCamera::init() {
    offset   = DEFAULT_OFFSET;
    target   = DEFAULT_TARGET;
    rotation = DEFAULT_ROTATION;
    zoom     = DEFAULT_ZOOM; 

    CaptureParams::getInstance()->hookZoomRatio(&zoom);
    CaptureParams::getInstance()->hookOffset(&offset);
}

void GameCamera::update() {
    impact_zoom_by_mouse_wheel();
    impact_zoom_by_keys();
}

void GameCamera::impact_zoom_by_mouse_wheel(){
    zoom += GetMouseWheelMove() * zoom * GameCameraParams::RATIO_ZOOM;
}

void GameCamera::impact_zoom_by_keys(){
    MOVING_KEY_HANDLE_BEGIN(ZOOM_ADD)
        zoom += zoom * GameCameraParams::RATIO_ZOOM;
    
    MOVING_KEY_HANDLE_EXTENSION(ZOOM_REDUCE)
        zoom -= zoom * GameCameraParams::RATIO_ZOOM;

    MOVING_KEY_HANDLE_END
}