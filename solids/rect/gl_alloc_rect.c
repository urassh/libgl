#include <stdlib.h>
#include "libgl.h"

t_rect	*gl_alloc_rect(t_vec3 origin, t_vec3 size)
{
	t_rect	*rect;

	rect = (t_rect *)malloc(sizeof(t_rect));
	if (!rect)
		return (NULL);
	*rect = gl_create_rect(origin, size);
	return (rect);
}
