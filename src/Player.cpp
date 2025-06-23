#include "../include/Player/Player.h"

void UserPlayer::addPosition(const Vector2 pos) noexcept{
    _submission.pos = add(_submission.pos, pos);
}

void UserPlayer::addRotation(const float rot) noexcept{
    _submission.rot += rot;
}

void UserPlayer::draw() const {
    if(_drawing_strategy)
        _drawing_strategy->draw(::EntityBase::getSubmission());
}

void UserPlayer::update() {
    if(_control_strategy){
        _input_strategy->handle();
        _control_strategy->update(_submission, _input_strategy->get());
    }
}

void UserPlayer::setDrawerStrategy(std::unique_ptr<IPlayerDrawingStrategy> drawer_strategy){
    _drawing_strategy = std::move(drawer_strategy);
}

void UserPlayer::setControlStrategy(std::unique_ptr<IPlayerControlStrategy> control_strategy){
    _control_strategy = std::move(control_strategy);
}