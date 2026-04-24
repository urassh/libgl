#include <string.h>
#include "libgl.h"

t_2d_line	gl_new_2d_line(t_vec2 start, t_vec2 end)
{
	t_2d_line	line;

	line.type = GL_TYPE_2D_LINE;
	strlcpy(line.label, "2d_line", GL_LABEL_MAX);
	line.start = start;
	line.end = end;
	line.color = gl_black();
	line.transform.rotation = 0;
	line.transform.offset = gl_vec2(0, 0);
	line.transform.scale = gl_vec2(1, 1);
	return (line);
}

t_2d_line	gl_new_2d_line_with_label(t_vec2 start, t_vec2 end,
				const char *label)
{
	t_2d_line	line;

	line = gl_new_2d_line(start, end);
	if (strlen(label) < GL_LABEL_MAX)
		strlcpy(line.label, label, GL_LABEL_MAX);
	return (line);
}
