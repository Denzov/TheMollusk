#ifndef _PLAYER_INPUT_STRATEGY_H_
#define _PLAYER_INPUT_STRATEGY_H_

#include <raylib.h>
#include <stdint.h>

struct PlayerInput
{
    Vector2 mouse_pos;
    bool is_fire;
};

class IPlayerInputStrategy{
public:
    virtual ~IPlayerInputStrategy() = default;
    virtual void handle() = 0;
    virtual PlayerInput get() const = 0;    
};

class DefaultPlayerInputStrategy : public IPlayerInputStrategy{
public:
    void handle() override{
        _input.mouse_pos = GetMousePosition();
        if(GetTime() - _last_cooldown_time < _shoot_cooldown) _input.is_fire = false;
        else{
            _input.is_fire = IsKeyDown(MOVING_KEYS::KEY_SHOOT);
            
            if(_input.is_fire) _last_cooldown_time = GetTime();
        }
    }

    PlayerInput get() const override{ return _input; }
    void setCooldown(float cooldown) { _shoot_cooldown = cooldown; }

private:
    enum MOVING_KEYS : uint16_t{
        KEY_SHOOT = KEY_F,
    };
    
    static constexpr float DEFAULT_COOLDOWN = 0.32f;

    float _shoot_cooldown = DEFAULT_COOLDOWN;

    float _last_cooldown_time = 0;

    PlayerInput _input = { {0, 0}, false };
};

class NullPlayerInputStrategy : public IPlayerInputStrategy{
public:
    void handle() override{}
    PlayerInput get() const override{ return { {0, 0}, false }; }
};

#endif // !_PLAYER_INPUT_STRATEGY_H_