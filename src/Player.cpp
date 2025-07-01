#include "../include/Player/Player.h"

void UserPlayer::addPosition(const Vector2 pos) noexcept{
    _submission.pos = add(_submission.pos, pos);
}

void UserPlayer::addRotation(const float rot) noexcept{
    _submission.rot += rot;
}

void UserPlayer::draw() const {
    _drawing_strategy->draw(_submission, BULLET_SPAWN_DELTA);
}

void UserPlayer::update(EntityManager& manager) {
    _input_strategy->handle();
    _control_strategy->update(_submission, _input_strategy->get());

    if(_input_strategy->get().is_fire){
        BulletMaker::rangeProcess<DefaultPlayerBullet>(manager, _submission.pos, _submission.rot, 180, 60 * DEG2RAD, BULLET_SWAWN_RADIUS);
    }
}

void UserPlayer::setDrawerStrategy(std::unique_ptr<IPlayerDrawingStrategy> drawer_strategy){
    _drawing_strategy = std::move(drawer_strategy);
}

void UserPlayer::setControlStrategy(std::unique_ptr<IPlayerControlStrategy> control_strategy){
    _control_strategy = std::move(control_strategy);
}

bool UserPlayer::isFire() const{
    return _input_strategy->get().is_fire;
}

Faction UserPlayer::getFaction() const{ 
    return Faction::Player; 
}