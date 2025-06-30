#ifndef _ENEMY_H_
#define _ENEMY_H_

#include <raylib.h>
#include <memory>

#include "../Entity/EntityBase.h"

template<class Derived>
class EnemyTemplate : public EntityBase{
public:
    EnemyTemplate(Vector2 pos, float rot) : EntityBase({pos, rot, Derived::getRadius()}){}

    Faction getFaction() const override{ 
        return Faction::Enemy;
    }
};

class Enemy1 : public EnemyTemplate<Enemy1>{
public:
    using EnemyTemplate::EnemyTemplate;

    void draw() const override{
        DrawCircleV(_submission.pos, _submission.radius, THIS_COLOR);
    }

    void update(EntityManager& manager) override{
    
    }

    static float getRadius() {
        return THIS_RADIUS;
    }

private:
    static constexpr float THIS_RADIUS = 10.f;
    static constexpr Color THIS_COLOR = RED;

};

#endif // !_ENEMY_H_