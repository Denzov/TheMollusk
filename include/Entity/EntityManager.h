#ifndef _ENTITY_MANAGER_H_
#define _ENTITY_MANAGER_H_

#include <memory>
#include <vector>
#include <array>

#include "IEntity.h"

class EntityManager{
public:
    void update(){
        auto& player_entities = _entities[to_int(Faction::Player)];
        for(size_t i = 0; i < player_entities.size();){
            if(!player_entities[i]->isAlive() || !player_entities[i]->isInField()){
                player_entities.erase(player_entities.begin() + i);
                continue;
            }

            player_entities[i++]->update(*this);
        }

        auto& enemy_entities = _entities[to_int(Faction::Enemy)];
        for(size_t i = 0; i < enemy_entities.size();){
            if(!enemy_entities[i]->isAlive() || !enemy_entities[i]->isInField()){
                enemy_entities.erase(enemy_entities.begin() + i);
                continue;
            }

            enemy_entities[i++]->update(*this);
        }

        auto& bullet_entities = _entities[to_int(Faction::Bullet)];
        for(size_t i = 0; i < bullet_entities.size();){
            if(!bullet_entities[i]->isAlive() || !bullet_entities[i]->isInField()){
                bullet_entities.erase(bullet_entities.begin() + i);
                continue;
            }

            bullet_entities[i]->update(*this);

            for(auto& enemy : enemy_entities){
                if(bullet_entities[i]->isCollide(*enemy)){
                    bullet_entities[i]->destroy();
                    enemy->destroy();
                }
            } ++i;
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
        for(int i = 0; i < get_faction_size(); i++){
        }
    }

    uint32_t getEntitiesCount() const{ 
        uint32_t count = 0;
        for(const auto& entity_vector : _entities){
            count += entity_vector.size();
        }

        return count; 
    }

private:
    using IEntityVector = std::vector<IEntityPtr>;
    std::array<IEntityVector, get_faction_size()> _entities;
};

#endif // !_ENTITY_MANAGER_H_