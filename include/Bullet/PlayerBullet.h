#ifndef _PLAYER_BULLET_H_
#define _PLAYER_BULLET_H_

#include "BulletBase.h"

class PlayerBullet : public BulletBase
{
public:
    PlayerBullet(EntitySubmission submission, float damage, float _speed):
        BulletBase(submission, damage, _speed){}

    void draw() const override {}

private:
    constexpr static float THIS_DAMAGE = 1.0f;
    constexpr static float RADIUS = 4.f;
};

#endif // !_PLAYER_BULLET_H_