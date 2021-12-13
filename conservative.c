#include "graint.h"

// 角運動量
t_vector3	angular_momentum(t_system *system)
{
	t_vector3	f;
	t_vector3	i = {0};

	vector_cross(&f, &system->r1, &system->v1);
	vector_mul(&f, &f, system->m1);
	vector_add(&i, &i, &f);
	vector_cross(&f, &system->r2, &system->v2);
	vector_mul(&f, &f, system->m2);
	vector_add(&i, &i, &f);
	vector_cross(&f, &system->r3, &system->v3);
	vector_mul(&f, &f, system->m3);
	vector_add(&i, &i, &f);
	return i;
}

double	mechanical_energy(t_system *system)
{
	double	e = 0;

	e += system->m1 * vector_dot(&system->v1, &system->v1);
	e += system->m2 * vector_dot(&system->v2, &system->v2);
	e += system->m3 * vector_dot(&system->v3, &system->v3);
	e /= 2;
	e += system->m1 * potential(system->m2, &system->r1, &system->r2);
	e += system->m1 * potential(system->m3, &system->r1, &system->r3);
	e += system->m2 * potential(system->m1, &system->r2, &system->r1);
	e += system->m2 * potential(system->m3, &system->r2, &system->r3);
	e += system->m3 * potential(system->m2, &system->r3, &system->r2);
	e += system->m3 * potential(system->m1, &system->r3, &system->r1);
	return e;
}
