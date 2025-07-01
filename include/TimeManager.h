#ifndef _TIME_MANAGER_H_
#define _TIME_MANAGER_H_

#include <raylib.h>

#include "Utililties.h"

class TimeManager{
public:
    static TimeManager* getInstance() {
        static TimeManager instance;
        return &instance;
    }

    float getScaledDeltaTime() const { return _time_scale * GetFrameTime(); }
    float getDeltaTime() const { return GetFrameTime(); }
    float getTimeScale() const { return _time_scale; }
    
    void setTimeScaleByLerp(float target, float lerp_t) {
        _time_scale = lerp(_time_scale, target, lerp_t); 
    }

    void setTimeScale(float scale) { _time_scale = scale; }
    void resetTimeScale() { _time_scale = 1.0f; }
    void addTimeScale(float scale) { _time_scale += scale; }
    void mulTimeScale(float scale) { _time_scale *= scale; }

private:
    float _time_scale = 1.0f;

    TimeManager() = default;
    ~TimeManager() = default;

    TimeManager(const TimeManager&) = delete;
    TimeManager& operator=(const TimeManager&) = delete;
};

#endif // !_TIME_MANAGER_H_