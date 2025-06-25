#ifndef _BULLET_MAKER_H_
#define _BULLET_MAKER_H_

#include "../Utililties.h"
#include "../Entity/EntityManager.h"
#include "BulletBase.h"

class BulletMaker
{
public:
    template<class Origin>
    static void makeRange(EntityManager& manager,
            const Vector2& base_pos, const float base_rot,
            const float num_bullets, const float range_angle, const float spawn_length){

        const float delta_angle = range_angle / (num_bullets - 1);
        const float angle_0 = base_rot - range_angle / 2;

        const Vector2 spawn_point = vec_from_angle(base_rot, spawn_length, base_pos);

        for(size_t i = 0; i < num_bullets; ++i){
            const float angle = angle_0 + delta_angle * i;
            manager.addEntity(std::make_unique<Origin>(spawn_point, angle));
        }
    }

private:
    BulletMaker() = delete;
    ~BulletMaker() = delete;
};

#endif // !_BULLET_MAKER_H_