#include <stdlib.h>
#include "libgl.h"

t_group	*gl_alloc_group(t_vec3 origin)
{
	t_group	*group;

	group = (t_group *)malloc(sizeof(t_group));
	if (!group)
		return (NULL);
	*group = gl_create_group(origin);
	return (group);
}
