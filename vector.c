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
