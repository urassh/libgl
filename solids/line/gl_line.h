#ifndef GL_LINE_H
# define GL_LINE_H

# include "params/vector/gl_vector.h"
# include "params/color/gl_color.h"
# include "params/transform/gl_transform.h"

typedef struct s_line
{
	t_vec3		start;
	t_vec3		end;
	t_color		color;
	t_transform	transform;
}	t_line;

t_line	gl_create_line(t_vec3 start, t_vec3 end);
void	gl_color_line(t_line *line, t_color color);
void	gl_draw_line(t_line *line);

#endif
