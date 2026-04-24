#include <stdlib.h>
#include <string.h>
#include "libgl.h"

t_2d_line	*gl_alloc_2d_line(t_vec2 start, t_vec2 end)
{
	t_2d_line	*line;

	line = (t_2d_line *)malloc(sizeof(t_2d_line));
	if (!line)
		return (NULL);
	*line = gl_new_2d_line(start, end);
	return (line);
}

t_2d_line	*gl_alloc_2d_line_with_label(t_vec2 start, t_vec2 end,
				const char *label)
{
	t_2d_line	*line;

	line = gl_alloc_2d_line(start, end);
	if (!line)
		return (NULL);
	if (strlen(label) < GL_LABEL_MAX)
		strlcpy(line->label, label, GL_LABEL_MAX);
	return (line);
}
