#ifndef GL_WIRE_CYLINDER_H
# define GL_WIRE_CYLINDER_H

# include "params/vector/gl_vector.h"
# include "params/color/gl_color.h"
# include "params/transform/gl_transform.h"

typedef struct s_wire_cylinder
{
	t_vec3		origin;
	float		radius;
	float		height;
	int			slices;
	t_color		color;
	t_transform	transform;
}	t_wire_cylinder;

t_wire_cylinder	gl_create_wire_cylinder(t_vec3 origin, float radius,
					float height);
t_wire_cylinder	*gl_alloc_wire_cylinder(t_vec3 origin, float radius,
					float height);
void			gl_free_wire_cylinder(t_wire_cylinder *cyl);
void			gl_color_wire_cylinder(t_wire_cylinder *cyl, t_color color);
void			gl_slices_wire_cylinder(t_wire_cylinder *cyl, int slices);
void			gl_draw_wire_cylinder(t_wire_cylinder *cyl);

#endif
