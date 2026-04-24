#ifndef GL_WIRE_CUBE_H
# define GL_WIRE_CUBE_H

# include <stdbool.h>
# include "params/vector/gl_vector.h"
# include "params/color/gl_color.h"
# include "params/transform/gl_transform.h"

typedef struct s_wire_cube
{
	t_vec3		origin;
	t_vec3		size;
	t_color		color;
	t_transform	transform;
	char		label[32];
}	t_wire_cube;

t_wire_cube	gl_create_wire_cube(t_vec3 origin, t_vec3 size);
t_wire_cube	gl_create_wire_cube_with_label(t_vec3 origin, t_vec3 size,
				const char *label);
t_wire_cube	*gl_alloc_wire_cube(t_vec3 origin, t_vec3 size);
t_wire_cube	*gl_alloc_wire_cube_with_label(t_vec3 origin, t_vec3 size,
				const char *label);
void		gl_free_wire_cube(t_wire_cube *cube);
bool		gl_label_wire_cube(t_wire_cube *cube, const char *label);
void		gl_color_wire_cube(t_wire_cube *cube, t_color color);
void		gl_draw_wire_cube(t_wire_cube *cube);

#endif
