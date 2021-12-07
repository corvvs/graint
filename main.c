#include "graint.h"

void	run(t_system *system, t_system_expander expander, t_system_printer printer)
{
	size_t	i = 0;

	while (i < system->n)
	{
		expander(system);
		printer(system, i);
		i += 1;
	}
}

int main()
{
	t_system	system = {
		.dt = 0.00001,
		.n = 10000000000ull,
		.m1 = 1,
		.r1 = { 0.0, 0, 0},
		.v1 = { 0, 0.1, 0},
		.m2 = 0.02,
		.r2 = { 10, 0, 0},
		.v2 = { 0, 0.2, 0},
		.m3 = 0.0002,
		.r3 = { 11, 0, 0},
		.v3 = { 0, 0.24, 0},
	};
	run(&system, expand_leap_frog, print_centroid);
}
