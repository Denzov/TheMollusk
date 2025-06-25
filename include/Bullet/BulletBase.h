#ifndef _BULLES_BASE_H_
#define _BULLES_BASE_H_

#include <raylib.h>
#include <memory>

#include "../Entity/EntityBase.h"

class BulletBase : public EntityBase{
public:
    BulletBase(EntitySubmission submission, float damage, float _speed): 
        _damage(damage), _speed(_speed),
        ::EntityBase(submission){};

    float getDamage() const {
        return _damage;
    }

    void update(EntityManager& manager) override {
        const Vector2 rot_vec = { std::cos(_submission.rot), std::sin(_submission.rot) };
        _submission.pos = add(_submission.pos, multiply(rot_vec, _speed));
    }

protected:
    float _speed;
    float _damage;
};

using AbstractBullet_ptr = std::shared_ptr<BulletBase>;

#endif // !_BULLES_BASE_H_