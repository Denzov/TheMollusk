#ifndef _SCREEN_PARAMS_H_
#define _SCREEN_PARAMS_H_

#include <raylib.h>
#include <iostream>

#include "../Utililties.h"
#include "GameAppParams.h"

struct CaptureParams
{
public:
	static CaptureParams* getInstance() {
        static CaptureParams _instance;
		return &_instance;
	}

    void set(int width, int height) {
        _width = width;
        _height = height;

        _offset->x = half(_width);
        _offset->y = half(_height);
        
        SetWindowPosition(
            half(GetMonitorWidth(0)) - half(_width),
            half(GetMonitorHeight(0)) - half(_height)    
        );

        SetWindowSize(_width, _height);
    }

    void hookZoomRatio(float* zoom_ratio) {
        _zoom_ratio = zoom_ratio;
    }

    void hookOffset(Vector2* offset) {
        _offset = offset;
    }

    int getWidth() {
        return _width;
    }

    int getHeight() {
        return _height;
    }

    float getZoomRatio() {
        return *_zoom_ratio;
    }

    Vector2 getTarget() {
        return *_offset;
    }

	CaptureParams(const CaptureParams&) = delete;
	CaptureParams& operator=(const CaptureParams&) = delete;

private:
	CaptureParams() {}
	~CaptureParams() {}	

	int _width = GameAppParams::DEFAULT_SCREEN_WIDTH;
	int _height = GameAppParams::DEFAULT_SCREEN_HEIGHT;
    float* _zoom_ratio = nullptr;
    Vector2* _offset = nullptr;
};

#endif // !_SCREEN_PARAMS_H_