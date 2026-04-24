#include <string.h>
#include "libgl.h"

t_group	gl_create_group(t_vec3 origin)
{
	t_group	group;
	int		i;

	group.origin = origin;
	group.transform.rotation = gl_vec3(0, 0, 0);
	group.transform.offset = gl_vec3(0, 0, 0);
	group.transform.scale = gl_vec3(1, 1, 1);
	group.count = 0;
	i = 0;
	while (i < GROUP_MAX_CHILDREN)
	{
		group.children[i].object = NULL;
		group.children[i].draw = NULL;
		i++;
	}
	strlcpy(group.label, "group", GL_LABEL_MAX);
	return (group);
}

t_group	gl_create_group_with_label(t_vec3 origin, const char *label)
{
	t_group	group;

	group = gl_create_group(origin);
	strlcpy(group.label, label, GL_LABEL_MAX);
	return (group);
}
