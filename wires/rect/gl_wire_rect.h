#ifndef GL_WIRE_RECT_H
# define GL_WIRE_RECT_H

# include <stdbool.h>
# include "params/object_type/gl_object_type.h"
# include "params/vector/gl_vector.h"
# include "params/color/gl_color.h"
# include "params/transform/gl_transform.h"

typedef struct s_wire_rect
{
	t_object_type	type;
	char			label[32];
	t_vec3		origin;
	t_vec3		size;
	t_color		color;
	t_transform	transform;
}	t_wire_rect;

t_wire_rect	gl_new_wire_rect(t_vec3 origin, t_vec3 size);
t_wire_rect	gl_new_wire_rect_with_label(t_vec3 origin, t_vec3 size,
				const char *label);
t_wire_rect	*gl_alloc_wire_rect(t_vec3 origin, t_vec3 size);
t_wire_rect	*gl_alloc_wire_rect_with_label(t_vec3 origin, t_vec3 size,
				const char *label);
void		gl_free_wire_rect(t_wire_rect *rect);
bool		gl_label_wire_rect(t_wire_rect *rect, const char *label);
void		gl_color_wire_rect(t_wire_rect *rect, t_color color);
void		gl_draw_wire_rect(t_wire_rect *rect);

#endif
