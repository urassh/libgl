#ifndef GL_WIRE_CONE_H
# define GL_WIRE_CONE_H

# include <stdbool.h>
# include "params/object_type/gl_object_type.h"
# include "params/vector/gl_vector.h"
# include "params/color/gl_color.h"
# include "params/transform/gl_transform.h"

typedef struct s_wire_cone
{
	t_object_type	type;
	char			label[32];
	t_vec3		origin;
	float		radius;
	float		height;
	int			slices;
	int			stacks;
	t_color		color;
	t_transform	transform;
}	t_wire_cone;

t_wire_cone	gl_new_wire_cone(t_vec3 origin, float radius, float height);
t_wire_cone	gl_new_wire_cone_with_label(t_vec3 origin, float radius,
				float height, const char *label);
t_wire_cone	*gl_alloc_wire_cone(t_vec3 origin, float radius, float height);
t_wire_cone	*gl_alloc_wire_cone_with_label(t_vec3 origin, float radius,
				float height, const char *label);
void		gl_free_wire_cone(t_wire_cone *cone);
bool		gl_label_wire_cone(t_wire_cone *cone, const char *label);
void		gl_color_wire_cone(t_wire_cone *cone, t_color color);
void		gl_slices_wire_cone(t_wire_cone *cone, int slices);
void		gl_stacks_wire_cone(t_wire_cone *cone, int stacks);
void		gl_draw_wire_cone(t_wire_cone *cone);

#endif
