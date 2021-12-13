#include "graint.h"
#define FMT "%.10e"
#define FMT2 FMT " " FMT
#define FMT6 FMT2 " " FMT2 " " FMT2
#define FMT3 FMT " " FMT " " FMT

// 位置を出力する
void	print_system(t_system *system)
{
	if (system->i % system->output_period != 0)
		return ;
	printf(FMT6 "\n",
		system->r1.x, system->r1.y,
		system->r2.x, system->r2.y,
		system->r3.x, system->r3.y
	);
}

// 重心系における位置を出力する
void	print_centroid(t_system *system)
{
	if (system->i % system->output_period != 0)
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
	printf(FMT6 "\n",
		system->r1.x - centroid.x, system->r1.y - centroid.y,
		system->r2.x - centroid.x, system->r2.y - centroid.y,
		system->r3.x - centroid.x, system->r3.y - centroid.y
	);
}

// 物体1を中心とし、物体1から物体2へのベクトルがX軸正方向に一致するように回転する系における位置を出力する
void	print_12(t_system *system)
{
	if (system->i % system->output_period != 0)
		return ;
	double phi = atan2(system->r2.y - system->r1.y, system->r2.x - system->r1.x);
	printf(FMT6 "\n",
		(system->r1.x - system->r1.x) * cos(phi) + (system->r1.y - system->r1.y) * sin(phi), -(system->r1.x - system->r1.x) * sin(phi) + (system->r1.y - system->r1.y) * cos(phi),
		(system->r2.x - system->r1.x) * cos(phi) + (system->r2.y - system->r1.y) * sin(phi), -(system->r2.x - system->r1.x) * sin(phi) + (system->r2.y - system->r1.y) * cos(phi),
		(system->r3.x - system->r1.x) * cos(phi) + (system->r3.y - system->r1.y) * sin(phi), -(system->r3.x - system->r1.x) * sin(phi) + (system->r3.y - system->r1.y) * cos(phi)
	);
}

// 保存量を出力する
// 1: 角運動量(のz成分)
// 2: 力学的エネルギー
void	print_conservative(t_system *system)
{
	t_vector3	l;
	if (system->i % system->output_period != 0)
		return ;
	l = angular_momentum(system);
	printf(FMT3 " " FMT "\n",
		l.x, l.y, l.z, mechanical_energy(system));
}

// 何も出力しない
void	print_nop(t_system *system)
{
	(void)system;
}