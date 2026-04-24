#include <string.h>
#include "libgl.h"

t_line	gl_new_line(t_vec3 start, t_vec3 end)
{
	t_line	line;

	line.type = GL_TYPE_LINE;
	strlcpy(line.label, "line", GL_LABEL_MAX);
	line.start = start;
	line.end = end;
	line.color = gl_black();
	line.transform.rotation = gl_vec3(0, 0, 0);
	line.transform.offset = gl_vec3(0, 0, 0);
	line.transform.scale = gl_vec3(1, 1, 1);
	return (line);
}

t_line	gl_new_line_with_label(t_vec3 start, t_vec3 end,
			const char *label)
{
	t_line	line;

	line = gl_new_line(start, end);
	if (strlen(label) < GL_LABEL_MAX)
		strlcpy(line.label, label, GL_LABEL_MAX);
	return (line);
}
