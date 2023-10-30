#include <Engine.h>

float normalize_angle(float angle)
{
    angle = fmodf(angle, 360);
    if (angle < 0)
        angle += 360;
    return angle;
}

float angle_to_vertex(t_wad_vertex vertex, float x_position, float y_position)
{
    return (normalize_angle(atan2f(vertex.y_position - y_position, vertex.x_position - x_position) * 180 / PI));
}

bool clip_vertexes_in_fov(t_map *this, t_wad_vertex *v1, t_wad_vertex *v2)
{
    float v1Angle = angle_to_vertex(*v1, this->player.x_position, this->player.y_position);
    float V2Angle = angle_to_vertex(*v2, this->player.x_position, this->player.y_position);

    float v1ToV2Span = normalize_angle(v1Angle - V2Angle);

    if (v1ToV2Span >= 180)
    {
        return false;
    }

    // Rotate everything.
    v1Angle = normalize_angle(v1Angle - this->player.angle);
    V2Angle = normalize_angle(V2Angle - this->player.angle);

    float HalfFOV = normalize_angle(FOV / 2);

    // Validate and Clip v1
    // shift angles to be between 0 and 90 (now virtually we shifted FOV to be in that range)
    float v1Moved = normalize_angle(v1Angle + HalfFOV);

    if (v1Moved > FOV)
    {
        // now we know that v1, is outside the left side of the FOV
        // But we need to check is Also V2 is outside.
        // Let's find out what is the size of the angle outside the FOV
        float v1MovedAngle = normalize_angle(v1Moved - FOV);

        // Are both v1 and V2 outside?
        if (v1MovedAngle >= v1ToV2Span)
        {
            return false;
        }

        // At this point V2 or part of the line should be in the FOV.
        // We need to clip the v1
        v1Angle = normalize_angle(HalfFOV);
    }

    // Validate and Clip V2
    float V2Moved = normalize_angle(HalfFOV - V2Angle);

    // Is V2 outside the FOV?
    if (V2Moved > FOV)
    {
        V2Angle = normalize_angle(-HalfFOV);
    }

    v1Angle += 90;
    V2Angle += 90;

    return true;
}