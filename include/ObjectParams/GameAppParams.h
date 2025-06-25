#ifndef _GAME_APP_PARAMS_H_
#define _GAME_APP_PARAMS_H_

#include <raylib.h>

struct GameAppParams {
	static constexpr const char* TITLE = "The Mollusk";
	static constexpr int FPS = 600;
	static constexpr int FIELD_WIDTH = 800;
	static constexpr int FIELD_HEIGHT = 800;
	static constexpr int DEFAULT_SCREEN_WIDTH = FIELD_WIDTH + 100;
	static constexpr int DEFAULT_SCREEN_HEIGHT = FIELD_HEIGHT + 100;
	static constexpr Color BG_COLOR = { 11, 45, 105, 255 };
};

#endif // !_GAME_APP_PARAMS_H_