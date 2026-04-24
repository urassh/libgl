#include <stdlib.h>
#include <string.h>
#include "libgl.h"

t_rect	*gl_alloc_rect(t_vec3 origin, t_vec3 size)
{
	t_rect	*rect;

	rect = (t_rect *)malloc(sizeof(t_rect));
	if (!rect)
		return (NULL);
	*rect = gl_new_rect(origin, size);
	return (rect);
}

t_rect	*gl_alloc_rect_with_label(t_vec3 origin, t_vec3 size,
			const char *label)
{
	t_rect	*rect;

	rect = gl_alloc_rect(origin, size);
	if (!rect)
		return (NULL);
	if (strlen(label) < GL_LABEL_MAX)
		strlcpy(rect->label, label, GL_LABEL_MAX);
	return (rect);
}
