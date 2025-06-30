#ifndef _ENTITY_BASE_H_
#define _ENTITY_BASE_H_

#include <iostream>

#include "IEntity.h"
#include "../ObjectParams/GameAppParams.h"

class EntityBase : public IEntity {
public:
    virtual ~EntityBase() = default;

    EntityBase(EntitySubmission submission) : _submission(submission) {}
    EntityBase(float radius) : _submission({ DEFAULT_POSITION, DEFAULT_ROTATION, radius}) {}

    bool isAlive() const override{ return _is_alive; }
    void destroy() override{ _is_alive = false; }
    
    void setSubmission(const EntitySubmission submission) override{ _submission = submission; }
    void setPosition(const Vector2 position) override{ _submission.pos = position; }
    void setRotation(const float rotation) override{ _submission.rot = rotation; }

    EntitySubmission getSubmission() const override{ return _submission; }

    bool isCollide(const IEntity& other) const override{ 
        return CheckCollisionCircles(
            this->_submission.pos, this->_submission.radius,
            other.getSubmission().pos, other.getSubmission().radius
        );
    }

    bool isInField() const override{ 
        const bool is_in_x = -GameAppParams::FIELD_WIDTH/2 < _submission.pos.x + _submission.radius &&
                             _submission.pos.x - _submission.radius < GameAppParams::FIELD_WIDTH/2;
        const bool is_in_y = -GameAppParams::FIELD_HEIGHT/2 < _submission.pos.y + _submission.radius &&
                             _submission.pos.y - _submission.radius < GameAppParams::FIELD_HEIGHT/2;
        return is_in_x && is_in_y;
    }

    int getFactionInt() const override{ 
        return static_cast<int>(getFaction()); 
    }

protected:
    static constexpr Vector2 DEFAULT_POSITION = { 0, 0 };
    static constexpr float DEFAULT_ROTATION = 0;
    
    bool _is_alive = true;
    EntitySubmission _submission = {};
};

#endif // !_ENTITY_BASE_H_