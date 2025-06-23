#ifndef _GAME_APP_PARAMS_H_
#define _GAME_APP_PARAMS_H_

#include <raylib.h>

struct GameAppParams {
	static constexpr const char* TITLE = "The Mollusk";
	static constexpr int FPS = 30;
	static constexpr int UPF = 20; // updates per frame
	static constexpr int FIELD_WIDTH = 1000;
	static constexpr int FIELD_HEIGHT = 1000;
	static constexpr Color BG_COLOR = { 40, 100, 200, 255 };
};

#endif // !_GAME_APP_PARAMS_H_