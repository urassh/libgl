#include <stdlib.h>
#include <string.h>
#include "libgl.h"

t_2d_rect	*gl_alloc_2d_rect(t_vec2 origin, t_vec2 size)
{
	t_2d_rect	*rect;

	rect = (t_2d_rect *)malloc(sizeof(t_2d_rect));
	if (!rect)
		return (NULL);
	*rect = gl_new_2d_rect(origin, size);
	return (rect);
}

t_2d_rect	*gl_alloc_2d_rect_with_label(t_vec2 origin, t_vec2 size,
				const char *label)
{
	t_2d_rect	*rect;

	rect = gl_alloc_2d_rect(origin, size);
	if (!rect)
		return (NULL);
	if (strlen(label) < GL_LABEL_MAX)
		strlcpy(rect->label, label, GL_LABEL_MAX);
	return (rect);
}
