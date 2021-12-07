#ifndef GRAINT_H
# define GRAINT_H

# include <unistd.h>
# include <stdio.h>
# include <math.h>

# define G 0.132777734
// G in [Re^3 Me^-1 d^-2]

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

t_vector3	force(double m, t_vector3 *r_me, t_vector3 *r_you);

void		expand_euler(t_system *system);
void		expand_leap_frog(t_system *system);

typedef	void (t_system_expander)(t_system*);

void		print_system(t_system *system, size_t i);
void		print_centroid(t_system *system, size_t i);

typedef	void (t_system_printer)(t_system*, size_t);

#endif