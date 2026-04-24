#include <stdlib.h>
#include "libgl.h"

t_line	*gl_alloc_line(t_vec3 start, t_vec3 end)
{
	t_line	*line;

	line = (t_line *)malloc(sizeof(t_line));
	if (!line)
		return (NULL);
	*line = gl_create_line(start, end);
	return (line);
}
