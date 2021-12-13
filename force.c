#include "graint.h"

// 質点youによる質点meへの重力ポテンシャル
double	potential(double m_you, t_vector3 *r_me, t_vector3 *r_you)
{
	t_vector3	x;

	vector_sub(&x, r_me, r_you);
	double norm = vector_norm(&x);
	double f = G * m_you / norm;
	return f;
}

// 質点youによる質点meへの質量あたりの重力ベクトル
t_vector3	force(double m_you, t_vector3 *r_me, t_vector3 *r_you)
{
	t_vector3	x;

	vector_sub(&x, r_me, r_you);
	double norm = vector_norm(&x);
	double f = -G * m_you / norm / norm;
	// printf("f = %e\n", f);
	vector_mul(&x, &x, f / norm);
	return x;
}

