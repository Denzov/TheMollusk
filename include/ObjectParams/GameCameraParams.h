#ifndef _GAME_CAMERA_PARAMS_H_
#define _GAME_CAMERA_PARAMS_H_

#include <raylib.h> 
#include "GameAppParams.h"
#include "../Utililties.h"

struct GameCameraParams {
    static constexpr Vector2 DEFAULT_OFFSET      = { 
        half(GameAppParams::DEFAULT_SCREEN_WIDTH),
        half(GameAppParams::DEFAULT_SCREEN_HEIGHT)
    }; 

    static constexpr Vector2 DEFAULT_TARGET      = { 0, 0 }; 
    static constexpr float   DEFAULT_ROTATION    = 0.f;
    static constexpr float   DEFAULT_ZOOM        = 1.f;

    static constexpr float   MIN_ZOOM            = 0.005f;
    static constexpr float   MAX_ZOOM            = 100000.f;

    static constexpr float   MOUSE_WHEEL_RATIO_ZOOM = 0.25f;
    static constexpr float   KEY_RATIO_ZOOM = 0.01f;

	static constexpr float   RATIO_TARGET = 0.7;
};

#endif // !_GAME_CAMERA_PARAMS_H_