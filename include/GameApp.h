#ifndef _APP_H_
#define _APP_H_

#include <vector>

#include "ObjectParams/GameAppParams.h"
#include "ObjectParams/CaptureParams.h"

#include "GameCamera.h"

#include "Entity/EntityManager.h"
#include "Player/Player.h"
#include "Bullet/PlayerBullet.h"

class GameApp : public GameAppParams {
public:
	void Run();

private:
	void init();
	void simulate();
	void compute();
	void draw();
	void close();

private:
	GameCamera _camera;

	EntityManager _entities;
	std::shared_ptr<UserPlayer> _main_player;
};

#endif // !_APP_H_