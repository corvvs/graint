#include "graint.h"

double	vector_norm(t_vector3 *v)
{
	return sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
}

void	vector_add(t_vector3 *ans, t_vector3 *r1, t_vector3 *r2)
{
	ans->x = r1->x + r2->x;
	ans->y = r1->y + r2->y;
	ans->z = r1->z + r2->z;
}

void	vector_sub(t_vector3 *ans, t_vector3 *r1, t_vector3 *r2)
{
	ans->x = r1->x - r2->x;
	ans->y = r1->y - r2->y;
	ans->z = r1->z - r2->z;
}

void	vector_mul(t_vector3 *ans, t_vector3 *r1, double d)
{
	ans->x = r1->x * d;
	ans->y = r1->y * d;
	ans->z = r1->z * d;
}

void	vector_cross(t_vector3 *ans, t_vector3 *r1, t_vector3 *r2)
{
	ans->x = r1->y * r2->z - r1->z * r2->y;
	ans->y = r1->z * r2->x - r1->x * r2->z;
	ans->z = r1->x * r2->y - r1->y * r2->x;
}

double	vector_dot(t_vector3 *r1, t_vector3 *r2)
{
	double v = 0;
	v += r1->x * r2->x;
	v += r1->y * r2->y;
	v += r1->x * r2->x;
	return v;
}
