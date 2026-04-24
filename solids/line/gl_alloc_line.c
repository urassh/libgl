#include <stdlib.h>
#include <string.h>
#include "libgl.h"

t_line	*gl_alloc_line(t_vec3 start, t_vec3 end)
{
	t_line	*line;

	line = (t_line *)malloc(sizeof(t_line));
	if (!line)
		return (NULL);
	*line = gl_new_line(start, end);
	return (line);
}

t_line	*gl_alloc_line_with_label(t_vec3 start, t_vec3 end,
			const char *label)
{
	t_line	*line;

	line = gl_alloc_line(start, end);
	if (!line)
		return (NULL);
	if (strlen(label) < GL_LABEL_MAX)
		strlcpy(line->label, label, GL_LABEL_MAX);
	return (line);
}
