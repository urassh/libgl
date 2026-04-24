#ifndef GL_WIRE_CUBE_H
# define GL_WIRE_CUBE_H

# include "params/vector/gl_vector.h"
# include "params/color/gl_color.h"
# include "params/transform/gl_transform.h"

typedef struct s_wire_cube
{
	t_vec3		origin;
	t_vec3		size;
	t_color		color;
	t_transform	transform;
}	t_wire_cube;

t_wire_cube	gl_create_wire_cube(t_vec3 origin, t_vec3 size);
t_wire_cube	*gl_alloc_wire_cube(t_vec3 origin, t_vec3 size);
void		gl_free_wire_cube(t_wire_cube *cube);
void		gl_color_wire_cube(t_wire_cube *cube, t_color color);
void		gl_draw_wire_cube(t_wire_cube *cube);

#endif
