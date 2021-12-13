#include "graint.h"

void	run(t_system *system, t_system_expander expand_time, t_system_printer print)
{
	size_t	i = 0;

	while (i < system->n)
	{
		expand_time(system);
		print(system, i);
		i += 1;
	}
}

void	print_profile(t_system *system)
{
	printf("# times:            %zu\n", system->n);
	printf("# dt:               %1.8f\n", system->dt);
	printf("# [particle 1]\n");
	printf("# mass:             %1.8f\n", system->m1);
	printf("# initial position: (%1.8f, %1.8f, %1.8f)\n", system->r1.x, system->r1.y, system->r1.z);
	printf("# initial velocity: (%1.8f, %1.8f, %1.8f)\n", system->v1.x, system->v1.y, system->v1.z);
	printf("# [particle 2]\n");
	printf("# mass:             %1.8f\n", system->m2);
	printf("# initial position: (%1.8f, %1.8f, %1.8f)\n", system->r2.x, system->r2.y, system->r2.z);
	printf("# initial velocity: (%1.8f, %1.8f, %1.8f)\n", system->v2.x, system->v2.y, system->v2.z);
	printf("# [particle 3]\n");
	printf("# mass:             %1.8f\n", system->m3);
	printf("# initial position: (%1.8f, %1.8f, %1.8f)\n", system->r3.x, system->r3.y, system->r3.z);
	printf("# initial velocity: (%1.8f, %1.8f, %1.8f)\n", system->v3.x, system->v3.y, system->v3.z);
	printf("\n");
}

int main()
{
	t_system	system = { // kidney-bean
		.dt = 0.001,
		.n = 100000000ull,
		.m1 = 1.98892e30,
		.r1 = {0, 0, 0},
		.v1 = {0, 0, 0},
		.m2 = 5.972e24,
		.r2 = {1.5e8, 0, 0},
		.v2 = {0, 2.566080e6, 0},
		.m3 = 1.2e24,
		// .m3 = 1.3e14,
		.r3 = {1.54e8, 0, 0},
		// .v3 = {0, 2.414768e6, 0}, // stable
		.v3 = {0, 2.490768e6, 0},
	};
	// t_system	system = { // kidney-bean
	// 	.dt = 0.001,
	// 	.n = 100000000ull,
	// 	.m1 = 1.98892e30,
	// 	.r1 = {0, 0, 0},
	// 	.v1 = {0, 0, 0},
	// 	.m2 = 5.972e24,
	// 	.r2 = {1.5e8, 0, 0},
	// 	.v2 = {0, 2.566080e6, 0},
	// 	.m3 = 1.3e14,
	// 	.r3 = {1.589e8, 0, 0},
	// 	.v3 = {0, 1.380768e6, 0},
	// };
	print_profile(&system);
	run(&system, expand_leap_frog, print_system);
}
