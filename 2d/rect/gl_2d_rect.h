#ifndef GL_2D_RECT_H
# define GL_2D_RECT_H

# include <stdbool.h>
# include "params/object_type/gl_object_type.h"
# include "params/vector/gl_vector.h"
# include "params/color/gl_color.h"
# include "params/transform/gl_transform.h"

typedef struct s_2d_rect
{
	t_object_type	type;
	char			label[32];
	t_vec2			origin;
	t_vec2			size;
	t_color			color;
	bool			has_outline;
	t_color			outline_color;
	t_2d_transform	transform;
}	t_2d_rect;

t_2d_rect	gl_new_2d_rect(t_vec2 origin, t_vec2 size);
t_2d_rect	gl_new_2d_rect_with_label(t_vec2 origin, t_vec2 size,
				const char *label);
t_2d_rect	*gl_alloc_2d_rect(t_vec2 origin, t_vec2 size);
t_2d_rect	*gl_alloc_2d_rect_with_label(t_vec2 origin, t_vec2 size,
				const char *label);
void		gl_free_2d_rect(t_2d_rect *rect);
bool		gl_label_2d_rect(t_2d_rect *rect, const char *label);
void		gl_color_2d_rect(t_2d_rect *rect, t_color color);
void		gl_outline_2d_rect(t_2d_rect *rect, t_color color);
void		gl_draw_2d_rect(t_2d_rect *rect);

#endif
