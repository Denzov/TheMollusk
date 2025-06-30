#ifndef _PLAYER_DRAWING_STRATEGY_H_
#define _PLAYER_DRAWING_STRATEGY_H_

#include <raylib.h>
#include <iostream>

#include "../Utililties.h"
#include "../ObjectParams/EntitySubmission.h"

class IPlayerDrawingStrategy {
public:
    virtual ~IPlayerDrawingStrategy() = default;
    virtual void draw(const EntitySubmission current, const float bullet_spawn_radius) const = 0;
};

class DefaultPlayerDrawingStrategy : public IPlayerDrawingStrategy {
public:
    void draw(const EntitySubmission current, const float bullet_spawn_radius) const override{
        draw_main_body(current);
        draw_direction_arrow(current, bullet_spawn_radius);
    }

private:
    void draw_main_body(const EntitySubmission& current) const{
        DrawCircleV(current.pos, current.radius, circle_color);
        DrawCircleV(current.pos, current.radius - 1.f, GRAY);
    }

    void draw_direction_arrow(const EntitySubmission& current, const float bullet_spawn_radius) const{
        const float left_side_point_angle       = current.rot - side_points_angle;
        const float left_fwd_point_angle        = current.rot - fwd_points_angle;
        const float left_direction_point_angle  = current.rot - direction_points_angle;
        
        const float right_side_point_angle      = current.rot + side_points_angle;
        const float right_fwd_point_angle       = current.rot + fwd_points_angle;
        const float right_direction_point_angle = current.rot + direction_points_angle;

        const float side_points_radius      = current.radius + side_points_delta;
        const float fwd_points_radius       = current.radius + fwd_points_delta;
        const float direction_points_radius = current.radius + bullet_spawn_radius;

        const Vector2 left_side_point       = vec_from_angle(left_side_point_angle, side_points_radius, current.pos);
        const Vector2 left_fwd_point        = vec_from_angle(left_fwd_point_angle, fwd_points_radius, current.pos);   
        const Vector2 left_direction_point  = vec_from_angle(left_direction_point_angle, direction_points_radius, current.pos);
        
        const Vector2 right_side_point      = vec_from_angle(right_side_point_angle, side_points_radius, current.pos);
        const Vector2 right_fwd_point       = vec_from_angle(right_fwd_point_angle, fwd_points_radius, current.pos); 
        const Vector2 right_direction_point = vec_from_angle(right_direction_point_angle, direction_points_radius, current.pos);

        DrawLineBezierCubic(left_side_point, right_side_point, left_fwd_point, right_fwd_point, line_thick, line_color);
        DrawLineBezierCubic(left_fwd_point, right_fwd_point, left_direction_point, right_direction_point, line_thick, line_color);
    }

    void draw_op_direction_arrow(const EntitySubmission& current, const float bullet_spawn_radius) const{
        const float   op_angle                 = current.rot + PI;
        const Vector2 op_right_side_point      = vec_from_angle(op_angle + side_points_angle, current.radius + side_points_delta, current.pos);
        const Vector2 op_left_side_point       = vec_from_angle(op_angle - side_points_angle, current.radius + side_points_delta, current.pos);
        const Vector2 centre_point             = vec_from_angle(op_angle, current.radius, current.pos);

        DrawLineBezierCubic(op_right_side_point, op_left_side_point, centre_point, centre_point, line_thick, line_color);
    }

    static constexpr Color circle_color = { 166, 173, 186, 255 };
    static constexpr Color line_color = RED;

    static constexpr float side_points_delta = 6.f;
    static constexpr float fwd_points_delta = 7.f;

    static constexpr float side_points_angle = 60 * DEG2RAD;
    static constexpr float fwd_points_angle = 20 * DEG2RAD;
    static constexpr float direction_points_angle = 10 * DEG2RAD;
    
    static constexpr float line_thick = 2.f;
};

#endif // !_PLAYER_DRAWING_STRATEGY_H_