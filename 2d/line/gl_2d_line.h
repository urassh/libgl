#ifndef GL_2D_LINE_H
# define GL_2D_LINE_H

# include <stdbool.h>
# include "params/object_type/gl_object_type.h"
# include "params/vector/gl_vector.h"
# include "params/color/gl_color.h"
# include "params/transform/gl_transform.h"

typedef struct s_2d_line
{
	t_object_type	type;
	char			label[32];
	t_vec2			start;
	t_vec2			end;
	t_color			color;
	t_2d_transform	transform;
}	t_2d_line;

t_2d_line	gl_new_2d_line(t_vec2 start, t_vec2 end);
t_2d_line	gl_new_2d_line_with_label(t_vec2 start, t_vec2 end,
				const char *label);
t_2d_line	*gl_alloc_2d_line(t_vec2 start, t_vec2 end);
t_2d_line	*gl_alloc_2d_line_with_label(t_vec2 start, t_vec2 end,
				const char *label);
void		gl_free_2d_line(t_2d_line *line);
bool		gl_label_2d_line(t_2d_line *line, const char *label);
void		gl_color_2d_line(t_2d_line *line, t_color color);
void		gl_draw_2d_line(t_2d_line *line);

#endif
