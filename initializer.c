#include "graint.h"

void	initsystem_curing_tape(t_system *system)
{
	*system = (t_system){ // 養テ
		.dt = 0.001,
		.n = 100000000ull,
		.i = 0,
		.output_period = 1000,
		.m1 = 1.98892e30,
		.r1 = {0, 0, 0},
		.v1 = {0, 0, 0},
		.m2 = 5.972e24,
		.r2 = {1.5e8, 0, 0},
		.v2 = {0, 2.566080e6, 0},
		.m3 = 5.0e23,
		.r3 = {1.5421e8, 0, 0},
		.v3 = {0, 5.60e5, 0},
	};
}

void	initsystem_quasi_sattelite(t_system *system)
{
	*system = (t_system){
		.dt = 0.001,
		.n = 100000000ull,
		.i = 0,
		.output_period = 10000,
		.m1 = 1.98892e30,
		.r1 = {0, 0, 0},
		.v1 = {0, 0, 0},
		.m2 = 5.972e24,
		.r2 = {1.5e8, 0, 0},
		.v2 = {0, 2.566080e6, 0},
		.m3 = 1.2e24,
		.r3 = {1.54e8, 0, 0},
		.v3 = {0, 2.490768e6, 0},
	};
}

void	initsystem_kidney_bean(t_system *system)
{
	*system = (t_system){
		.dt = 0.001,
		.n = 100000000ull,
		.i = 0,
		.output_period = 10000,
		.m1 = 1.98892e30,
		.r1 = {0, 0, 0},
		.v1 = {0, 0, 0},
		.m2 = 5.972e24,
		.r2 = {1.5e8, 0, 0},
		.v2 = {0, 2.566080e6, 0},
		.m3 = 1.3e14,
		.r3 = {1.589e8, 0, 0},
		.v3 = {0, 1.380768e6, 0},
	};
}