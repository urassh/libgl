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
	char		label[32];
}	t_rect;

t_rect	gl_create_rect(t_vec3 origin, t_vec3 size);
t_rect	gl_create_rect_with_label(t_vec3 origin, t_vec3 size,
			const char *label);
t_rect	*gl_alloc_rect(t_vec3 origin, t_vec3 size);
t_rect	*gl_alloc_rect_with_label(t_vec3 origin, t_vec3 size,
			const char *label);
void	gl_free_rect(t_rect *rect);
bool	gl_label_rect(t_rect *rect, const char *label);
void	gl_color_rect(t_rect *rect, t_color color);
void	gl_outline_rect(t_rect *rect, t_color color);
void	gl_draw_rect(t_rect *rect);

#endif
