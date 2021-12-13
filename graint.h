#ifndef GRAINT_H
# define GRAINT_H

# include <unistd.h>
# include <stdio.h>
# include <math.h>

//# define G 6.67408e-11 // [m^3kg^-1s^-2]
# define G 4.98217402e-10 // [km^3kg^-1day^-2]

typedef struct s_vector3
{
	double	x;
	double	y;
	double	z;
}	t_vector3;

typedef struct s_system
{
	// time_delta
	double			dt;
	// times
	size_t			n;
	// masses
	double			m1;
	double			m2;
	double			m3;
	// positions
	t_vector3		r1;
	t_vector3		r2;
	t_vector3		r3;
	// velocities
	t_vector3		v1;
	t_vector3		v2;
	t_vector3		v3;
}	t_system;

double		vector_norm(t_vector3 *v);
void		vector_add(t_vector3 *ans, t_vector3 *r1, t_vector3 *r2);
void		vector_sub(t_vector3 *ans, t_vector3 *r1, t_vector3 *r2);
void		vector_mul(t_vector3 *ans, t_vector3 *r1, double d);
void		vector_cross(t_vector3 *ans, t_vector3 *r1, t_vector3 *r2);
double		vector_dot(t_vector3 *r1, t_vector3 *r2);

void		initsystem_curing_tape(t_system *system);
void		initsystem_quasi_sattelite(t_system *system);
void		initsystem_kidney_bean(t_system *system);
typedef		void (t_system_initializer)(t_system*);


double		potential(double m, t_vector3 *r_me, t_vector3 *r_you);
t_vector3	force(double m, t_vector3 *r_me, t_vector3 *r_you);

void		expand_euler(t_system *system);
void		expand_leap_frog(t_system *system);
typedef		void (t_system_expander)(t_system*);

t_vector3	angular_momentum(t_system *system);
double		mechanical_energy(t_system *system);

void		print_system(t_system *system);
void		print_centroid(t_system *system);
void		print_12(t_system *system);
void		print_nop(t_system *system);
typedef		void (t_system_printer)(t_system*);

#endif