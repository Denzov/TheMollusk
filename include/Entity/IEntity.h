#ifndef _I_ENTITY_H_
#define _I_ENTITY_H_

#include <functional>
#include "../ObjectParams/EntitySubmission.h"

class EntityManager;

class IEntity
{
public:
    virtual ~IEntity() = default;
    
    virtual void draw() const = 0;
    virtual void update(EntityManager& manager) = 0;
    virtual bool isAlive() const = 0;
    virtual void destroy() = 0;

    virtual void setSubmission(const EntitySubmission submission) = 0;
    virtual void setPosition(const Vector2 position) = 0;
    virtual void setRotation(const float rotation) = 0;

    virtual EntitySubmission getSubmission() const = 0;

    virtual bool isInField() const = 0;
    virtual bool isCollide(const IEntity& other) const = 0;
};

#endif // !_I_ENTITY_H_