#ifndef _PLAYER_DRAWING_STRATEGY_H_
#define _PLAYER_DRAWING_STRATEGY_H_

#include <raylib.h>
#include <iostream>

#include "../Utililties.h"
#include "../ObjectParams/EntitySubmission.h"

class IPlayerDrawingStrategy {
public:
    virtual ~IPlayerDrawingStrategy() = default;
    virtual void draw(const EntitySubmission current) const = 0;
};

class DefaultPlayerDrawingStrategy : public IPlayerDrawingStrategy {
public:
    void draw(const EntitySubmission current) const override{
        const float left_side_point_angle  = current.rot - side_points_angle;
        const float right_side_point_angle = current.rot + side_points_angle;

        const float side_points_radius = current.radius + 7.f;
        const float fwd_points_radius  = current.radius + 12.f;

        const Vector2 left_side_point      = vec_from_angle(left_side_point_angle, side_points_radius, current.pos);
        const Vector2 right_side_point     = vec_from_angle(right_side_point_angle, side_points_radius, current.pos);

        const float left_fwd_point_angle   = current.rot - fwd_points_angle;
        const float right_fwd_point_angle  = current.rot + fwd_points_angle;
        const Vector2 left_fwd_point       = vec_from_angle(left_fwd_point_angle, fwd_points_radius, current.pos);   
        const Vector2 right_fwd_point      = vec_from_angle(right_fwd_point_angle, fwd_points_radius, current.pos); 

        DrawLineBezierCubic(left_side_point, right_side_point, left_fwd_point, right_fwd_point, line_thick, line_color);
        DrawCircleV(current.pos, current.radius, circle_color);
    }

private:
    static constexpr Color circle_color = { 166, 173, 186, 255 };
    static constexpr Color line_color = RED;

    static constexpr float line_thick = 1.5f;
    static constexpr float side_points_angle = 60 * DEG2RAD;
    static constexpr float fwd_points_angle = 20 * DEG2RAD;
};

#endif // !_PLAYER_DRAWING_STRATEGY_H_