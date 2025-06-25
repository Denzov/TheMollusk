#ifndef _PLAYER_BULLET_H_
#define _PLAYER_BULLET_H_

#include "BulletBase.h"

template<class Derived>
class PlayerBulletTemplate : public BulletBase{
public:
    PlayerBulletTemplate(Vector2 pos, float rot):
        BulletBase({pos, rot, Derived::getRadius()}, Derived::getDamage(), Derived::getSpeed()){}
};

class DefaultPlayerBullet : public PlayerBulletTemplate<DefaultPlayerBullet>
{
public:
    using PlayerBulletTemplate<DefaultPlayerBullet>::PlayerBulletTemplate;

    void draw() const override {
        DrawCircleV(_submission.pos, _submission.radius, THIS_COLOR);
    }

    static constexpr float getRadius() { return THIS_RADIUS; }
    static constexpr float getSpeed()  { return THIS_SPEED; }
    static constexpr float getDamage() { return THIS_DAMAGE; }

private:
    static constexpr Color THIS_COLOR = YELLOW;
    static constexpr float THIS_RADIUS = 4.f;
    static constexpr float THIS_SPEED = 300.f;
    static constexpr float THIS_DAMAGE = 1.f;
};

#endif // !_PLAYER_BULLET_H_