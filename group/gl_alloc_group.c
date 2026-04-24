#include <stdlib.h>
#include <string.h>
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

t_group	*gl_alloc_group_with_label(t_vec3 origin, const char *label)
{
	t_group	*group;

	group = gl_alloc_group(origin);
	if (!group)
		return (NULL);
	strlcpy(group->label, label, GL_LABEL_MAX);
	return (group);
}
