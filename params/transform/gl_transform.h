#ifndef GL_TRANSFORM_H
# define GL_TRANSFORM_H

# include "params/vector/gl_vector.h"

typedef struct s_transform
{
	t_vec3	rotation;
	t_vec3	offset;
	t_vec3	scale;
}	t_transform;

void	gl_rotate(t_transform *tf, t_vec3 angle);
void	gl_translate(t_transform *tf, t_vec3 offset);
void	gl_scale(t_transform *tf, t_vec3 scale);

typedef struct s_2d_transform
{
	float	rotation;
	t_vec2	offset;
	t_vec2	scale;
}	t_2d_transform;

void	gl_2d_rotate(t_2d_transform *tf, float angle);
void	gl_2d_translate(t_2d_transform *tf, t_vec2 offset);
void	gl_2d_scale(t_2d_transform *tf, t_vec2 scale);

#endif
