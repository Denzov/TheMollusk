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
        _mouse_pos = GetMousePosition();

        if(GetTime() - last_time < SHOOT_COOLDOWN) _is_fire = false;
        else{
            _is_fire = IsKeyDown(MOVING_KEYS::KEY_SHOOT);
            
            if(_is_fire)
                last_time = GetTime();
        }

    }
    PlayerInput get() const override{ return { _mouse_pos, _is_fire }; }

private:
    enum MOVING_KEYS : uint16_t{
        KEY_SHOOT = KEY_F,
    };
    static constexpr float SHOOT_COOLDOWN = 0.4f;

    float last_time = 0;
    Vector2 _mouse_pos = { 0, 0 };
    bool _is_fire = false;
};

class NullPlayerInputStrategy : public IPlayerInputStrategy{
public:
    void handle() override{}
    PlayerInput get() const override{ return { {0, 0}, false }; }
};

#endif // !_PLAYER_INPUT_STRATEGY_H_