#include "graint.h"

double	potential(double m, t_vector3 *r_me, t_vector3 *r_you)
{
	t_vector3	x;

	vector_sub(&x, r_me, r_you);
	double norm = vector_norm(&x);
	double f = G * m / norm;
	return f;
}

t_vector3	force(double m, t_vector3 *r_me, t_vector3 *r_you)
{
	t_vector3	x;

	vector_sub(&x, r_me, r_you);
	double norm = vector_norm(&x);
	double f = -G * m / norm / norm;
	// printf("f = %e\n", f);
	vector_mul(&x, &x, f / norm);
	return x;
}

