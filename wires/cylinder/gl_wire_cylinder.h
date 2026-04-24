#ifndef GL_WIRE_CYLINDER_H
# define GL_WIRE_CYLINDER_H

# include <stdbool.h>
# include "params/vector/gl_vector.h"
# include "params/color/gl_color.h"
# include "params/transform/gl_transform.h"

typedef struct s_wire_cylinder
{
	char		label[32];
	t_vec3		origin;
	float		radius;
	float		height;
	int			slices;
	t_color		color;
	t_transform	transform;
}	t_wire_cylinder;

t_wire_cylinder	gl_create_wire_cylinder(t_vec3 origin, float radius,
					float height);
t_wire_cylinder	gl_create_wire_cylinder_with_label(t_vec3 origin, float radius,
					float height, const char *label);
t_wire_cylinder	*gl_alloc_wire_cylinder(t_vec3 origin, float radius,
					float height);
t_wire_cylinder	*gl_alloc_wire_cylinder_with_label(t_vec3 origin, float radius,
					float height, const char *label);
void			gl_free_wire_cylinder(t_wire_cylinder *cyl);
bool			gl_label_wire_cylinder(t_wire_cylinder *cyl, const char *label);
void			gl_color_wire_cylinder(t_wire_cylinder *cyl, t_color color);
void			gl_slices_wire_cylinder(t_wire_cylinder *cyl, int slices);
void			gl_draw_wire_cylinder(t_wire_cylinder *cyl);

#endif
