#ifndef _PLAYER_CONTROL_STRATEGY_H_
#define _PLAYER_CONTROL_STRATEGY_H_

#include <raylib.h>

#include "../Utililties.h"
#include "../TimeManager.h"

#include "../ObjectParams/GameAppParams.h"
#include "../ObjectParams/EntitySubmission.h"
#include "../ObjectParams/CaptureParams.h"

#include "PlayerInputStrategy.h"

class IPlayerControlStrategy {
public:
    virtual ~IPlayerControlStrategy() = default;
    virtual void update(EntitySubmission& submission, const PlayerInput& input) = 0;
};

class DefaultPlayerControlStrategy : public IPlayerControlStrategy {
public:
    void update(EntitySubmission& submission, const PlayerInput& input) override {
        slowmotion_control(input);

        const float next_rot = rot_to_mouse(submission.pos, input.mouse_pos);
        const Vector2 next_pos = add(submission.pos, shoot_moving(input, next_rot));

        submission.pos = next_pos;
        submission.rot = next_rot;
    }

private:
    float rot_to_mouse(const Vector2& base, const Vector2& target) const{
        const float zoom_scale = 1.f / CaptureParams::getInstance()->getZoomRatio();
        const Vector2 target_position = multiply(target, zoom_scale);
        const Vector2 scaled_screen_centre = {
            half(CaptureParams::getInstance()->getWidth()) * zoom_scale,
            half(CaptureParams::getInstance()->getHeight()) * zoom_scale
        };

        const float dx = target_position.x - base.x - scaled_screen_centre.x;
        const float dy = target_position.y - base.y - scaled_screen_centre.y;
        
        const float next_rot = std::atan2(dy, dx);
        return next_rot;
    }

    Vector2 shoot_moving(const PlayerInput& input, const float rot){
        const bool need_shoot = input.is_fire;
        
        const float Ts = TimeManager::getInstance()->getScaledDeltaTime();

        const Vector2 norm_speed = { -std::cos(rot), -std::sin(rot) };

        const Vector2 target_speed = need_shoot?
            multiply(norm_speed, MAX_SPEED) : ZERO_SPEED;

        const float T = need_shoot?
            ACCEL_TIME : DECEL_TIME;

        const float lerp_t = 1.f - std::exp(-Ts / T);

        _context_speed.x = lerp(_context_speed.x, target_speed.x, lerp_t);
        _context_speed.y = lerp(_context_speed.y, target_speed.y, lerp_t);

        return multiply(_context_speed, Ts);
    }

    void slowmotion_control(const PlayerInput& input) {
        if(input.is_slowmotion){
            TimeManager::getInstance()->setTimeScaleByLerp(SLOWMOTION_TARGET, SMOOTHING_SLOWMOTION);
        }
        else{
            TimeManager::getInstance()->setTimeScaleByLerp(SLOWMOTION_DEFAULT, SMOOTHING_SLOWMOTION);
        }
    }

private:
    Vector2 _context_speed = {0, 0};

    static constexpr Vector2 ZERO_SPEED = {0, 0};
    static constexpr float ACCEL_TIME = 0.2f;
    static constexpr float DECEL_TIME = 0.6f;
    static constexpr float MAX_SPEED = 3000.f;

    static constexpr float SLOWMOTION_TARGET = 0.1f;
    static constexpr float SLOWMOTION_DEFAULT = 1.f;
    static constexpr float SMOOTHING_SLOWMOTION = 0.05f;
};

#endif // !_PLAYER_CONTROL_STRATEGY_H_