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

#endif
