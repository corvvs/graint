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
t_vector3	accel(double m_you, t_vector3 *r_me, t_vector3 *r_you)
{
	t_vector3	a;

	vector_sub(&a, r_me, r_you);
	double norm3 = pow(vector_norm(&a), 3);
	double f = -G * m_you / norm3;
	vector_mul(&a, &a, f);
	return a;
}

