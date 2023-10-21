#ifndef VECTOR_H
#define VECTOR_H

#include <math.h>

#define PI 3.14159265358979323846

typedef struct s_vector2
{
    double x;
    double y;
} t_vector2;

typedef struct s_vector3
{
    float x;
    float y;
    float z;
} t_vector3;

void vector2_set(t_vector2 *this, double x, double y);
t_vector2 vector2(double x, double y);
void vector2_rotate(t_vector2 *this, double angle);
void vector2_translate(t_vector2 *this, double x, double y);
void vector2_scale(t_vector2 *this, double s);
void vector2_add(t_vector2 *this, t_vector2 vec);
void vector2_sub_2(t_vector2 *this, t_vector2 vec);
void vector2_sub_3(t_vector2 *this, t_vector2 a, t_vector2 b);
int vector2_sign(t_vector2 a, t_vector2 b);
double vector2_length(t_vector2 a);
t_vector2 vector2_perp(t_vector2 a);
void vector2_perp_2(t_vector2 *this, t_vector2 a);
double vector2_dot(t_vector2 a, t_vector2 b);
double vector2_cross(t_vector2 a, t_vector2 b);
double vector2_perpDot(t_vector2 a, t_vector2 b);
void vector2_normalize(t_vector2 *this);
double vector2_relative_angle_between(t_vector2 a, t_vector2 b);
double toRadians(double angdeg);
float normalize_angle(float angle);

#endif