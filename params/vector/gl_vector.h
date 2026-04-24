#ifndef GL_VECTOR_H
# define GL_VECTOR_H

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

t_vec3	gl_vec3(float x, float y, float z);

typedef struct s_vec2
{
	float	x;
	float	y;
}	t_vec2;

t_vec2	gl_vec2(float x, float y);

#endif
