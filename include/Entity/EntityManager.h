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

    void addEntity(std::unique_ptr<IEntity> entity){
        _entities.push_back(std::move(entity));
    }

    uint32_t getEntitiesCount() const{ return _entities.size(); }

private:
    std::vector<std::unique_ptr<IEntity>> _entities;
};

#endif // !_ENTITY_MANAGER_H_