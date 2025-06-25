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
        const float left_bullet_rot = _submission.rot - half(half(PI));
        const float right_bullet_rot = _submission.rot + half(half(PI));

        const Vector2 left_bullet_pos  = vec_from_angle(_submission.rot, _submission.radius + BULLET_SPAWN_DELTA, _submission.pos);
        const Vector2 right_bullet_pos = vec_from_angle(_submission.rot, _submission.radius + BULLET_SPAWN_DELTA, _submission.pos);

        manager.addEntity(std::make_shared<DefaultPlayerBullet>(left_bullet_pos, left_bullet_rot));
        manager.addEntity(std::make_shared<DefaultPlayerBullet>(right_bullet_pos, right_bullet_rot));
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