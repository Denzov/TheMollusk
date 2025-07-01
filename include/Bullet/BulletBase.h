#ifndef _BULLES_BASE_H_
#define _BULLES_BASE_H_

#include <raylib.h>
#include <memory>

#include "../TimeManager.h"
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

    virtual void update(EntityManager& manager) override {
        const float Ts = TimeManager::getInstance()->getScaledDeltaTime();

        _submission.pos = add(_submission.pos, multiply(speed_vec, Ts));
    }

    Faction getFaction() const override{
        return Faction::Bullet;
    }

protected:
    const Vector2 speed_vec;
    const float _speed;
    const float _damage;
};

#endif // !_BULLES_BASE_H_