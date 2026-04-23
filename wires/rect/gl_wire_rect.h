#ifndef GL_WIRE_RECT_H
# define GL_WIRE_RECT_H

# include "params/vector/gl_vector.h"
# include "params/color/gl_color.h"
# include "params/transform/gl_transform.h"

typedef struct s_wire_rect
{
	t_vec3		origin;
	t_vec3		size;
	t_color		color;
	t_transform	transform;
}	t_wire_rect;

t_wire_rect	gl_create_wire_rect(t_vec3 origin, t_vec3 size);
void		gl_color_wire_rect(t_wire_rect *rect, t_color color);
void		gl_draw_wire_rect(t_wire_rect *rect);

#endif
