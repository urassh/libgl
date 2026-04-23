#ifndef GL_RECT_H
# define GL_RECT_H

# include <stdbool.h>
# include "params/vector/gl_vector.h"
# include "params/color/gl_color.h"
# include "params/transform/gl_transform.h"

typedef struct s_rect
{
	t_vec3		origin;
	t_vec3		size;
	t_color		color;
	bool		has_outline;
	t_color		outline_color;
	t_transform	transform;
}	t_rect;

t_rect	gl_create_rect(t_vec3 origin, t_vec3 size);
void	gl_color_rect(t_rect *rect, t_color color);
void	gl_outline_rect(t_rect *rect, t_color color);
void	gl_draw_rect(t_rect *rect);

#endif
