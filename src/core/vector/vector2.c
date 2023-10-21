#include <Vector.h>

void vector2_set(t_vector2 *this, double x, double y)
{
    this->x = x;
    this->y = y;
}

t_vector2 vector2(double x, double y)
{
    return (t_vector2){x, y};
}

void vector2_rotate(t_vector2 *this, double angle)
{
    double nx = this->x * cos(angle) - this->y * sin(angle);
    double ny = this->x * sin(angle) + this->y * cos(angle);
    this->x = nx;
}

void vector2_translate(t_vector2 *this, double x, double y)
{
    this->x += x;
    this->y += y;
}

void vector2_scale(t_vector2 *this, double s)
{
    this->x *= s;
    this->y *= s;
}

void vector2_add(t_vector2 *this, t_vector2 vec)
{
    this->x += vec.x;
    this->y += vec.y;
}

void vector2_sub_2(t_vector2 *this, t_vector2 vec)
{
    this->x -= vec.x;
    this->y -= vec.y;
}

void vector2_sub_3(t_vector2 *this, t_vector2 a, t_vector2 b)
{
    this->x = a.x - b.x;
    this->y = a.y - b.y;
}

int vector2_sign(t_vector2 a, t_vector2 b)
{
    return (a.y * b.x > a.x * b.y) ? -1 : 1;
}

double vector2_length(t_vector2 a)
{
    return sqrt(a.x * a.x + a.y * a.y);
}

t_vector2 vector2_perp(t_vector2 a)
{
    return (t_vector2){-a.y, a.x};
}

void vector2_perp_2(t_vector2 *this, t_vector2 a)
{
    this->x = -a.y;
    this->y = a.x;
}
double vector2_dot(t_vector2 a, t_vector2 b)
{
    return a.x * b.x + a.y * b.y;
}

double vector2_cross(t_vector2 a, t_vector2 b)
{
    return a.x * b.y - a.y * b.x;
}

double vector2_perpDot(t_vector2 a, t_vector2 b)
{
    return a.x * b.y - a.y * b.x;
}

void vector2_normalize(t_vector2 *this)
{
    double length = vector2_length(*this);
    if (length == 0)
    {
        this->x = 0;
        this->y = 0;
    }
    else
    {
        double den = 1 / length;
        this->x *= den;
        this->y *= den;
    }
}

double vector2_relative_angle_between(t_vector2 a, t_vector2 b)
{
    return vector2_sign(a, b) * acos(vector2_dot(a, b) /
                                     (vector2_length(a) * vector2_length(b)));
}

/**
 *   Converts an angle measured in degrees to an approximately equivalent angle measured in radians. The conversion from degrees to radians is generally inexact.
 *   Params:
 *   angdeg – an angle, in degrees
 *   Returns:
 */
double toRadians(double angdeg)
{
    return (angdeg * 0.017453292519943295);
}

