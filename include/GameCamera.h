#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <raylib.h>
#include <stdint.h>
#include <iostream>

#include "ObjectParams/GameCameraParams.h"
#include "ObjectParams/GameAppParams.h"
#include "ObjectParams/CaptureParams.h"

#include "Utililties.h"

#define MOVING_KEY_HANDLE_BEGIN(KEY) if(IsKeyDown(KEY)){
#define MOVING_KEY_HANDLE_EXTENSION(KEY) }else if(IsKeyDown(KEY)){
#define MOVING_KEY_HANDLE_END }

class GameCamera : public Camera2D, public GameCameraParams{
public:
	void init();
	void update();

private:
    void impact_zoom_by_mouse_wheel();
	void impact_zoom_by_keys();

private:
	enum MOVING_KEYS : uint16_t{
		TARGET_UP 		= KEY_W,
		TARGET_DOWN 	= KEY_S,
		TARGET_LEFT		= KEY_A,
		TARGET_RIGHT 	= KEY_D,
		ZOOM_ADD		= KEY_EQUAL,
		ZOOM_REDUCE 	= KEY_MINUS,
	};
};

#endif // !_CAMERA_H_