#ifndef _BULLES_BASE_H_
#define _BULLES_BASE_H_

#include <raylib.h>
#include <memory>

#include "../Entity/EntityBase.h"

class BulletBase : public EntityBase{
public:
    BulletBase(EntitySubmission submission, float damage, float _speed): 
        _damage(damage), _speed(_speed),
        ::EntityBase(submission), 
        speed_vec {
            std::cos(submission.rot) * _speed,
            std::sin(submission.rot) * _speed
        } {};

    float getDamage() const {
        return _damage;
    }

    void update(EntityManager& manager) override {
        const float constrained_fps = constrain(GetFPS(), 1, GameAppParams::FPS);
        const float Ts = 1.f / constrained_fps;

        _submission.pos = add(_submission.pos, multiply(speed_vec, Ts));
    }

protected:
    const Vector2 speed_vec;
    
    const float _speed;
    const float _damage;
};

#endif // !_BULLES_BASE_H_