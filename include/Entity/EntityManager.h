#ifndef _ENTITY_MANAGER_H_
#define _ENTITY_MANAGER_H_

#include <memory>
#include <vector>
#include <list>
#include <array>

#include "IEntity.h"

class EntityManager{
private:
    using IEntityVector = std::vector<IEntityPtr>;
    using IEntityList = std::list<IEntityPtr>;

public:
    void update(){
        auto& player_entities = _entities[to_int(Faction::Player)];
        for(size_t i = 0; i < player_entities.size();){
            if(try_erase_entity(player_entities, i)) continue;

            player_entities[i++]->update(*this);
        }

        auto& enemy_entities = _entities[to_int(Faction::Enemy)];
        for(size_t i = 0; i < enemy_entities.size();){
            if(try_erase_entity(enemy_entities, i)) continue;

            enemy_entities[i++]->update(*this);
        }

        auto& bullet_entities = _entities[to_int(Faction::Bullet)];
        for(size_t i = 0; i < bullet_entities.size();){
            if(try_erase_entity(bullet_entities, i)) continue;

            bullet_entities[i]->update(*this);

            for(auto& enemy : enemy_entities){
                if(bullet_entities[i]->isCollide(*enemy)){
                    // bullet_entities[i]->destroy();
                    enemy->destroy();
                }
            } ++i;
        }

        for(uint32_t i = 0; i < MAX_DESTROYED_ENTITIES_PER_TICK; i++){
            if(_destroyed_entities.empty()) break;
            _destroyed_entities.pop_back();
        }
    }

    void draw() const{
        for(const auto& entity_vector : _entities){
            for(const auto& entity : entity_vector){
                entity->draw();
            }
        }
    }

    void addEntity(std::unique_ptr<IEntity> entity){
        _entities[entity->getFactionInt()].push_back(std::move(entity));
    }

    uint32_t getEntitiesCount() const{ 
        uint32_t count = 0;
        for(const auto& entity_vector : _entities){
            count += entity_vector.size();
        }

        return count; 
    }

    uint32_t getDestroyedEntitiesCount() const{
        return _destroyed_entities.size();
    }

private:
    void erase_fast(IEntityVector& vec, size_t i) {
        if (i < vec.size()) {
            vec[i] = std::move(vec.back());
            vec.pop_back();
        }
    }

    bool try_erase_entity(IEntityVector& vec, size_t i){
        if(!vec[i]->isAlive() || !vec[i]->isInField()){
                _destroyed_entities.push_back(std::move(vec[i]));
                erase_fast(vec, i);
                return true;
        }
        return false;
    }

private:
    std::array<IEntityVector, get_faction_size()> _entities;
    IEntityList _destroyed_entities;

    static constexpr uint32_t MAX_DESTROYED_ENTITIES_PER_TICK = 100;
};

#endif // !_ENTITY_MANAGER_H_