#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <raylib.h>
#include <memory>

#include "../Utililties.h"
#include "../ObjectParams/GameAppParams.h"

#include "../Entity/EntityBase.h"
#include "../Entity/EntityManager.h"

#include "../Bullet/BulletMaker.h"
#include "../Bullet/PlayerBullet.h"

#include "PlayerDrawingStrategy.h"
#include "PlayerControlStrategy.h"
#include "PlayerInputStrategy.h"

class UserPlayer : public EntityBase{
private:
    using DrawingStrategy_ptr = std::unique_ptr<IPlayerDrawingStrategy>;
    using ControlStrategy_ptr = std::unique_ptr<IPlayerControlStrategy>;
    using InputStrategy_ptr = std::unique_ptr<IPlayerInputStrategy>;
public:
    UserPlayer(): 
            _drawing_strategy(std::make_unique<DefaultPlayerDrawingStrategy>()),
            _control_strategy(std::make_unique<DefaultPlayerControlStrategy>()),
            _input_strategy(std::make_unique<DefaultPlayerInputStrategy>()),
            ::EntityBase(THIS_RADIUS) {}

    UserPlayer(const Vector2 position, const float rotation):
            _drawing_strategy(std::make_unique<DefaultPlayerDrawingStrategy>()),
            _control_strategy(std::make_unique<DefaultPlayerControlStrategy>()),
            _input_strategy(std::make_unique<DefaultPlayerInputStrategy>()),
            ::EntityBase({position, rotation, THIS_RADIUS}){}
    
    UserPlayer(const Vector2 position, const float rotation, 
        DrawingStrategy_ptr drawer_strategy,
        ControlStrategy_ptr control_strategy,
        InputStrategy_ptr input_strategy):
            _drawing_strategy(std::move(drawer_strategy)),
            _control_strategy(std::move(control_strategy)),
            _input_strategy(std::move(input_strategy)),
            ::EntityBase({position, rotation, THIS_RADIUS}){}

    void    addPosition(const Vector2 position)     noexcept;
    void    addRotation(const float rotation)       noexcept;

    void    draw()                                  const override;
    void    update(EntityManager& manager)          override;

    void    setDrawerStrategy(DrawingStrategy_ptr drawer_strategy);
    void    setControlStrategy(ControlStrategy_ptr control_strategy);

    bool    isFire()                                const;

private:
    DrawingStrategy_ptr _drawing_strategy;
    ControlStrategy_ptr _control_strategy;
    InputStrategy_ptr _input_strategy;

    static constexpr float THIS_RADIUS = 7.f;
    static constexpr float BULLET_SPAWN_DELTA = 15.f;
};

#endif // !_PLAYER_H_