#include "graint.h"

// リープフロッグ法による時間発展
void	expand_leap_frog(t_system *system)
{
	t_vector3	f;
	t_vector3	f1 = accel(system->m2, &system->r1, &system->r2);
	t_vector3	f2 = accel(system->m3, &system->r2, &system->r3);
	t_vector3	f3 = accel(system->m1, &system->r3, &system->r1);
	f = accel(system->m3, &system->r1, &system->r3);
	vector_add(&f1, &f1, &f);
	f = accel(system->m1, &system->r2, &system->r1);
	vector_add(&f2, &f2, &f);
	f = accel(system->m2, &system->r3, &system->r2);
	vector_add(&f3, &f3, &f);

	t_vector3	v;
	// 1
	v = system->v1;
	vector_mul(&v, &v, system->dt); // v = v * dt
	vector_add(&system->r1, &system->r1, &v);
	vector_mul(&v, &f1, system->dt * system->dt / 2);
	vector_add(&system->r1, &system->r1, &v);
	// 2
	v = system->v2;
	vector_mul(&v, &v, system->dt);
	vector_add(&system->r2, &system->r2, &v);
	vector_mul(&v, &f2, system->dt * system->dt / 2);
	vector_add(&system->r2, &system->r2, &v);
	// 3
	v = system->v3;
	vector_mul(&v, &v, system->dt);
	vector_add(&system->r3, &system->r3, &v);
	vector_mul(&v, &f3, system->dt * system->dt / 2);
	vector_add(&system->r3, &system->r3, &v);

	t_vector3	f11 = accel(system->m2, &system->r1, &system->r2);
	t_vector3	f12 = accel(system->m3, &system->r2, &system->r3);
	t_vector3	f13 = accel(system->m1, &system->r3, &system->r1);
	f = accel(system->m3, &system->r1, &system->r3);
	vector_add(&f11, &f11, &f);
	vector_add(&f1, &f11, &f1);
	f = accel(system->m1, &system->r2, &system->r1);
	vector_add(&f12, &f12, &f);
	vector_add(&f2, &f12, &f2);
	f = accel(system->m2, &system->r3, &system->r2);
	vector_add(&f13, &f13, &f);
	vector_add(&f3, &f13, &f3);
	vector_mul(&v, &f1, system->dt / 2);
	vector_add(&system->v1, &system->v1, &v);
	vector_mul(&v, &f2, system->dt / 2);
	vector_add(&system->v2, &system->v2, &v);
	vector_mul(&v, &f3, system->dt / 2);
	vector_add(&system->v3, &system->v3, &v);
}
