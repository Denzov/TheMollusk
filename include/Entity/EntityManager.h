#ifndef _ENTITY_MANAGER_H_
#define _ENTITY_MANAGER_H_

#include <memory>
#include <vector>

#include "IEntity.h"

class EntityManager{
public:
    void update(){
        for(size_t i = 0; i < _entities.size();){
            if(!_entities[i]->isAlive() || !_entities[i]->isInField()){
                _entities.erase(_entities.begin() + i);
                continue;
            }

            _entities[i++]->update(*this);
        }
    }

    void draw() const{
        for(const auto& entity : _entities)
            entity->draw();
    }

    void addEntity(std::shared_ptr<IEntity> entity){
        _entities.push_back(entity);
    }

private:
    std::vector<std::shared_ptr<IEntity>> _entities;
};

using EntityManager_ptr = std::shared_ptr<EntityManager>;

#endif // !_ENTITY_MANAGER_H_