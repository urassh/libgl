#ifndef GL_CYLINDER_H
# define GL_CYLINDER_H

# include <stdbool.h>
# include "params/vector/gl_vector.h"
# include "params/color/gl_color.h"
# include "params/transform/gl_transform.h"

typedef struct s_cylinder
{
	t_vec3		origin;
	float		radius;
	float		height;
	int			slices;
	t_color		color;
	bool		has_outline;
	t_color		outline_color;
	t_transform	transform;
}	t_cylinder;

t_cylinder	gl_create_cylinder(t_vec3 origin, float radius, float height,
				int slices);
t_cylinder	*gl_alloc_cylinder(t_vec3 origin, float radius, float height,
				int slices);
void		gl_free_cylinder(t_cylinder *cyl);
void		gl_color_cylinder(t_cylinder *cyl, t_color color);
void		gl_outline_cylinder(t_cylinder *cyl, t_color color);
void		gl_draw_cylinder(t_cylinder *cyl);

#endif
