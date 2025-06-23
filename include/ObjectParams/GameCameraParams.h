#ifndef _GAME_CAMERA_PARAMS_H_
#define _GAME_CAMERA_PARAMS_H_

#include <raylib.h> 
#include "GameAppParams.h"
#include "../Utililties.h"

struct GameCameraParams {
    static constexpr Vector2 DEFAULT_OFFSET      = { 
        half(GameAppParams::FIELD_WIDTH),
        half(GameAppParams::FIELD_HEIGHT)
    }; 

    static constexpr Vector2 DEFAULT_TARGET      = { 0, 0 }; 
    static constexpr float   DEFAULT_ROTATION    = 0.f;
    static constexpr float   DEFAULT_ZOOM        = 1.f;

    static constexpr float   MIN_ZOOM            = 0.005f;
    static constexpr float   MAX_ZOOM            = 100000.f;

    static constexpr float   RATIO_ZOOM   = 0.1;
	static constexpr float   RATIO_TARGET = 0.7;
};

#endif // !_GAME_CAMERA_PARAMS_H_