#ifndef GRAINT_H
# define GRAINT_H

# include <unistd.h>
# include <stdio.h>
# include <math.h>

// 万有引力定数
# define G 4.98217402e-10 // [km^3kg^-1day^-2]
//# define G 6.67408e-11 // [m^3kg^-1s^-2]

typedef struct s_vector3
{
	double	x;
	double	y;
	double	z;
}	t_vector3;

// 物理系 + 出力設定
typedef struct s_system
{
	// 時間刻み
	double			dt;
	// シミュレーション回数
	size_t			n;
	// 現在のシミュレーション回数
	size_t			i;
	// 出力頻度
	size_t			output_period;
	// 物体1の質量
	double			m1;
	// 物体2の質量
	double			m2;
	// 物体3の質量
	double			m3;
	// 物体1の位置ベクトル
	t_vector3		r1;
	// 物体2の位置ベクトル
	t_vector3		r2;
	// 物体3の位置ベクトル
	t_vector3		r3;
	// 物体1の速度ベクトル
	t_vector3		v1;
	// 物体2の速度ベクトル
	t_vector3		v2;
	// 物体3の速度ベクトル
	t_vector3		v3;
}	t_system;

double		vector_norm(t_vector3 *v);
void		vector_add(t_vector3 *ans, t_vector3 *r1, t_vector3 *r2);
void		vector_sub(t_vector3 *ans, t_vector3 *r1, t_vector3 *r2);
void		vector_mul(t_vector3 *ans, t_vector3 *r1, double d);
void		vector_cross(t_vector3 *ans, t_vector3 *r1, t_vector3 *r2);
double		vector_dot(t_vector3 *r1, t_vector3 *r2);

// 系の初期化関数
typedef		void (t_system_initializer)(t_system*);
void		initsystem(t_system *system);
void		initsystem_horseshoe(t_system *system);
void		initsystem_curing_tape(t_system *system);
void		initsystem_quasi_sattelite(t_system *system);
void		initsystem_kidney_bean(t_system *system);


double		potential(double m, t_vector3 *r_me, t_vector3 *r_you);
t_vector3	force(double m, t_vector3 *r_me, t_vector3 *r_you);

// 系の時間発展関数
typedef		void (t_system_expander)(t_system*);
void		expand_euler(t_system *system);
void		expand_leap_frog(t_system *system);

t_vector3	angular_momentum(t_system *system);
double		mechanical_energy(t_system *system);

// 系の出力関数
void		print_system(t_system *system);
void		print_centroid(t_system *system);
void		print_12(t_system *system);
void		print_nop(t_system *system);
typedef		void (t_system_printer)(t_system*);

#endif