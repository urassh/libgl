#ifndef GL_LINE_H
# define GL_LINE_H

# include <stdbool.h>
# include "params/vector/gl_vector.h"
# include "params/color/gl_color.h"
# include "params/transform/gl_transform.h"

typedef struct s_line
{
	t_vec3		start;
	t_vec3		end;
	t_color		color;
	t_transform	transform;
	char		label[32];
}	t_line;

t_line	gl_create_line(t_vec3 start, t_vec3 end);
t_line	gl_create_line_with_label(t_vec3 start, t_vec3 end,
			const char *label);
t_line	*gl_alloc_line(t_vec3 start, t_vec3 end);
t_line	*gl_alloc_line_with_label(t_vec3 start, t_vec3 end,
			const char *label);
void	gl_free_line(t_line *line);
bool	gl_label_line(t_line *line, const char *label);
void	gl_color_line(t_line *line, t_color color);
void	gl_draw_line(t_line *line);

#endif
