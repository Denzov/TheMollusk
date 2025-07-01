#ifndef _PLAYER_BULLET_H_
#define _PLAYER_BULLET_H_

#include "BulletBase.h"

class DefaultPlayerBullet : public BulletBase
{
public:
    DefaultPlayerBullet(Vector2 pos, float rot): BulletBase({pos, rot, THIS_RADIUS}, THIS_DAMAGE, THIS_SPEED){}

    void draw() const override {
        DrawCircleV(_submission.pos, _submission.radius, THIS_COLOR);
        DrawCircleV(_submission.pos, _submission.radius - 1.f, BLACK);
    }

private:
    static constexpr Color THIS_COLOR = YELLOW;
    static constexpr float THIS_RADIUS = 4.f;
    static constexpr float THIS_SPEED = 100.f;
    static constexpr float THIS_DAMAGE = 1.f;
};

class FastPlayerBullet : public BulletBase
{
public:
    FastPlayerBullet(Vector2 pos, float rot): 
        BulletBase({pos, rot, THIS_RADIUS}, THIS_DAMAGE, THIS_SPEED){}

    void draw() const override {
        DrawCircleV(_submission.pos, _submission.radius, THIS_COLOR);
        DrawCircleV(_submission.pos, _submission.radius * 0.7f, WHITE);
    }

private:
    static constexpr Color THIS_COLOR = RED;
    static constexpr float THIS_RADIUS = 6.f;
    static constexpr float THIS_SPEED = 600.f;
    static constexpr float THIS_DAMAGE = 1.f;
};

#endif // !_PLAYER_BULLET_H_