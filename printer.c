#include "graint.h"

void	print_system(t_system *system, size_t i)
{
	if (i % 10000 != 0)
		return ;
	printf("%.10f %.10f %.10f %.10f %.10f %.10f %.10f %.10f %.10f\n",
		system->r1.x - system->r1.x, system->r1.y - system->r1.y, system->r1.z - system->r1.z,
		system->r2.x - system->r1.x, system->r2.y - system->r1.y, system->r2.z - system->r1.z,
		system->r3.x - system->r1.x, system->r3.y - system->r1.y, system->r3.z - system->r1.z
	);
}


void	print_centroid(t_system *system, size_t i)
{
	if (i % 10000 != 0)
		return ;
	t_vector3 centroid = {0};
	t_vector3 temp;
	vector_mul(&temp, &system->r1, system->m1);
	vector_add(&centroid, &centroid, &temp);
	vector_mul(&temp, &system->r2, system->m2);
	vector_add(&centroid, &centroid, &temp);
	vector_mul(&temp, &system->r3, system->m3);
	vector_add(&centroid, &centroid, &temp);
	vector_mul(&centroid, &centroid, 1 / (system->m1 + system->m2 + system->m3));
	printf("%.10f %.10f %.10f %.10f %.10f %.10f %.10f %.10f %.10f\n",
		system->r1.x - centroid.x, system->r1.y - centroid.y, system->r1.z - centroid.z,
		system->r2.x - centroid.x, system->r2.y - centroid.y, system->r2.z - centroid.z,
		system->r3.x - centroid.x, system->r3.y - centroid.y, system->r3.z - centroid.z
	);
}
